#pragma once
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

class Character
{
private:
	int HP;			// ���������� ��������
	int stamina;	// ���������� ������������

public:
	Character();

	/* ������� � ������� ��� private ����� */
	int GetHP();
	void SetHP(int value);
	int GetStamina();
	void SetStamina(int value = -1);

	/* ����� �������� �� ������ */
	bool Die();
};

#endif // !_CHARACTER_H_