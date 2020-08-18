#pragma once
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

class Character
{
private:
	int HP;
	int stamina;

public:
	Character();

	/* Getters and setters for private fields */
	int GetHP();
	void SetHP(int value);
	int GetStamina();
	void SetStamina(int value = -1);

	/* Check for death */
	bool Die();
};

#endif // !_CHARACTER_H_