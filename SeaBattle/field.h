#ifndef FIELD_H
#define FIELD_H

#define FIELD_LENGTH 6

// public types
typedef enum {
	COMPUTER = 0,
	HUMAN
}Player;

typedef enum {
	EMPTY_CELL = 0,
	CHECKED_CELL,
	SHIP_CELL,
	KILLED_SHIP_CELL,
	UNKNOWN_CELL_TYPE // generally means something wrong
}CellType;

// public methods
void setPlayerName(char* name);

// check cell
CellType check(Player p, int x, int y);
CellType shoot(Player p, int x, int y);
void setShipCell(Player p, int x, int y);
void initField();
void printField();
void emptyField();

#endif