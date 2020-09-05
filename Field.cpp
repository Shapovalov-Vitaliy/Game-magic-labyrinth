#include <iostream>
#include <string>
#include <algorithm>

#include "Field.h"
#include "Character.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;
class Character;

Field::Field(Character& hero, int doortype)
{
	this->is_left_door = false;
	this->is_right_door = false;
	this->is_behind_door = false;


	this->is_here_smth = false;
	this->type_of_smth = "a dog";
	this->description = "Pretty french buldog jump on you. You must take him with you";

	this->type_behind_door = "green";
	this->type_left_door = "green";
	this->type_right_door = "green";
	this->type_front_door = "green";
}

string Field::Choose_move(Character& hero)
{
	string str;
	cin >> str;
	return str;
}

void Field::Respawn_door(bool& is_door, string& type, int resp, int red, int yel)
{
	int random;
	int subrandom;

	random = rand() % 100;

	if (random < resp)
	{
		is_door = true;
		subrandom = rand() % 100;
		if (subrandom < red)
			type = "red";
		else if (subrandom >= red && subrandom < yel)
			type = "yellow";
		else
			type = "green";
	}
	else
		is_door = false;
}

void Field::Green_event()
{
	int random;
	random = rand() % 2;
	if (random == 0)
	{
		this->type_of_smth = "a potion";
		this->description = "On the label written \"Drink me\"";
	}
	else if (random == 1)
	{
		this->type_of_smth = "a shelf with books";
		this->description = "Books are dust-covered, they have not been opened for a long time";
	}
}

void Field::Yellow_event()
{
	int random;
	random = rand() % 2;

	if (random == 0)
	{
	this->type_of_smth = "a doghouse";
	this->description = "This doghouse seems inhabited, but there is nothing here";
	}
	else if (random == 1)
	{
	this->type_of_smth = "a trapdoor";
	this->description = "Heavy trapdoor is here. Is this escape?";
	}
}

void Field::Red_event()
{
	int random;
	random = rand() % 1;

	if (random == 0)
	{
	this->type_of_smth = "a flute and a bag";
	this->description = "There is carpet in this room. A flute is on it and a bag is in front of it";
	}
}

void Field::Generate_new_field(string type_of_door) // CHANGE NUMBER AND TYPE OF DOORS AND SET EVENT BY RANDOM
{
	if (type_of_door == "green")
	{
		Green_event();
		Respawn_door(this->is_left_door, this->type_left_door, 45, 10, 60);
		Respawn_door(this->is_right_door, this->type_right_door, 45, 10, 60);
		Respawn_door(this->is_behind_door, this->type_behind_door, 45, 10, 60);
		this->type_front_door = "red";

	}
	else if (type_of_door == "yellow")
	{
		Yellow_event();
		Respawn_door(this->is_left_door, this->type_left_door, 45, 30, 65);
		Respawn_door(this->is_right_door, this->type_right_door, 45, 30, 65);
		Respawn_door(this->is_behind_door, this->type_behind_door, 45, 30, 65);
		this->type_front_door = "red";
	}
	else if (type_of_door == "red")
	{
		Red_event();
		Respawn_door(this->is_left_door, this->type_left_door, 45, 60, 90);
		Respawn_door(this->is_right_door, this->type_right_door, 45, 60, 90);
		Respawn_door(this->is_behind_door, this->type_behind_door, 45, 60, 90);
		this->type_front_door = "red";
	}
}

