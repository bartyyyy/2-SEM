#include <iostream>

using namespace std;

int main()
{


	int N, tmp, step;
	int i, j, k;
	
	do
	{
		cout << "Введите количество товаров: ";
		cin >> N;

		if (N > 10000 || N < 0)
			cout << "Некорректный ввод";
	} while (N > 10000 || N < 0);
	
	int size = N;

	int* productsList = new int[size]; 

	for (i = 0; i < size; i++)
		productsList[i] = (rand() % 100 + 1);


	for (step = size / 2; step > 0; step /= 2)
		for (i = step; i < size; i++)
		{
			tmp = productsList[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < productsList[j - step])
					productsList[j] = productsList[j - step];
				else
					break;
			}
			productsList[j] = tmp;
		}


	int* lowestCost = new int[size / 2];  
	int* highestCost = new int[size / 2];

	for (i = 0; i < size; i++)
		if (i < size / 2)
			lowestCost[i] = productsList[i];
		else
			highestCost[i-size/2] = productsList[i];

	
	int* endList = new int[size]; 

	for (i = 0, j = 0, k = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			endList[i] = highestCost[j];
			j++;
		}
		else
		{
			endList[i] = lowestCost[k];
			k++;
		}
	}
	
	
	
	int sum = 0; 
	
	for (i = 0; size % 2 == 1 ? i < size / 2 + 1 : i < size / 2; i++)
		sum += highestCost[i];




	cout << "\nНачальные цены\n";
	for (i = 0; i < size; i++)
	{
		cout << productsList[i] << ' ';
	}

	cout << "\nМинимальные цены\n";
	for (i = 0; i < size / 2; i++)
		cout << lowestCost[i] << ' ';

	cout << "\nМаксимальные цены\n";
	for (i = 0; size % 2 == 1 ? i < size / 2 + 1 : i < size / 2; i++)
		cout << highestCost[i] << ' ';

	cout << "\n\nКонечный лист цен\n";
	for (i = 0; i < size; i++)
		cout << endList[i] << ' ';

	cout << "\n\nКонечная цена чека = " << sum <<"\n\n";



	return 0;
}