#pragma once
#ifndef _FIELD_H_
#define _FIELD_H_

#include <string>
#include <vector>

class Field
{
private:
	static int count;

	bool is_left_door;
	string type_left_door;

	bool is_right_door;
	string type_right_door;

	const bool is_front_door = true;
	string type_front_door;

	bool is_behind_door;
	string type_behind_door;

	bool is_here_smth;
	string type_of_smth;

	string description;

	enum Inventory{ DOG };

	vector<int> inventory;

public:
	Field(Character& hero, int doortype = 0);
	string Choose_move(Character& hero);
	void Respawn_door(bool& is_door, string& type, int resp, int red, int yel);
	void Green_event();
	void Generate_new_field(string type_of_door);
	void Event(string& event, Character& hero);
	bool Update(Character& hero);
	void Show_info(Character& hero);
	void Victory();
};

#endif // !_FIELD_H_