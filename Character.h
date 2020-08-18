#pragma once
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

class Character
{
private:
	int HP;			// показатель здоровья
	int stamina;	// показатель выносливости

public:
	Character();

	/* Геттеры и сеттеры для private полей */
	int GetHP();
	void SetHP(int value);
	int GetStamina();
	void SetStamina(int value = -1);

	/* Метод проверки на смерть */
	bool Die();
};

#endif // !_CHARACTER_H_