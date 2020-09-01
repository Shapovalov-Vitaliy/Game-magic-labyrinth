#include "Character.h"

Character::Character()
{
	HP = 5;
	stamina = 20;
}

int Character::GetHP() { return HP; }

void Character::SetHP(int damage) { HP -= damage; }

int Character::GetStamina() { return stamina; }

void Character::SetStamina(int value/* = -1*/) { stamina += value; }

bool Character::Die()
{
	if (this->GetHP() > 0 && this->GetStamina() > 0)
		return false;
	return true;
}