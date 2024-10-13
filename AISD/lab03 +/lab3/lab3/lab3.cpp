#include <iostream>
#include <time.h> 

using namespace std;

void qsortRecursive(int* mas, int size);


int main()
{
	int N, size;

	clock_t start[4] = {0,0,0,0};
	clock_t end[4] = {0,0,0,0};
	long double seconds[4] = {0,0,0,0};

	do
	{
		cout << "Введите число N (Количество значений массива): ";
		cin >> N;

		if (N <= 0)
			cout << "Некорректный ввод";
	} while (N < 0);

	size = N;
	int* arrA = new int[size];
	
	for (int i = 0; i < N; i++)
		arrA[i] = rand();

	int* arrB = arrA; 
	int* arrC = arrA; 
	int* arrD = arrA;  
	int* arrE = arrA; 
	cout << "Начальный массив";


	start[0] = clock();

	int temp;
	// Пузырьковая
	for (int i = 0; i < size - 1; i++) {			
		for (int j = 0; j < size - i - 1; j++) {
			if (arrB[j] > arrB[j + 1]) {
				temp = arrB[j];
				arrB[j] = arrB[j + 1];
				arrB[j + 1] = temp;
			}
		}
	}

	end[0] = clock();
	seconds[0] = (long double)(end[0] - start[0]) / CLOCKS_PER_SEC;
	// Сортировка методом Шелла
	start[1] = clock();

	int i, j, step;
	int tmp;

	for (step = size / 2; step > 0; step /= 2)
		for (i = step; i < size; i++)
		{
			tmp = arrC[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < arrC[j - step])
					arrC[j] = arrC[j - step];
				else
					break;
			}
			arrC[j] = tmp;
		}

	end[1] = clock();
	seconds[1] = (long double)(end[1] - start[1]) / CLOCKS_PER_SEC; 
	// Выбором
	start[2] = clock();

	int min, buf;

	for (int i = 0; i < N; i++)
	{
		min = i; 
		for (int j = i + 1; j < N; j++)
			min = (arrD[j] < arrD[min]) ? j : min;
		if (i != min)
		{
			buf = arrD[i];
			arrD[i] = arrD[min];
			arrD[min] = buf;
		}
	}


	end[2] = clock();
	seconds[2] = (long double)(end[2] - start[2]) / CLOCKS_PER_SEC;

	// Быстрая
	start[3] = clock();

	qsortRecursive(arrE, size);

	end[3] = clock();
	seconds[3] = (long double)(end[3] - start[3]) / CLOCKS_PER_SEC;

	cout << "\n\nВремя cортировки пузырьком = " << seconds[0];
	cout << "\n\nВремя сортировки методом Шелла = " << seconds[1];
	cout << "\n\nВремя сортировки выбором = " << seconds[2];
	cout << "\n\nВремя быстрой сортировки = " << seconds[3];

	
	return 0;
}


void qsortRecursive(int* mas, int size) 
{
	int i = 0;
	int j = size - 1;

	
	int mid = mas[size / 2];

	do {
		while (mas[i] < mid) {
			i++;
		}
		while (mas[j] > mid) {
			j--;
		}

		if (i <= j) {
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);


	if (j > 0) {
		qsortRecursive(mas, j + 1);
	}
	if (i < size) {
		qsortRecursive(&mas[i], size - i);
	}
}