#ifndef COMPUTER_H
#define COMPUTER_H
#include "coord.h"

int computerTurnNumber = 0; // инициализируем переменную для счета ходов компьютера;

int shipHurted = 0;		//Инициализируем переменные состояния кораблей;
int shipKilled = 0;

Сoord hurtHit, previousHurtHit;			// Инициализируем структуру для хранения последнего успешного выстрела.

srand(time(NULL)); // Инициализируем генератор случайных чисел;


Coord computerMove();
void tellComputerShipHurted();
void tellComputerShipKilled();
void tellComputerMissed();

#endif