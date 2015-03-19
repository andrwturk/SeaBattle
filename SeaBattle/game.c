#include "field.h"
#include "shipPlacer.h"
#include "computer.h"
#include "human.h"
#include "coord.h"

void gameMain();

int main(int argc, char const *argv[])
{
	gameMain();
	return 0;
}

void gameMain() { // game entry point

	// game main cycle

	
	initField();
	placeShips();

	setPlayerName("Andrew");

	Coord c;

	printField();

	//Первым ходит человек;

	c = humanMove();

	CellType cell;
	cell = shoot(COMPUTER, c.x, c.y);	
	
	if (cell == CHECKED_CELL)
	{
		printf("You've already shot in this cell\n");
	}


	if (cell == SHIP_CELL) 
	{
		printf("Good job! You've hurted the ship!\n");
	}
	


	
	c = computerMove();
	shoot(HUMAN, c.x, c.y);

	
	// to determine that Ship was killed, store last success computer move, than make another move.
	// if another move is empty cell --> ship was killed, so call tellComputerShipKilled()

	
	
	
	
}
