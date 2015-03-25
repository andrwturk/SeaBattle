#include "coord.h"
#include "human.h"


Coord humanMove() 
{
	int x_cord; 	//Перемееная для хранения введеной координаты пользователем по x
	int y_cord; 	//Перемееная для хранения введеной координаты пользователем по y
	int confirm;    //Переменная для проверки ответа пользователя на вопрос подтверждения ввода координат
	Coord c;	//Инициализация структуры введеных пользователем координат 
	Start:		//Точка старта ввода координат (нужна для безусловного перехода в случае если пользователь хочет ввечти координаты снова)
	printf("Enter a coordinate on the Y axis (from 1 to %d)\n",FIELD_LENGTH);
	Start_Y:	//Точка ввода координаты по оси Y (нужна для безусловного перехода, в случае ошибочного ввода координаты по оси Y)
	scanf("%d",&c.y);
	y_cord = c.y;   //Сохраняем координату Y введеную пользователем (нужно потому, как вводимые координаты не совпадают с координатами обрабатываемыми)
	c.y -=1;	//Приводим координату по Y к рабочему виду (первое поле по Y начинается с 1 а работаем мы с 0 )
	if (c.y < 0 || c.y > (FIELD_LENGTH-1)) //Первоначальная проверка на то, что что координата находится в пределах координат (размера) поля 
	{
	//	system("cls");     	       //Очистка экрана
		printf("\nIncorrect axis coordinate (coordinate should be in the range of from 1 to %d)\nEnter the coordinate of Y axis again\n\n",FIELD_LENGTH);
		fflush(stdin);		       //Очистка буффера ввода
		c.y = -1;		       //Присваем координату кторая заведомо не входит в пределы поля 
		goto Start_Y;		       //Безусловный переход в точку ввода координаты Y
	}
	fflush(stdin);			       //Очистка буффера ввода
	printf("Enter a coordinate on the X axis (from a to %c)\n", ('a'+FIELD_LENGTH-1));
	Start_X:	//Точка ввода координаты по оси X (нужна для безусловного перехода, в случае ошибочного ввода координаты по оси X)
	c.x = getchar();
	x_cord = c.x;	//Сохраняем координату X введеную пользователем (нужно потому, как вводимые координаты не совпадают с координатами обрабатываемыми)
	if ( x_cord >= 'A' && x_cord <='Z' && (c.x-'A') <= (FIELD_LENGTH-1))	    //Проверка и преобразование буквенной координаты в рабочую и проверка на вхождение в поле
	{
		c.x -= 'A';
	}
	else if ( x_cord >= 'a' && x_cord <='z' && (c.x-'a') <= (FIELD_LENGTH-1))  //Проверка и преобразование буквенной координаты в рабочую и проверка на вхождение в поле
	{
		c.x -= 'a';
	}	
	else if(c.x > LAST_ACSII)		  //Проверка раскладки клавиатуры, если введеный символ выходит за пределы стандртной таблицы символов ACSII значит язык раскладки клавиатуры не английский
	{
	//	system("cls");			  //Очистка экрана
		printf("\nIncorrect axis coordinate (Switch the keyboard layout into ENGLISH)\nEnter the coordinate of X axis again\n\n");
		fflush(stdin);			  //Очистка буффера ввода
		goto Start_X;			  //Безусловный переход в точку ввода координаты X
	}
	else 					  // если введеная координата не попала в диапазон заглавных(строчных) анг букв, если не вышла за предел ASCII, то введено что-то явно не похожее на координату
	{
	//	system("cls");			  //Очистка экрана
		printf("\nIncorrect axis coordinate (coordinate should be in the range of from a to %d)\nEnter the coordinate of X axis again\n\n",('a'+FIELD_LENGTH-1));
		fflush(stdin);			  //Очистка буффера ввода
		goto Start_X;			  //Безусловный переход в точку ввода координаты X
	}
			

	//system("cls");				  //Очистка экрана
	fflush(stdin);				  //Очистка буффера ввода
	Answer:					  //Точка ввода вопроса про подтверждения введеных координат
	printf("You Enter such cordinate :\n Y = %d\n X = %c\n Please enter\n - y if you confirm cordinatesor \n - n if you want enter cordinates again\n ",y_cord,x_cord);
	confirm = getchar();
	if (confirm == 'y' || confirm == 'Y')	  //Если введено Y(Да), возвращаем координаты в место вызова функции
	{	
		return c;
	}
			
	else if (confirm == 'n' || confirm == 'N')	//Если введено N(Нет), возвращаемся к вводу координат, безусловным переходом предварительно изменив координаты на заведомо ошибочные 
	{
	//	system("cls");
		c.x = -1;
		c.y = -1;
		goto Start;
	}
	else 						//Если введено что либо другое, возвращаемся к вопросу
	{
	//	system("cls");
		printf ("You write wrong answer, please repeat your choise");
		goto Answer;
	}
}

