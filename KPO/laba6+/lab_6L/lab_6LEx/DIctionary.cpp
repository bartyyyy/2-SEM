#include "Dictionary.h"
#include <iostream>
#include <cstring>
#include <stdexcept> // Для std::invalid_argument и std::out_of_range

namespace MyDictionary
{
    int FindEntry(Instance& inst, int id) {
        int countIds = 0;
        for (int i = 0; i <= inst.size; i++)
        {
            if (inst.dictionary[i].id == id) countIds++;
        }
        if (countIds == 1) return 1;
        return 0;
    }

    Instance Create(const char name[DICTNAMEMAXSIZE], int size) {
        if (std::strlen(name) >= DICTNAMEMAXSIZE) throw std::invalid_argument(THROW01);
        else if (size >= DICTMAXSIZE) throw std::invalid_argument(THROW02);
        Instance dict;
        dict.size = 0;
        dict.dictionary = new Entry[size]; // Выделяем память под массив dictionary размером size
        strcpy_s(dict.name, name); // Копируем имя с помощью strcpy
        dict.maxsize = size;
        return dict;
    }

    void AddEntry(Instance& inst, Entry ed) {
        // Проверяем, есть ли место в словаре для новой записи
        if (inst.size >= inst.maxsize) throw std::out_of_range(THROW03);
        int isel = FindEntry(inst, ed.id);
        if (isel) throw std::invalid_argument(THROW04);
        // Добавляем запись в словарь
        inst.dictionary[inst.size] = ed;
        inst.size++; // Увеличиваем счетчик записей
    }

    void DelEntry(Instance& inst, int id) {
        int i, flag = 0;
        for (i = 0; i < inst.size; i++)
        {
            if (inst.dictionary[i].id == id)
            {
                flag++; // Увеличиваем счетчик найденных записей
                break;
            }
        }

        if (!flag) throw std::out_of_range(THROW06);

        // Сдвигаем все записи влево на одну позицию, начиная с найденной записи
        for (i; i < inst.size - 1; ++i)
        {
            inst.dictionary[i] = inst.dictionary[i + 1];
            inst.dictionary[i].id--;
        }

        inst.size--; // Уменьшаем размер словаря
    }

    void UpdEntry(Instance& inst, int id, Entry new_ed) {
        int countIds = 0, i;
        for (i = 0; i < inst.size; ++i)
        {
            if (inst.dictionary[i].id == id)
            {
                countIds++;
            }
        }
        if (!countIds) throw std::out_of_range(THROW07);
        else if (countIds < 1) inst.dictionary[i] = new_ed; // Заменяем найденную запись новой записью
        else throw std::invalid_argument(THROW08);
    }

    Entry GetEntry(Instance& inst, int id) {
        int countIds = 0;
        Entry* dictptr = inst.dictionary;
        Entry dict = { -1, "none" };
        for (int i = 0; i <= inst.size; i++)
        {
            Entry* dictptrbeh = inst.dictionary + i;
            if (dictptrbeh->id == id)
            {
                dictptr = dictptrbeh;
                countIds++;
            }
        }
        if (!countIds) throw std::out_of_range(THROW05);
        else if (countIds == 1) dict = *dictptr;
        return dict;

    }

    void Print(Instance d) {
        if (d.dictionary == nullptr)
        {
            std::cerr << "Ошибка: словарь не инициализирован\n";
            return;
        }

        for (int i = 0; i < 7; ++i) {
            std::cout << '-';
        }
        std::cout << " " << d.name << " ";
        for (int i = 0; i < 7; ++i) {
            std::cout << '-';
        }
        std::cout << std::endl;

        for (int i = 0; i < d.size; i++)
        {
            if (i >= d.maxsize)
            {
                std::cerr << "Превышен размер словаря\n";
                return;
            }

            Entry* dictptrbeh = d.dictionary + i;
            std::cout << dictptrbeh->id << " " << dictptrbeh->name << std::endl;
        }
    }

    void Delete(Instance& d) {
        d.size = 0; // Устанавливаем размер словаря в 0
        delete[] d.dictionary; // Освобождаем память, выделенную для словаря
        d.dictionary = nullptr; // Указываем, что указатель на словарь пуст
    }
}
