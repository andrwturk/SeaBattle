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

	/* game main cycle
	initField();
	placeShips();

	setPlayerName("Andrew");*/

	//Coord c;
	int test = 0;
	while (test != 55)
	{
		c = computerMove();
	
		printf("x = %d\t y = %d\n", c.x, c.y);

		printf("Legend:\n 0: shoot again\t 1: miss\t 2: hurt\t 3: killed\t 55: quit\n");
		
		scanf ("%d", &test);
		if (test == 1)
			tellComputerMissed();
		if (test == 2)
			tellComputerShipHurted();
		if (test == 3)
			tellComputerShipKilled();
	}
	

	//shoot(HUMAN, c.x, c.y);

	
	// to determine that Ship was killed, store last success computer move, than make another move.
	// if another move is empty cell --> ship was killed, so call tellComputerShipKilled()

	/*c = humanMove();
	CellType cell;
	cell = shoot(COMPUTER, c.x, c.y);	
	if (cell == SHIP_CELL) {
		// congratulate human
	}*/
	
	//printField();
}
