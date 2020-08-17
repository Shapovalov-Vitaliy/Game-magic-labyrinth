#include <ctime>

#include "Character.h"
#include "Field.h"

using namespace std;

int main()
{
	srand(time(NULL));

	Character hero;
	Field field(hero);
	field.Show_info(hero);

	while (!hero.Die())
	{
		if (field.Update(hero))
			field.Victory();
		else
			field.Show_info(hero);
	}

	return 0;
}