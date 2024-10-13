#include <iostream>

using namespace std;

int main()
{

	int N, tmp, step;
	int awardess = 0;
	int i, j, k;

	do
	{
		cout << "Введите количество товаров: ";
		cin >> N;

		if (N > 10000 || N < 0)
			cout << "Некорректный ввод";
	} while (N > 10000 || N < 0);

	int size = N;

	int* participantScores = new int[size]; 

	for (i = 0; i < size; i++)	
		participantScores[i] = (rand() % 10 + 1);



	for (step = size / 2; step > 0; step /= 2)
		for (i = step; i < size; i++)
		{
			tmp = participantScores[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < participantScores[j - step])
					participantScores[j] = participantScores[j - step];
				else
					break;
			}
			participantScores[j] = tmp;
		}



	unsigned int top1 = participantScores[size-1], top2 = participantScores[size-1], top3 = participantScores[size-1]; 
	bool top2Check = true,top3Check = true;

	for (i = size-1; i > 0; i--)
	{
		if (top2 > participantScores[i] && top2Check && top2 >=top1)
		{
			top2 = participantScores[i];
			top2Check = false;
		}
		if (top3 > participantScores[i] && top3Check && participantScores[i] != top2)
		{
			top3 = participantScores[i];
			top3Check = false;
		}

		
	}


	for (i = size-1; i > 0; i--)
		if (participantScores[i] == top1 || participantScores[i] == top2 || participantScores[i] == top3)
			awardess++;

	cout << "\nНачальный массив данных" << '\n';
	for (i = 0; i < size; i++)
		cout << participantScores[i] << ' ';


	cout << "\n\n" << top1 << ' ' << top2 << ' ' << top3;

	cout << "\n\nКоличество призёров = " << awardess << "\n\n";

	return 0;
}