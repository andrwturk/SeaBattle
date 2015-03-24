#include <stdio.h>
#include "field.h"
#include "coord.h"
#include "shipPlacer.h"
#define TRUE 1
#define FALSE 0

int countShipCells() {
	return 0;
}

int is_possibility();
void setShipCell();

int direction;
Coord c;
int i,j;

void placeShips(Player p) 
{
	
//srand(time(NULL));
int a;	
	
	
	if (FIELD_LENGTH >= 10)
	{	for (a=1; a <= 1; a++)
		{
			while (placeShip_Cells(p,4) !=1 );
			//print_computer ();		
		}
		for (a=1; a <= 2; a++)
		{
			while (placeShip_Cells(p,3) !=1 );
			//print_computer ();	
		}
		for (a=1; a <= 3; a++)
		{
			while (placeShip_Cells(p,2) !=1 );
			//print_computer ();	
		}
		for (a=1; a <= 4; a++)
		{
			while (placeShip_Cells(p,1) !=1 );
			//print_computer ();	
		}

	}	
	else if (FIELD_LENGTH == 8)
	{	
		for (a=1; a <= 1; a++)
		{
			while (placeShip_Cells(p,3) !=1 ); 
		}
		for (a=1; a <= 2; a++)
		{
			while (placeShip_Cells(p,2) !=1 ); 
		}
		for (a=1; a <= 3; a++)
		{
			while (placeShip_Cells(p,1) !=1 ); 
		}

	}	
	else if (FIELD_LENGTH == 6)
	{	
		for (a=1; a <= 1; a++)
		{
			while (placeShip_Cells(p,2) !=1 );
		}
		for (a=1; a <= 2; a++)
		{
			while (placeShip_Cells(p,1) !=1 );
		}

	}

}
int placeShip_Cells(Player p,int quanity)
{	
	c.x = rand () % FIELD_LENGTH;
	c.y = rand () % FIELD_LENGTH;
	direction = rand () % 2;
	//printf ("c.x=%d  c.y=%d  direction=%d\n\n",c.x,c.y,direction);
	//printf ("possibility = %d quanity= %d\n",is_possibility(p,direction,quanity,c),quanity);
		if (is_possibility(p,direction,quanity,c) == TRUE)
		{
			for (i = 0; i <= (quanity-1); i++)
				{	if (direction  == 0)
						setShipCell(p, c.x+i,(c.y));
					else if (direction  == 1)
						setShipCell(p, c.x,(c.y+i));
					else return 0;
				}
				return 1;
		}
		else return 0;		
}
		

int is_possibility(Player p,int dir,int qnt,Coord c)
{
if(qnt == 1 )
{	
	int y_start = -1;
	int x_start = -1;
	int y_finish = 1;
	int x_finish = 1;
	
	if (c.x == 0)
		x_start = c.x;
	else if (c.x == (FIELD_LENGTH-1))
		x_finish = 0;
	if (c.y == 0)
		y_start = c.y;
	else if (c.y == (FIELD_LENGTH-1))
		y_finish = 0;
	
			for (j =y_start; j<=y_finish; j++)
			{
				for (i=x_start; i<=x_finish; i++)
				{
					if(check(p,(c.x+i),(c.y+j)) == SHIP_CELL)
						return 0;
				}
			}
}


else if (dir == 0)
	{
		int y_start = -1;
		int x_start = -1;
		int y_finish = 1;
		int x_finish = qnt;
		
		if (c.x == 0)
			x_start = c.x;
		if ((c.x+qnt) == (FIELD_LENGTH-1))
			x_finish = (qnt-1);
		if (c.y == 0)
			y_start = c.y;
		if (c.y == (FIELD_LENGTH-1))
			y_finish = 0;
		
		if( (c.x+qnt) <= (FIELD_LENGTH-1) )
		{
			for (j =y_start; j<=y_finish; j++)
			{
				for (i=x_start; i<=x_finish; i++)
				{
					if(check(p,(c.x+i),(c.y+j)) == SHIP_CELL)
						return 0;
				}
			}
			
		}
		else return 0;
	}
	else if (dir == 1)
	{
		int y_start = -1;
		int x_start = -1;
		int y_finish = qnt;
		int x_finish = 1;
		
		if (c.x == 0)
			x_start = c.x;
		if (c.x == (FIELD_LENGTH-1))
			x_finish = 0;
		if (c.y == 0)
			y_start = c.y;
		if ((c.y+qnt) == (FIELD_LENGTH-1))
			y_finish = (qnt-1);
		
		if( (c.y+qnt) <= (FIELD_LENGTH-1) )
		{
			for (i =x_start; i<=x_finish; i++)
			{
				for (j=y_start; j<=y_finish; j++)
				{
					if(check(p,(c.x+i),(c.y+j)) == SHIP_CELL)
						return 0;
				}
			}
			
		}
		else return 0;
	}
	return 1;
}
