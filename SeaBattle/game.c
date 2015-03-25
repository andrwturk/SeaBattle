#include <stdio.h>
#include "field.h"
#include "shipPlacer.h"
#include "computer.h"
#include "human.h"
#include "coord.h"

#define NUMBER_OF_SHIPS 3

void gameMain();
void checkHumanMove();
int countAliveShipCell ();
void checkComputerMove();

CellType cell;
Coord c;

int computerShipKilled = 0;
//int humanShipKilled1 = 0;
int  humanShipKilled1 = 0;

int main(int argc, char const *argv[])
{
	gameMain();
	return 0;
}

void gameMain() // game entry point
{ 

	// game main cycle
	srand(time(NULL));
	
	initField();
	placeShips(HUMAN);
	placeShips(COMPUTER);

	setPlayerName("Andrew");

	

	printField();

	while (computerShipKilled < NUMBER_OF_SHIPS && humanShipKilled1 < NUMBER_OF_SHIPS)
	{
		//Первым ходит человек;
		c = humanMove();
		cell = shoot(COMPUTER, c.x, c.y);	
		checkHumanMove();

		//Вторым ходит компьютер;	
		c = computerMove();
		cell = shoot(HUMAN, c.x, c.y);
		checkComputerMove();

		printField();

		humanShipKilled1 = getKilledShips();
	}
	
	if (computerShipKilled == NUMBER_OF_SHIPS)
		printf("You won the game!\n");
	else
		printf("You lost the game! Try once again!\n");
}

void checkHumanMove()
{
	while (cell == CHECKED_CELL || cell == KILLED_SHIP_CELL || cell == SHIP_CELL)
	{
		
		if (cell == CHECKED_CELL || cell == KILLED_SHIP_CELL)
			printf("You've already shot in this cell. Please shoot again!\n");
		else
		{
			if (countAliveShipCell(COMPUTER) != 0) //если есть живые клетки корабля значит корабль ранен
				printf ("You've hurhed the ship! Shoot again!");
			else
			{
				printf("Congratulations! You've sunk the ship! Shoot again!\n"); //если нет живых клеток корабля - следственно корабль убит.
				computerShipKilled++;
			}
		}
		c = humanMove(); // Если игрок попал либо в стреляную точку либо в корабль - у игрока появляется дополнительный ход.
		cell = shoot(COMPUTER, c.x, c.y);
	}
	
	if (cell == EMPTY_CELL)
			printf("There is nothing!\n");
}


int countAliveShipCell (Player p) //ищем живые клетки корабля во всех направлениях, считаем их и выводим из функции.
{
	CellType tempCell = cell;
	int numberOFaliveShipCell = 0;
	int i;
	for (i = 1; (tempCell == SHIP_CELL || tempCell == KILLED_SHIP_CELL) && c.x - i >= 0; ++i)  //проходимся влево от точки
	{
		tempCell = check(p, (c.x - i), (c.y));
		if (tempCell == SHIP_CELL)
			numberOFaliveShipCell++;

	}
	tempCell = cell;
	for (i = 1; (tempCell == SHIP_CELL || tempCell == KILLED_SHIP_CELL) && c.x + i < FIELD_LENGTH -1; ++i) //проходимся вправо
	{
		tempCell = check(p, (c.x + i), (c.y));
		if (tempCell == SHIP_CELL)
			numberOFaliveShipCell++;

	}
	tempCell = cell;
	for (i = 1; (tempCell == SHIP_CELL || tempCell == KILLED_SHIP_CELL) && c.y - i >= 0; ++i) //проходимся вверх
	{
		tempCell = check(p, (c.x), (c.y - i));
		if (tempCell == SHIP_CELL)
			numberOFaliveShipCell++;

	}
	tempCell = cell;
	for (i = 1; (tempCell == SHIP_CELL || tempCell == KILLED_SHIP_CELL) && c.y + i < FIELD_LENGTH - 1; ++i) //проходимся вниз
	{
		tempCell = check(p, (c.x), (c.y + i));
		if (tempCell == SHIP_CELL)
			numberOFaliveShipCell++;

	}
	return numberOFaliveShipCell;
}

void checkComputerMove()
{
	while (cell == CHECKED_CELL || cell == KILLED_SHIP_CELL || cell == SHIP_CELL)
	{
		if (cell == SHIP_CELL)
		{
			if (countAliveShipCell(HUMAN) != 0) //если есть живые клетки корабля значит корабль ранен
				tellComputerShipHurted();
			else
				tellComputerShipKilled();
		}
		
		c = computerMove();					//Если коммп попал или стрельнул куда уже стрелял - даем ему стрельнуть еще разок.
		cell = shoot(HUMAN, c.x, c.y);
	}
	
	if (cell == EMPTY_CELL)
			tellComputerMissed();
}