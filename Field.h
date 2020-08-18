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
	static int count;		// counter of checked rooms

	bool is_left_door;		// is there a door in this direction
	string type_left_door;	// type(color) of this door

	bool is_right_door;
	string type_right_door;

	const bool is_front_door = true;	// door is always in front of you
	string type_front_door;

	bool is_behind_door;
	string type_behind_door;

	bool is_here_smth;		// is there an event in the room
	string type_of_smth;	// type of event

	string description;		// descryption of event

	enum Inventory{ DOG };	// what may be in inventory

	vector<int> inventory;	// what is in inventory

public:
	Field(Character& hero, int doortype = 0);

	/* Reading a command from the console */
	string Choose_move(Character& hero);

	/* Generating the location and color of doors */
	void Respawn_door(bool& is_door, string& type, int resp, int red, int yel);

	/* Probability distribution and adding an event to a new room */
	void Green_event();

	/* Generating a new room */
	void Generate_new_field(string type_of_door);

	/* Method for interacting with an event in a room */
	void Event(string& event, Character& hero);

	/* Main method. Making a turn. Return true, if a player win */
	bool Update(Character& hero);

	/* Output all necessary information about the game to the console */
	void Show_info(Character& hero);

	/* The message about the victory */
	void Victory();
};

#endif // !_FIELD_H_