#include "coord.h"
#include "human.h"


Coord humanMove() 
{
	int x_cord;
	int y_cord;
	int confirm;
	Coord c;
	Start:
	printf("Enter a coordinate on the Y axis (from 1 to 6)\n");
	Start_Y:
	scanf("%d",&c.y);
	y_cord = c.y;
	c.y -=1;
	if (c.y < 0 || c.y > (FIELD_LENGTH-1))
	{
		system("cls");
		printf("\nIncorrect axis coordinate (coordinate should be in the range of from 1 to 6)\nEnter the coordinate of Y axis again\n\n");
		fflush(stdin);
		c.y = -1;
		goto Start_Y;
	}
	fflush(stdin);
	printf("Enter a coordinate on the X axis (from a to f)\n");
	Start_X:
	c.x = getchar();
	x_cord = c.x;
	if ( x_cord >= 'A' && x_cord <='Z' )
	{
		c.x -= 'A';
	}
	else if ( x_cord >= 'a' && x_cord <='z' )
	{
		c.x -= 'a';
	}	
	else if(c.x > LAST_ACSII)
	{
		system("cls");
		printf("\nIncorrect axis coordinate (Switch the keyboard layout into ENGLISH)\nEnter the coordinate of X axis again\n\n");
		fflush(stdin);
		goto Start_X;
	}
	else 
	{
		system("cls");
		printf("\nIncorrect axis coordinate (coordinate should be in the range of from a to f)\nEnter the coordinate of X axis again\n\n");
		fflush(stdin);
		goto Start_X;
	}
			

	system("cls");
	fflush(stdin);
	Answer:
	printf("You Enter such cordinate :\n Y = %d\n X = %c\n Please enter\n - y if you confirm cordinatesor \n - n if you want enter cordinates again\n ",y_cord,x_cord);
	confirm = getchar();
	if (confirm == 'y' || confirm == 'Y')
	{	
		return c;
	}
			
	else if (confirm == 'n' || confirm == 'N')
	{
		system("cls");
		goto Start;
	}
	else 
	{
		system("cls");
		printf ("You write wrong answer, please repeat your choise");
		goto Answer;
	}
}

