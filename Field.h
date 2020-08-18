#pragma once
#ifndef _FIELD_H_
#define _FIELD_H_

#include <string>
#include <vector>

using namespace std;

class Character;

class Field
{
private:
	static int count;		// счетчик пройденных комнат

	bool is_left_door;		// есть ли дверь в этом направлении
	string type_left_door;	// цвет(тип) этой двери

	bool is_right_door;
	string type_right_door;

	const bool is_front_door = true;	// дверь спереди есть всегда, чтобы не было ситуации, когда дверей нет вообще
	string type_front_door;

	bool is_behind_door;
	string type_behind_door;

	bool is_here_smth;		// есть ли событие в комнате
	string type_of_smth;	// тип события

	string description;		// пояснение события

	enum Inventory{ DOG };	// что может быть в инвентаре

	vector<int> inventory;	// что фактически находится в инвентаре

public:
	Field(Character& hero, int doortype = 0);

	/* Считывание команды с консоли */
	string Choose_move(Character& hero);

	/* Генерация местонахождения и цвета дверей */
	void Respawn_door(bool& is_door, string& type, int resp, int red, int yel);

	/* Распределение вероятностей и добавление события в новую комнату 
		(в данный момент один метод на все типы дверей/комнат; в дальнейшем по методу на каждый тип) */
	void Green_event();

	/* Генерация новой комнаты */
	void Generate_new_field(string type_of_door);

	/* Метод взаимодействия с событием в комнате */
	void Event(string& event, Character& hero);

	/* Основной метод. Совершение хода игроком. Возвращает true, если соблюдено условие победы */
	bool Update(Character& hero);

	/* Вывод всей необходимой информации об игре на консоль */
	void Show_info(Character& hero);

	/* Сообщение о победе */
	void Victory();
};

#endif // !_FIELD_H_