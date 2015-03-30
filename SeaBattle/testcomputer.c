#include "computer.h"
#include "human.h"
#include "coord.h"
#include <stdio.h>
int x, b = 0, a = 0,barcox = 0, barcoy = 0,outfield;
int countershoot [2];
int checkinfield(int); // Check if all coordinates go into the field
Coord c;

main()
{
    srand(time(NULL));



for (barcoy = 0; barcoy < 6 ; barcoy++ )// For checking the vertical form change parameters to 4
{


for (barcox = 0; barcox < 4 ; barcox++ )// For checking the vertical form change parameters to 6

    {

    for ( x = 0; x < 1000; x++ ) {

    computerMove();
    outfield = checkinfield (c.x);// Check if c.x is inside the field.
	if (outfield == 1)
	{
	printf("Coodinates out of field!!!!\n");
	break;}
	outfield = checkinfield (c.y);// Check if c.y is inside the field.
	if (outfield == 1)
	{
	printf("Coodinates out of field!!!!\n");
	break;}

    if( c.x == (barcox + a) && c.y == (barcoy )) // For checking the vertical form put (barcoy + a)
    {
    tellComputerShipHurted();
    printf("%d\n",c.x);
    printf("%d\n",c.y);
    countershoot[a]=x;
    a++;

    if(x > 300)
    {
    printf("Error. Too many shoots to try to kill one ship\n"); //
	break;
    }

    if (a > 2) //computerlogic has killed the ship
    {
    if ( (countershoot[2] - countershoot[1]) > 20 || (countershoot[1] - countershoot[0]) > 20 ) //Shoot should not be separated more than 20.
    {
	printf("Error. Too many shoots\n");
	printf("%d\n", (countershoot[1] - countershoot[0]) );
	break;
	}
    tellComputerShipKilled();
    b++;
    a = 0;
	break;
	}
    }
    else{
    tellComputerMissed();
    }
    }
    }
    }
printf("Ships killed %d\n",b);
}





int checkinfield (int a) {

	if ( a  <= -1 || a >= 6  )
	{ return 1;
    }
    else{
	return 0;
	}
	}
