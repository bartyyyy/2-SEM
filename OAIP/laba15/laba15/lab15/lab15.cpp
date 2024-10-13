#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Функция для генерации случайного массива
vector<int> generateRandomArray(int size, int minValue = 1, int maxValue = 10000) {
    vector<int> array(size);
    for (int& value : array) {
        value = minValue + rand() % (maxValue - minValue + 1);
    }
    return array;
}

// Функция для нахождения минимального элемента в массиве
int findMinElement(const vector<int>& array) {
    return *min_element(array.begin(), array.end());
}

// Функция пирамидальной сортировки (сортировка кучи)
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Функция для сортировки слиянием
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Функция для измерения времени выполнения сортировок
template <typename Func>
double measureSortTime(Func sortFunc, vector<int>& arr) {
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    return diff.count();
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    vector<int> sizes = { 1000, 2000, 3000, 4000, 5000 };

    for (int size : sizes) {
        vector<int> A = generateRandomArray(size);
        vector<int> B = generateRandomArray(size);

        int minB = findMinElement(B);

        vector<int> C;
        for (int value : A) {
            if (value > minB) {
                C.push_back(value);
            }
        }

        // Сортировка по убыванию с использованием пирамидальной сортировки
        vector<int> CHeap = C;
        double heapSortTime = measureSortTime(heapSort, CHeap);
        cout << "Heap Sort Time for size " << size << ": " << heapSortTime << " seconds\n";

        // Сортировка по убыванию с использованием сортировки слиянием
        vector<int> CMerge = C;
        double mergeSortTime = measureSortTime([&](vector<int>& arr) { mergeSort(arr, 0, arr.size() - 1); }, CMerge);
        cout << "Merge Sort Time for size " << size << ": " << mergeSortTime << " seconds\n";
    }

    return 0;
}
