#include <iostream>

using namespace std;

int main() {

    int choose, counter = 1;
    long int low = 1, high, x;

    cout << "Введите число n: ";
    cin >> high;


    int* stepCounter = new int[100];

    high;
    x = (low + high) / 2;

    stepCounter[0] = high;
    stepCounter[1] = x;

    if (high == 0) 
    {
        cout << "Максимальное количество шагов =  " << counter << endl;
        for (int i = 0; i < counter; i++)
            cout << stepCounter[i] << endl;

        return printf("Ваше число : %d", high);
    }

    do {
        cout << "Ваше число: " << x << endl;
        cout << "Выберете 1 - Меньше, 2 - Больше, 3 - Правильно\n";
        cin >> choose;
        switch (choose) {
        case 1: {
            high = x - 1;
            x = (low + high) / 2;
            counter++;
            stepCounter[counter] = x;
            if (high == low)
            {
                cout << "Максимальное количество шагов =  " << counter << endl;
                for (int i = 0; i < counter; i++)
                    cout << stepCounter[i] << endl;
                return printf("Ваше число : %d", high);
            }
            else if(x == high)
            {
                cout << "Максимальное количество шагов =  " << counter << endl;
                for (int i = 0; i < counter; i++)
                    cout << stepCounter[i] << endl;
                return printf("Ваше число : %d", high);

            }
            break;
        }
        case 2: {
            if (x == high)
            {
                cout << "Такой вариант не работает\n";
                break;
            }
            low = x + 1;
            x = (low + high) / 2;
            counter++;
            stepCounter[counter] = x;
            if (high == low){
                cout << "Максимальное количество шагов =  " << counter << endl;
                for (int i = 0; i < counter; i++)
                    cout << stepCounter[i] << endl;
                return printf("Ваше число : %d", high);
            }
            break;
        }
        case 3: {
            cout << "Максимальное количество шагов =  " << counter << endl;
            for (int i = 0; i < counter; i++)
                cout << stepCounter[i] << endl;
            break;
        }
        default:
            cout << "Неправильный выбор" << endl;
            break;
        }
    } while (choose != 3);

    delete[] stepCounter;

    return 0;
}