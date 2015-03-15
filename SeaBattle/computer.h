#ifndef COMPUTER_H
#define COMPUTER_H
#include "coord.h"
#include "stdio.h"



Coord hurtHit, previousHurtHit, c;			// Инициализируем структуру для хранения последнего успешного выстрела.

//Coord c;

Coord computerMove();
void tellComputerShipHurted();
void tellComputerShipKilled();
void tellComputerMissed();

#endif