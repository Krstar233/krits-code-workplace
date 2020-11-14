#pragma once
#include "Block.h"
class Block;

class Board
{
	int score;
	int maxscore;
	int downTime;
	int weight;
	int height;
	
public:
	int map[100][100];
	Block *block;

	Board();
	Board(int weight, int height);
	void confirm();
	bool isEnd();
	int getHeight() { return height; }
	int getWeight() { return weight; }
	int getTime() { return downTime; }
	int getScore() { return score; }
	~Board();
};

