#pragma once
#include "Board.h"
class Board;

class Block
{
	int NEXT[20];
	int x;
	int y;
	int type;
	int nexttype;
	Board* board;

	void init(int key, int dis[][4][4], int sou[][4]);

public:
	int shape[20][4][4];
	int getType() { return type; }
	int getNexttype() { return nexttype; }
	Block(Board* const board);
	void toNext();
	void moveRight();
	void moveLeft();
	void moveDown();
	void moveUp();
	bool detect(int );	//Åö×²¼ì²â;
	int getX() { return x; }
	int getY() { return y; }
	~Block();
};