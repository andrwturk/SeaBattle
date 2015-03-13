#ifndef COMPUTER_H
#define COMPUTER_H
#include "coord.h"

int computerTurnNumber = 0; // инициализируем переменную для счета ходов компьютера;

int computerMemoryArray [FIELD_LENGTH][FIELD_LENGTH];

int ixComputer, iyComputer;
for (int ixComputer = 0; ixComputer < FIELD_LENGTH; ++ixComputer)  // Заполняем масив пустыми клетками
{
	for (int iyComputer = 0; iyComputer < FIELD_LENGTH; ++iyComputer)
	{
		computerMemoryArray [ixComputer][iyComputer] = EMPTY_CELL;
	}
}

int shipHurted = 0;		//Инициализируем переменные состояния кораблей;
int shipKilled = 0;

coord lasthit;

srand(time(NULL)); // Инициализируем генератор случайных чисел;


Coord computerMove();
void tellComputerShipHurted();
void tellComputerShipKilled();
void tellComputerMissed();

#endif