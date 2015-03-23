#ifndef COMPUTER_H
#define COMPUTER_H
#include "coord.h"
#include "stdio.h"


int humanShipKilled = 0;


//Coord c;

Coord computerMove();
void tellComputerShipHurted();
void tellComputerShipKilled();
void tellComputerMissed();

#endif