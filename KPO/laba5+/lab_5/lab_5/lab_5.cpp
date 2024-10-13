#include "Dictionary.h"
#include <iostream>

int menu(void) {
    char s[80];  int c; // стек память
    std::cout << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "1. Ввод нового справочника" << std::endl;
    std::cout << "2. Ввод новой записи" << std::endl;
    std::cout << "3. Вывод всего справочника на экран на экран" << std::endl;
    std::cout << "4. Поиск номеру в справочнике" << std::endl;
    std::cout << "5. Обновление записи в справочнике (по id)" << std::endl;
    std::cout << "6. Удаление записи из справочника" << std::endl;
    std::cout << std::endl;
    do
    {
        std::cin.ignore(std::cin.rdbuf()->in_avail());
        std::cout << "Ваш выбор: ";
        std::cin.sync();
        gets_s(s);
        std::cout << std::endl;
        c = atoi(s);
    } while (c < 0 || c > 7);
    return c;
}

int main() {
    MyDictionary::Instance d; // cтатическая память 
    MyDictionary::Entry e;
    char dname[1000], ename[ENTRYNAMEMAXSIZE];
    int dsize, eid;

#ifdef TEST_CREATE_01 // макрос+память из кучи
    try 
    {
        MyDictionary::Instance d1 = MyDictionary::Create("qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq", 23);
        MyDictionary::Delete(d);
    }
    catch (const std::invalid_argument& e) // обработка исключений словаря
    {
        std::cout << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) // обработка исключений словаря
    {
        std::cout << e.what() << std::endl;
        MyDictionary::Delete(d);
    }
#endif //
#ifdef TEST_CREATE_02
    try
    {
        MyDictionary::Instance d2 = MyDictionary::Create("q", 123);
        MyDictionary::Delete(d);
    }
    catch (const std::invalid_argument& e) // обработка исключений словаря
    {
        std::cout << e.what() << std::endl;
        MyDictionary::Delete(d);
    }
    catch (const std::out_of_range& e) // обработка исключений словаря
    {
        std::cout << e.what() << std::endl;
        MyDictionary::Delete(d);
    }
#endif //
#ifdef TEST_CREATE_03
    try
    {
        MyDictionary::Instance d3 = MyDictionary::Create("q", 1);
        MyDictionary::Etry e1 = { 1, "1" };
        MyDictionary::Etry e2 = { 2, "1" };
        MyDictionary::AddEntry(d, e1);
        MyDictionary::AddEntry(d, e2);
        MyDictionary::Delete(d);
    }
    catch (const std::invalid_argument& e) // обработка исключений словаря
    {
        std::cout << e.what() << std::endl;
        MyDictionary::Delete(d);
    }
    catch (const std::out_of_range& e) // обработка исключений словаря
    {
        MyDictionary::Delete(d);
        std::cout << e.what() << std::endl;
    }
#endif // 
#ifdef TEST_CREATE_04
    try
    {
        MyDictionary::Instance d4 = MyDictionary::Create("q", 2);
        MyDictionary::Etry e3 = { 1, "1" };
        MyDictionary::Etry e4 = { 1, "1" };
        MyDictionary::AddEntry(d, e1);
        MyDictionary::AddEntry(d, e2);
        MyDictionary::Delete(d);
    }
    catch (const std::invalid_argument& e) // обработка исключений словаря
    {
        std::cout << e.what() << std::endl;
        MyDictionary::Delete(d);
    }
    catch (const std::out_of_range& e) // обработка исключений словаря
    {
        MyDictionary::Delete(d);
        std::cout << e.what() << std::endl;
    }
#endif // 
#ifdef TEST_CREATE_05
    try
    {
        MyDictionary::Instance d5 = MyDictionary::Create("q", 2);
        MyDictionary::Etry e5 = { 1, "1" };
        MyDictionary::Etry e6 = { 2, "1" };
        MyDictionary::AddEntry(d, e1);
        MyDictionary::AddEntry(d, e2);
        MyDictionary::GetEntry(d, e3);
        MyDictionary::Delete(d);
    }
    catch (const std::invalid_argument& e) // обработка исключений словаря
    {
        std::cout << e.what() << std::endl;
        MyDictionary::Delete(d);
    }
    catch (const std::out_of_range& e) // обработка исключений словаря
    {
        std::cout << e.what() << std::endl;
        MyDictionary::Delete(d);
    }
#endif // 
#ifdef TEST_CREATE_06
    try
    {
        MyDictionary::Instance d7 = MyDictionary::Create("q", 2);
        MyDictionary::Etry e7 = { 1, "1" };
        MyDictionary::Etry e8 = { 2, "1" };
        MyDictionary::AddEntry(d, e1);
        MyDictionary::AddEntry(d, e2);
        MyDictionary::DelEntry(d, e3);
        MyDictionary::Delete(d);
    }
    catch (const std::invalid_argument& e) // обработка исключений словаря
    {
        std::cout << e.what() << std::endl;
        MyDictionary::Delete(d);
    }
    catch (const std::out_of_range& e) // обработка исключений словаря
    {
        std::cout << e.what() << std::endl;
        MyDictionary::Delete(d);
    }
#endif // 
#ifdef TEST_CREATE_07
    try
    {
        MyDictionary::Instance d8 = MyDictionary::Create("q", 2);
        MyDictionary::Etry e9 = { 1, "1" };
        MyDictionary::Etry e10 = { 2, "1" };
        MyDictionary::AddEntry(d, e1);
        MyDictionary::AddEntry(d, e2);
        MyDictionary::UpdEntry(d, 3);
        MyDictionary::Delete(d);
    }
    catch (const std::invalid_argument& e) // обработка исключений словаря
    {
        std::cout << e.what() << std::endl;
        MyDictionary::Delete(d);
    }
    catch (const std::out_of_range& e) // обработка исключений словаря
    {
        std::cout << e.what() << std::endl;
        MyDictionary::Delete(d);
    }
#endif // 
#ifdef TEST_CREATE_07
    try
    {
        MyDictionary::Instance d9 = MyDictionary::Create("q", 2);
        MyDictionary::Etry e11 = { 1, "1" };
        MyDictionary::Etry e12 = { 2, "1" };
        MyDictionary::AddEntry(d, e1);
        MyDictionary::AddEntry(d, e2);
        MyDictionary::UpdEntry(d, 2);
        MyDictionary::Delete(d);
    }
    catch (const std::invalid_argument& e) // обработка исключений словаря
    {
        std::cout << e.what() << std::endl;
        MyDictionary::Delete(d);
    }
    catch (const std::out_of_range& e) // обработка исключений словаря
    {
        std::cout << e.what() << std::endl;
        MyDictionary::Delete(d);
    }
#endif //

#ifdef TEST_DICTIONARY
    // Включить тестовый режим
    try
    {
#endif
        while (true)
        {
            switch (menu())
            {
            case 0: exit(0);
            case 1: {
                std::cout << "Введите имя справочника: "; std::cin >> dname;
                std::cout << "Введите размер справочника: "; std::cin >> dsize;
                d = MyDictionary::Create(dname, dsize);
                std::cin.ignore(std::cin.rdbuf()->in_avail());
                break;
            }
            case 2: {
                std::cout << "Введите имя человека: "; std::cin >> ename;
                std::cout << "Введите его id: "; std::cin >> eid;
                e = { eid, *ename };
                MyDictionary::AddEntry(d, e);
                std::cin.ignore(std::cin.rdbuf()->in_avail());
                break;
            }
            case 3: MyDictionary::Print(d); break;
            case 4: {
                std::cout << "Введите id человека которого хотите найти: "; std::cin >> eid;
                MyDictionary::Entry element = MyDictionary::GetEntry(d, eid);
                std::cout << element.id << " " << element.name << std::endl;
                std::cin.ignore(std::cin.rdbuf()->in_avail());
                break;
            }
            case 5: {
                std::cout << "Введите id записи которую хотите обновить: "; std::cin >> eid;
                std::cout << "Введите имя человека: "; std::cin >> ename;
                std::cout << "Введите его id: "; std::cin >> eid;
                e = { eid, *ename };
                MyDictionary::UpdEntry(d, eid, e);
                std::cout << "Запись успешно изменена\n";
                std::cin.ignore(std::cin.rdbuf()->in_avail());
                break;
            }
            case 6: {
                std::cout << "Введите id человека которого хотите удалить из справочника: "; std::cin >> eid;
                MyDictionary::DelEntry(d, eid);
                std::cout << "Запись успешно удалена\n";
                std::cin.ignore(std::cin.rdbuf()->in_avail());
                break;
            }
            default: exit(1);
            }
        }
        MyDictionary::Delete(d);
#ifdef TEST_DICTIONARY
        MyDictionary::Delete(d);
}
    catch (const std::invalid_argument& e) // обработка исключений словаря
    {
        std::cout << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) // обработка исключений словаря
    {
        std::cout << e.what() << std::endl;
        MyDictionary::Delete(d);
    }
#endif
    return 0;
}
