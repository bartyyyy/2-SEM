#include <iostream>

int  _cdecl sum(int x, int y, int z) {
	return x + y + z; 
}

int   _stdcall sum1(int &x, int y, int z) {
	return x + y + z; 
}

int   _fastcall sum2(int x, int y, int p1, int p2) {
	return x + y + p1 + p2; 
}

int main() { 
	int rc = sum(1, 2, 3);
	/*int a = 1;
	int rc = sum1(a, 2, 3);*/
	// int rc = sum2(1, 2, 3, 4);

	return 0;
}