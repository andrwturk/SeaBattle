#include "coord.h"
#include "human.h"


Coord humanMove() {
	int x_letter;
	int confirm;
	Coord c;
	Start:
	printf("Enter a coordinate on the Y axis (from 1 to 6)\n");
	Start_Y:
	scanf("%d",&c.y);
	if (c.y < 1 || c.y > 6){
			system("cls");
			printf("\nIncorrect axis coordinate (coordinate should be in the range of from 1 to 6)\nEnter the coordinate of Y axis again\n\n");
			goto Start_Y;
	}
	fflush(stdin);
	printf("Enter a coordinate on the X axis (from a to f)\n");
	Start_X:
	c.x = getchar();
	x_letter = c.x;
	switch (c.x){
		case 'A':
			c.x = 1;
			break;
		case 'B':
			c.x = 2;
			break;
		case 'C':
			c.x = 3;
			break;
		case 'D':
			c.x = 4;
			break;
		case 'E':
			c.x = 5;
			break;
		case 'F':
			c.x = 6;
			break;
		case 'a':
			c.x = 1;
			break;
		case 'b':
			c.x = 2;
			break;
		case 'c':
			c.x = 3;
			break;
		case 'd':
			c.x = 4;
			break;
		case 'e':
			c.x = 5;
			break;
		case 'f':
			c.x = 6;
			break;
			
			}
			
	if (c.x < 1 || c.x > 6){
		if(c.x > 127)
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
			
	}
		system("cls");
		fflush(stdin);
		Answer:
		printf("You Enter such cordinate :\n Y = %d\n X = %c\n Please enter\n - y if you confirm cordinatesor \n - n if you want enter cordinates again\n ",c.y,x_letter);
		confirm = getchar();
		if (confirm == 'y' || confirm == 'Y')
			return c;
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
