#include <iostream>
#include <fstream>
using namespace std;

const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address {
    char name[NAME_SIZE];
    char city[CITY_SIZE];
    Address* next;
    Address* prev;
};

int menu(void);
void insert(Address* e, Address** phead, Address** plast);
Address* setElement();
void outputList(Address** phead, Address** plast);
void find(char name[NAME_SIZE], Address** phead);
void deleteElement(char name[NAME_SIZE], Address** phead, Address** plast);
void deleteKLast(int k, Address** phead, Address** plast);
void writeToFile(Address** phead);
void readFromFile(Address** phead, Address** plast);

int main(void) {
    Address* head = nullptr;
    Address* last = nullptr;

    while (true) {
        switch (menu()) {
        case 1:
            insert(setElement(), &head, &last);
            break;
        case 2: {
            char dname[NAME_SIZE];
            cout << "Введите имя: ";
            cin.getline(dname, NAME_SIZE - 1, '\n');
            cin.ignore(cin.rdbuf()->in_avail());
            cin.sync();
            deleteElement(dname, &head, &last);
        }
              break;
        case 3:
            outputList(&head, &last);
            break;
        case 4: {
            char fname[NAME_SIZE];
            cout << "Введите имя: ";
            cin.getline(fname, NAME_SIZE - 1, '\n');
            cin.ignore(cin.rdbuf()->in_avail());
            cin.sync();
            find(fname, &head);
        }
              break;
        case 5:
            writeToFile(&head);
            exit(0);
        case 6:
            readFromFile(&head, &last);
            break;
        case 7: {
            int k;
            cout << "Введите количество элементов для удаления: ";
            cin >> k;
            deleteKLast(k, &head, &last);
        }
              break;
        case 8:
            exit(0);
        default:
            exit(1);
        }
    }
    return 0;
}

int menu(void) {
    char s[80];
    int c;
    cout << endl;
    cout << "1. Ввод имени" << endl;
    cout << "2. Удаление имени" << endl;
    cout << "3. Вывод на экран" << endl;
    cout << "4. Поиск" << endl;
    cout << "5. Сохранить в файл" << endl;
    cout << "6. Загрузить из файла" << endl;
    cout << "7. Удалить последние К элементов" << endl;
    cout << "8. Выход" << endl;
    cout << endl;
    do {
        cout << "Ваш выбор: ";
        cin.sync();
        gets_s(s);
        cout << endl;
        c = atoi(s);
    } while (c < 1 || c > 8);
    return c;
}

void insert(Address* e, Address** phead, Address** plast) {
    Address* p = *plast;
    if (*plast == nullptr) {
        e->next = nullptr;
        e->prev = nullptr;
        *plast = e;
        *phead = e;
    }
    else {
        p->next = e;
        e->next = nullptr;
        e->prev = p;
        *plast = e;
    }
}

Address* setElement() {
    Address* temp = new  Address();
    if (!temp) {
        cerr << "Ошибка выделения памяти памяти";
        return nullptr;
    }
    cout << "Введите имя: ";
    cin.getline(temp->name, NAME_SIZE - 1, '\n');
    cin.ignore(cin.rdbuf()->in_avail());
    cin.clear();
    cout << "Введите город: ";
    cin.getline(temp->city, CITY_SIZE - 1, '\n');
    cin.ignore(cin.rdbuf()->in_avail());
    cin.clear();
    temp->next = nullptr;
    temp->prev = nullptr;
    return temp;
}

void outputList(Address** phead, Address** plast) {
    Address* t = *phead;
    while (t) {
        cout << t->name << ' ' << t->city << endl;
        t = t->next;
    }
    cout << "" << endl;
}

void find(char name[NAME_SIZE], Address** phead) {
    Address* t = *phead;
    while (t) {
        if (!strcmp(name, t->name))
            break;
        t = t->next;
    }
    if (!t)
        cerr << "Имя не найдено" << endl;
    else
        cout << t->name << ' ' << t->city << endl;
}

void deleteElement(char name[NAME_SIZE], Address** phead, Address** plast) {
    Address* t = *phead;
    while (t) {
        if (!strcmp(name, t->name))
            break;
        t = t->next;
    }
    if (!t)
        cerr << "Имя не найдено" << endl;
    else {
        if (*phead == t) {
            *phead = t->next;
            if (*phead)
                (*phead)->prev = nullptr;
            else
                *plast = nullptr;
        }
        else {
            t->prev->next = t->next;
            if (t != *plast)
                t->next->prev = t->prev;
            else
                *plast = t->prev;
        }
        delete t;
        cout << "Элемент удален" << endl;
    }
}

void deleteKLast(int k, Address** phead, Address** plast) {
    if (*phead == nullptr || k <= 0)
        return;

    Address* current = *plast;
    for (int i = 0; i < k - 1 && current != nullptr; ++i)
        current = current->prev;

    if (current == nullptr)
        return;

    if (current == *plast) {
        *plast = current->prev;
        (*plast)->next = nullptr;
    }
    else {
        current->prev->next = nullptr;
        *plast = current->prev;
    }

    while (current != nullptr) {
        Address* temp = current;
        current = current->prev;
        delete temp;
    }

    if (*plast == nullptr)
        *phead = nullptr;
}

void writeToFile(Address** phead) {
    Address* t = *phead;
    FILE* fp;
    errno_t err = fopen_s(&fp, "mlist", "wb");
    if (err) {
        cerr << "Файл не открывается" << endl;
        exit(1);
    }
    cout << "Сохранение в файл" << endl;
    while (t) {
        fwrite(t, sizeof(struct Address), 1, fp);
        t = t->next;
    }
    fclose(fp);
}

void readFromFile(Address** phead, Address** plast) {
    Address* t;
    FILE* fp;
    errno_t err = fopen_s(&fp, "mlist", "rb");
    if (err) {
        cerr << "Файл не открывается" << endl;
        exit(1);
    }
    while (*phead) {
        *plast = (*phead)->next;
        delete* phead;
        *phead = *plast;
    }
    *phead = *plast = nullptr;
    cout << "Загрузка из файла" << endl;
    while (!feof(fp)) {
        t = new Address();
        if (!t) {
            cerr << "Ошибка выделения памяти" << endl;
            return;
        }
        if (1 != fread(t, sizeof(struct Address), 1, fp))
            break;
        insert(t, phead, plast);
    }
    fclose(fp);
}
