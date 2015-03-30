#include "computer.h"
#include "coord.h"
#include "stdlib.h"
#include "stdio.h"

#define RAND_COORD_TEST_SAMPLES 100000

int checkValuesInField(int *array);
int checkRandomShoot();
int checkHurtedShoot();

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main(int argc, char const *argv[])
{
	printf("Check random shoot...");
	checkRandomShoot() ? printf("[Fail]\n") : printf("[OK]\n");
	printf("Check hurted shoot...");
	checkHurtedShoot() ? printf("[Fail]\n") : printf("[OK]\n");

	return 0;
}


int checkRandomShoot() { // check computer randomly shoot all field and always in field
	int xCoord[RAND_COORD_TEST_SAMPLES];
	int yCoord[RAND_COORD_TEST_SAMPLES];

	
	// make random shoots
	int i;
	for (i=0;i<RAND_COORD_TEST_SAMPLES;++i) {
		Coord c = computerMove();
		xCoord[i] = c.x;
		yCoord[i] = c.y;
	}

	int error = 0;

	qsort(xCoord, RAND_COORD_TEST_SAMPLES, sizeof(int), cmpfunc);
	error |= checkValuesInField(xCoord);

	qsort(yCoord, RAND_COORD_TEST_SAMPLES, sizeof(int), cmpfunc);
	error |= checkValuesInField(yCoord);

	return error;
}

int checkHurtedShoot() {

	int i;

	Coord lastCoord = computerMove();
	tellComputerShipHurted();
	Coord nextCoord = computerMove();

	if ((nextCoord.x == lastCoord.x && nextCoord.y == lastCoord.y+1) ||
		(nextCoord.x == lastCoord.x && nextCoord.y == lastCoord.y-1) || 
		(nextCoord.x == lastCoord.x+1 && nextCoord.y == lastCoord.y) ||
		(nextCoord.x == lastCoord.x-1 && nextCoord.y == lastCoord.y))
	{
	}
	else {
		return 1;
	}

	return 0;
}

int checkValuesInField(int *array) {

	// check that all values in field
	int i;
	int sampleCoord = 0;
	for (i=0;i<RAND_COORD_TEST_SAMPLES;++i) {

		if (array[i] == sampleCoord){
		}
		else if (array[i] == sampleCoord+1) {
			++sampleCoord;
		}
		else {
			return 1;
		}
	}

	// check last coord is a last coord in field
	if (array[RAND_COORD_TEST_SAMPLES-1] != (FIELD_LENGTH-1)) {
		return 1;
	}

	return 0;
}