void Field::Event(string& event, Character& hero) // DEPENDING ON event SOMETHING HAPPENS
{
	if (event == "a potion")
	{
		int random = rand() % 100;

		if (random >= 0 && random <= 25)
		{
			hero.SetHP(1);
			hero.SetStamina(3);
			this->description = "it's disgusting, but invigorating. -1 HP, +3 stamina";
		}
		else if (random >= 26 && random <= 50)
		{
			hero.SetHP(2);
			hero.SetStamina(-3);
			this->description = "It's disgusting. You throw up. -2 HP, -3 stamina";
		}
		else if (random >= 51 && random <= 99)
		{
			hero.SetHP(-4);
			hero.SetStamina(0);
			this->description = "It's very tasty. +4 HP";
		}
		event = "nothing else";
	}

	if (event == "a shelf with books")
	{
		int random = rand() % 1000;

		if (random >= 0 && random <= 499)
		{
			hero.SetHP(1);
			this->description = "You found a book about thermodynamics. You didn't learn anything, but your eyes hurt. -1 HP";
		}
		else if (random >= 500 && random <= 998)
		{
			hero.SetHP(-1);
			this->description = "You found a fat book. It full of medicinal herb. +1 HP";
		}
		else if (random == 999)
		{
			this->description = "Secret!!! You found a story book. Contact the Creator for the fairytale.";
		}
		event = "nothing else";
	}

	if (event == "a dog")
	{
		inventory.push_back(DOG);
		this->description = "Dog is happy!";
		event = "nothing else";
	}

	if (event == "a doghouse")
	{
		if (find(inventory.begin(), inventory.end(), DOG) != inventory.end())
		{
			inventory.erase(remove_if(inventory.begin(), inventory.end(), [](const int& i)
				{
					return i == DOG;
				}), inventory.end());
			inventory.push_back(BONE);

			this->description = "Your dog is home. In gratitude, he gives his favorite bone.";
		}
		else
		{
			this->description = "You found nothing.";
		}

		event = "nothing else";
	}

	if (event == "a trapdoor")
	{
		int random = rand() % 2;

		if (random == 0)
		{
			if (find(inventory.begin(), inventory.end(), DOG) != inventory.end())
			{
				inventory.erase(remove_if(inventory.begin(), inventory.end(), [](const int& i)
					{
						return i == DOG;
					}), inventory.end());

				this->description = "As soon as you open the trapdoor, your dog jump in darkness. You couldn't get through the doorway because it's narrow.";
			}
			else
			{
				this->description = "You open the trapdoor, but see nothing in the darkness. You couldn't get through the doorway because it's narrow.";
			}
		}
		else if (random == 1)
		{
			count++;
			Generate_new_field("red");
			hero.SetStamina();

			this->type_of_smth = "nothing";
			this->description = "You jumped through the doorway and landed on soft pillows.";
		}

		event = "nothing else";
	}

/*	if (event == "a chest")
	{

	}*/

	if (event == "a flute and a bag")
	{
		int random = rand() % 3;

		if (random == 0)
		{
			hero.SetStamina(10);
			this->description = "You start playing the flute. A snake crawls out of the bag and looks at you carefully. As soon as you finish, the snake crawls away into the darkness. You feel refreshed. +10 stamina";
		}
		else if (random == 1)
		{
			this->description = "You start playing the flute. You're good at it. A poison snake crawls out of the bag and hears you. As soon as you finish, the snake crawls away into the darkness.";
		}
		else if (random == 2)
		{
			hero.SetHP(hero.GetHP() - 1);
			this->description = "You start playing the flute. You play terribly. A poison snake crawls out of the bag, crowls up to you and beats. You feel weekness. HP = 1";
		}

		event = "nothing else";
	}
}

bool Field::Update(Character& hero)
{
	string choice = this->Choose_move(hero);
	if (choice == "behind" && is_behind_door)
	{
		count++;
		Generate_new_field(type_behind_door);
		hero.SetStamina();
	}
	if (choice == "left" && is_left_door)
	{
		count++;
		Generate_new_field(type_left_door);
		hero.SetStamina();
	}
	if (choice == "right" && is_right_door)
	{
		count++;
		Generate_new_field(type_right_door);
		hero.SetStamina();
	}
	if (choice == "front" && is_front_door)
	{
		count++;
		Generate_new_field(type_front_door);
		hero.SetStamina();
	}
	else if (choice == "use" && this->type_of_smth != "nothing")
	{
		Event(type_of_smth, hero);
	}
	else if (choice == "die")
	{
		hero.SetHP(50);
		if (hero.GetHP() > 0)
			return true;
	}

	return false;
}

void Field::Show_info(Character& hero)
{
	system(CLEAR);

	cout << "You are in magic tower. Can you escape this?" << endl;
	cout << "Use this commands:" << endl;
	cout << "\t'right', 'left', 'front', 'behind' for open the doors." << endl;
	cout << "\t'use' for interact with something in the room." << endl;
	cout << "\t'die' to give up and die." << endl << endl;

	cout << "////////////////////////////////////////////////////////////////" << endl << endl;

	cout << "Your HP: " << hero.GetHP() << "\tYour stamina: " << hero.GetStamina() << "\t" << count << " rooms checked" << endl << endl;

	if (!inventory.empty())
	{
		cout << "You have:";
		for (auto thing : inventory)
		{
			switch (thing)
			{
			case DOG:
				cout << " a dog |";
			default:
				break;
			}
		}
		cout << endl;
	}

	if (this->is_behind_door)
		cout << "This room has " << this->type_behind_door << " door behind you" << endl;
	if (this->is_left_door)
		cout << "This room has " << this->type_left_door << " door on the left" << endl;
	if (this->is_right_door)
		cout << "This room has " << this->type_right_door << " door on the right" << endl;
	if (this->is_front_door)
		cout << "This room has " << this->type_front_door << " door in front of you" << endl;
	cout << "There is " << this->type_of_smth << " in this room" << endl;
	cout << this->description << endl << endl;
}

void Field::Victory()
{
	system("cls");
	cout << "You killed yourself but not dead. You woke up at home in your bed." << endl;
	cout << "It was just a dream." << endl << endl;
	cout << "Congratulations!!!" << endl;
	cout << "You checked " << count << " rooms" << endl;
}

int Field::count = 0;