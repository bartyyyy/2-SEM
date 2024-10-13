#pragma once
#include <cstring>
#include "stdafx.h"
#define DICTNAMEMAXSIZE 20 // максимальная длина имени словаря
#define DICTMAXSIZE 100 // максимальный размер словаря
#define ENTRYNAMEMAXSIZE 30 // максимальная длина имени в записи
#define THROW01 "Create: ошибка выделения памяти\n"
#define THROW02 "Create: ошибка инициализации пустого словаря\n"
#define THROW03 "AddEntry: невозможно добавить запись\n"
#define THROW04 "AddEntry: запись уже существует\n"
#define THROW05 "GetEntry: запись не найдена\n"
#define THROW06 "DelEntry: запись не найдена\n"
#define THROW07 "UpdEntry: запись не найдена\n"
#define THROW08 "UpdEntry: ошибка обновления записи\n"

namespace MyDictionary
{
    struct Entry
    {
        int id; // идентификатор (уникальный)
        char name[ENTRYNAMEMAXSIZE]; // имя записи
    };
    struct Instance // структура словаря
    {
        char name[DICTNAMEMAXSIZE]; // название словаря
        int maxsize; // максимальный размер словаря
        int size; // текущий размер словаря
        Entry* dictionary; // массив структур словаря
    };
    Instance Create( // создание словаря
        const char name[DICTNAMEMAXSIZE], // имя словаря
        int size // размер словаря < DICTNAMEMAXSIZE
    );
    void AddEntry( // добавление записи в словарь
        Instance& inst, // экземпляр словаря
        Entry ed // добавляемая запись
    );
    void DelEntry( // удаление записи из словаря
        Instance& inst, // экземпляр словаря
        int id // идентификатор удаляемой записи (уникальный)
    );
    void UpdEntry( // обновление записи в словаре
        Instance& inst, // экземпляр словаря
        int id, // идентификатор обновляемой записи (уникальный)
        Entry new_ed // новая версия записи
    );
    Entry GetEntry(
        Instance& inst, // экземпляр словаря
        int id // идентификатор искомой записи (уникальный)
    );
    void Print(Instance d); // печать словаря
    void Delete(Instance& d); // удаление словаря
}
