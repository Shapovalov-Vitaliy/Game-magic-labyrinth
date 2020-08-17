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
	int GetHP();
	void SetHP(int);
	int GetStamina();
	void SetStamina(int = -1);
	bool Die();
};

#endif // !_CHARACTER_H_