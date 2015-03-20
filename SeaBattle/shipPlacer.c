#include "field.h"

#include "shipPlacer.h"

int countShipCells() {
	return 0;
}
void placeShip_Cells(int);
check_possibility(int,int);

srand(time(NULL)); // Инициализируем генератор случайных чисел;

cord p;
int direction;

void placeShips() {
	if (FIELD_LENGTH >= 10)
	{	for (int i=1; i <= 1, i++)
		{
			placeShip_Cells(4); //ставит четырехпалубный
		}
		for (int i=1; i <= 2, i++)
		{
			placeShip_Cells(3);
		}
		for (int i=1; i <= 3, i++)
		{
			placeShip_Cells(2);
		}
		for (int i=1; i <= 4, i++)
		{
			placeShip_Cells(1);
		}
	}
	else if (FIELD_LENGTH = 8)
	{	for (int i=1; i <= 0, i++)
		{
			placeShip_Cells(4); //ставит четырехпалубный
		}
		for (int i=1; i <= 1, i++)
		{
			placeShip_Cells(3);
		}
		for (int i=1; i <= 2, i++)
		{
			placeShip_Cells(2);
		}
		for (int i=1; i <= 3, i++)
		{
			placeShip_Cells(1);
		}
	}
	else if (FIELD_LENGTH = 6)
	{	for (int i=1; i <= 0, i++)
		{
			placeShip_Cells(4); //ставит четырехпалубный
		}
		for (int i=1; i <= 0, i++)
		{
			placeShip_Cells(3);
		}
		for (int i=1; i <= 1, i++)
		{
			placeShip_Cells(2);
		}
		for (int i=1; i <= 2, i++)
		{
			placeShip_Cells(1);
		}
	}

}
void placeShip_Cells(int quanity){
	
	p.x = rand () %FIELD_LENGTH;
	p.y = rand () %FIELD_LENGTH;
	if (computerField[p.x][p.y] == 0)
		{
			direction = rand () %2; // если 0 то в направлении х, если 1 то в направлении y
			if (check_possibility(direction,quanity) == 1) //проверяем возможность размещения корабля
			{
				for (int i = 0; i <= (quanity-1); i++)
				{	if (direction  == 0)
						setShipCell(COMPUTER, p.x+i,(p.y));
					else if (direction  == 1)
						setShipCell(COMPUTER, p.x,(p.y+i));
					else 
					return 0;
				}
				return 1;
			}
			
		}
}
check_possibility(int dir,int qnt)
{
	//нужно написать проверялщика 
}
/*	setShipCell(COMPUTER, p.x,py);
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
