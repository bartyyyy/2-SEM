#include <iostream>
using namespace std;

int defaultparm(int x1, int x2, int x3, int x4, int x5, int x6 = 6, int x7 = 7) {
	return (x1 + x2 + x3 + x4 + x5 + x6 + x7) / 7;
}

int main() {

	int x1 = defaultparm(1, 2, 3, 4, 5);
	int x2 = defaultparm(1, 2, 3, 4, 5, 6, 7);
	cout << "Результат первого вызова функции: " << x1 << endl;
	cout << "Результат второго вызова функции: " << x2 << endl;
	return 0;
}