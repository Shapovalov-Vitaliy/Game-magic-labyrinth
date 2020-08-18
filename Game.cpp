#include <ctime>

#include "Character.h"
#include "Field.h"

int main()
{
	srand(time(NULL));

	/* Init generation */
	Character hero;
	Field field(hero);
	field.Show_info(hero);

	/* Main cycle */
	while (!hero.Die())
	{
		if (field.Update(hero))
			field.Victory();
		else
			field.Show_info(hero);
	}
	
	return 0;
}