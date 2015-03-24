#include <stdio.h>
#include "computer.h"
#include "coord.h"


Coord hurtHit, previousHurtHit, c;			// Инициализируем структуру для хранения последнего успешного выстрела.

int computerTurnNumber = 0; // инициализируем переменную для счета ходов компьютера;

int shipHurted = 0;		//Инициализируем переменные состояния кораблей;
int humanShipKilled = 0;



Coord computerMove() {

//srand(time(NULL)); // Инициализируем генератор случайных чисел;
			
	if (shipHurted == 0) // рандомный пиу-пиу если прошлый выстрел был мимо;
	{
		c.x = rand () %FIELD_LENGTH;
		c.y = rand () %FIELD_LENGTH;
	}

	if (shipHurted == 1 ) // Если прошлый вестрел ранил копабль стреляем рядышком
	{
		int xORy = rand () %2; //Рандомно выбираем куда сдвигаться после успешного попадания. По оси "x" (xORy=0) или по оси "y" (xORy=1);
		
		int shootVariants [2] = {-1, 1}; //Масив вариантов для выстрела (исключаем стрельбу в то же место)
		
		if (xORy == 0)
		{
			c.y = hurtHit.y;
			if (hurtHit.x == 0)		//Если поле находится в начале - всегда стреляем правее;
				c.x = hurtHit.x + 1;
			else if (hurtHit.x == FIELD_LENGTH - 1)		//Если поле находится в конце - всегда стреляем левее;
				c.x = hurtHit.x - 1;
			else
				c.x = hurtHit.x + shootVariants [rand () %2]; //Стреляем по оси "x"	
		}
		if (xORy == 1)
		{
			c.x = hurtHit.x;
			if (hurtHit.y == 0)		//Если поле находится в начале - всегда стреляем ниже;
				c.y = hurtHit.y + 1;
			else if (hurtHit.y == FIELD_LENGTH - 1)		//Если поле находится в конце - всегда стреляем выше;
				c.y = hurtHit.y - 1;
			else
				c.y = hurtHit.y + shootVariants [rand () %2];	//стреляем по оси "y"	
		}
		
	}

	if (shipHurted > 1) //Логика вычисления третьего и дальнейших выстрелов;
	{
		if (hurtHit.x == previousHurtHit.x) //Если координаты по "x" двух выстрелов совпадают - меняем координату "y"
		{
			c.x = hurtHit.x;
			if (hurtHit.y > previousHurtHit.y)
			{
				if (hurtHit.y == FIELD_LENGTH - 1)
					c.y = hurtHit.y - shipHurted;
				else if (hurtHit.y < shipHurted)		//можно проверку сделать путем (previousHurtHit.y == 0) нужно подумать как лучше
					c.y = hurtHit.y + 1;		//если предыдущий выстрел был возле границы - стреляем всегда ввниз;
				else
				{
					int shootVariants [2] = {-shipHurted, 1};
					c.y = hurtHit.y + shootVariants [rand () %2];  //стреляем или вниз на 1 ячейку или вверх на shipHurted ячеек;
				}
			}
			if (hurtHit.y < previousHurtHit.y)
			{
				if (hurtHit.y == 0)
					c.y = hurtHit.y + shipHurted;
				else if (hurtHit.y < shipHurted)		//можно проверку сделать путем (previousHurtHit.y == FIELD_LENGTH - 1) нужно подумать как лучше
					c.y = hurtHit.y - 1;		//если предыдущий выстрел был возле границы - стреляем всегда вверх;
				else
				{
					int shootVariants [2] = {shipHurted, -1};
					c.y = hurtHit.y + shootVariants [rand () %2];  //стреляем или вверх на 1 ячейку или вниз на shipHurted ячеек;
				}
			}
		}
		
		if (hurtHit.y == previousHurtHit.y) //Если координаты по "y" двух выстрелов совпадают - меняем координату "x"
		{
			c.y = hurtHit.y;
			if (hurtHit.x > previousHurtHit.x)
			{
				if (hurtHit.x == FIELD_LENGTH - 1)
					c.x = hurtHit.x - shipHurted;
				else if (hurtHit.x < shipHurted)		//можно проверку сделать путем (previousHurtHit.x == 0) нужно подумать как лучше
					c.x = hurtHit.x + 1;		//если предыдущий выстрел был возле границы - стреляем всегда ввправо;
				else
				{
					int shootVariants [2] = {-shipHurted, 1};
					c.x = hurtHit.x + shootVariants [rand () %2];  //стреляем или вправо на 1 ячейку или влево на shipHurted ячеек;
				}
			}
			if (hurtHit.x < previousHurtHit.x)
			{
				if (hurtHit.x == 0)
					c.x = hurtHit.x + shipHurted;
				else if (hurtHit.x < shipHurted)		//можно проверку сделать путем (previousHurtHit.x == FIELD_LENGTH - 1) нужно подумать как лучше
					c.x = hurtHit.x - 1;		//если предыдущий выстрел был возле границы - стреляем всегда влево;
				else
				{
					int shootVariants [2] = {shipHurted, -1};
					c.x = hurtHit.x + shootVariants [rand () %2];  //стреляем или влево на 1 ячейку или вправо на shipHurted ячеек;
				}
			}
		}
	}

	/*Coord c; 

	c.x = 0;			Я хз зачем это было здесь ;)
	c.y = 0; */
	
	

	return c;

}

void tellComputerShipKilled() 
{

	shipHurted = 0;  //обнуляем флаг подбитого корабля;
	++humanShipKilled;
	
	computerTurnNumber++; // считаем количество ходов;

	printf("Yo-ho-ho and a bottle of rum! I've sunk your ship!\n");
	
}

void tellComputerShipHurted() 
{
	
	++shipHurted;
	
	if (shipHurted == 1)
		hurtHit = c;	//сохраняем состояние последнего выстрела;
		
	if (shipHurted > 1)
	{
		previousHurtHit = hurtHit;
		hurtHit = c;
	}

	computerTurnNumber++; // считаем количество ходов;

	printf("Prepare for swimming!\n");
}

void tellComputerMissed()
{
	computerTurnNumber++; // считаем количество ходов;
}


int getKilledShips()
{
	return humanShipKilled;
}