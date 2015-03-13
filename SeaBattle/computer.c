#include "computer.h"
#include "field.h"



Coord computerMove() {

	/*Нужно дописать:
	1) Алгоритм сравнения рандомной точки с историей выстрелов (чтобы не стрелять по несколько раз в одну и ту же точку)*/

	computerTurnNumber++; // считаем количество ходов;
	
	if (shipHurted == 0) // рандомный пиу-пиу если прошлый выстрел был мимо;
	{
		c.x = rand () %FIELD_LENGTH;
		c.y = rand () %FIELD_LENGTH;
	}


	if (shipHurted == 1 ) // Если прошлый вестрел ранил копабль стреляем рядышком
	{
		/* Нужно еще дописать:
		1) алгоритм стрельбы по краям карты
		2) алгоритм препятствующий стрелянию в ту же точку (как-то исключить 1 из рандома)*/
		int xORy = rand () %2; //Рандомно выбираем куда сдвигаться после успешного попадания. По оси "x" или по оси "y";
		
		if (xORy == 0)
		{
			c.x = lasthit.x - 1 + rand () %3; //Стреляем по оси "x"
			c.y = lasthit.y;
		}
		else
		{
			c.x = lasthit.x;
			c.y = lasthit.y - 1 + rand () %3;	//стреляем по оси "y"
		}
		
	}

	/*Coord c; 

	c.x = 0;			Я хз зачем это было здесь ;)
	c.y = 0; */
	
	lasthit.x = c.x;	//сохраняем состояние последнего выстрела;
	lasthit.y = c.y;

	return c;

}

void tellComputerShipKilled() {

	shipHurted = 0;
	++shipKilled;
}

void tellComputerShipHurted() {
	
	++shipHurted;

}