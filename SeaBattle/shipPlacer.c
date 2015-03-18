#include "field.h"

#include "shipPlacer.h"

int countShipCells() {
	return 0;
}

void placeShips() {
	placeShips_4_Cells(); //разставляет четырех палубные
	placeShips_3_Cells(); //разставляет трьохпалубные
	placeShips_2_Cells(); //разставляет двухпалубные
	placeShips_1_Cells(); //разставляет однопалубные
}
/*	setShipCell(HUMAN, 0,1);
	setShipCell(HUMAN, 3,3);
	setShipCell(HUMAN, 4,3);
	setShipCell(HUMAN, 5,3);
	setShipCell(HUMAN, 1,2);
	setShipCell(HUMAN, 2,2);
	setShipCell(HUMAN, 3,2);
	setShipCell(HUMAN, 5,5);
	setShipCell(HUMAN, 4,5);
	setShipCell(HUMAN, 0,5);
	setShipCell(HUMAN, 3,0);
	setShipCell(HUMAN, 4,0);
	setShipCell(HUMAN, 5,0);
*/
