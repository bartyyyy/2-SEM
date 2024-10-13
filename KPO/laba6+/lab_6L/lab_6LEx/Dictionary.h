#pragma once
#include <cstring>
#define DICTNAMEMAXSIZE 20 
#define DICTMAXSIZE 100 
#define ENTRYNAMEMAXSIZE 30
#define THROW01 "Create: превышена длина имени\n"
#define THROW02 "Create: превышен максимальный размер словаря\n"
#define THROW03 "AddEntry: превышен максимальный размер словаря\n"
#define THROW04 "AddEntry: запись уже существует\n"
#define THROW05 "GetEntry: запись не найдена\n"

#define THROW06 "DelEntry: запись не найдена\n"
#define THROW07 "UpdEntry: запись не найдена\n"
#define THROW08 "UpdEntry: слишком много записей найдено\n"

namespace MyDictionary
{
	struct Entry
	{
		int id; // Идентификатор(ключ)
		char name[ENTRYNAMEMAXSIZE]; // Имя записи
	};
	struct Instance // Структура словаря
	{
		char name[DICTNAMEMAXSIZE]; // Имя словаря
		int maxsize; // Максимальный размер словаря
		int size; // Текущий размер словаря
		Entry* dictionary; // Массив структур словаря
	};
	Instance Create( // Создание словаря
		const char name[DICTNAMEMAXSIZE], // Имя словаря
		int size // Размер словаря < DICTNAMEMAXSIZE
	);
	void AddEntry( // Добавление записи в словарь
		Instance& inst, // Ссылка на словарь
		Entry ed // Добавляемая запись
	);
	void DelEntry( // Удаление записи из словаря
		Instance& inst, // Ссылка на словарь
		int id // Идентификатор удаляемой записи (ключ)
	);
	void UpdEntry( // Обновление записи в словаре
		Instance& inst, // Ссылка на словарь
		int id, // Идентификатор удаляемой записи (ключ)
		Entry new_ed // Новая запись для обновления
	);
	Entry GetEntry(
		Instance& inst, // Ссылка на словарь
		int id // Идентификатор удаляемой записи (ключ)
	);
	void Print(Instance d); // Печать словаря
	void Delete(Instance& d); // Удаление словаря
}
