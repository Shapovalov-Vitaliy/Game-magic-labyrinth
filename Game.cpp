#include <ctime>

#include "Character.h"
#include "Field.h"

int main()
{
	srand(time(NULL));

	/* Начальная генерация игры */
	Character hero;
	Field field(hero);
	field.Show_info(hero);

	/* Основной цикл игры */
	while (!hero.Die())
	{
		if (field.Update(hero))
			field.Victory();
		else
			field.Show_info(hero);
	}
	
	return 0;
}