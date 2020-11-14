#pragma once
#include "Chess.h"
class QiPan
{
private:
	int a[15][15];
	int winner;
	int size;
	
	bool check(int x, int y);
	bool check2(int *count);
public:
	QiPan();
	void putChess(Chess chess, int x, int y);
	bool win();
	string getStringWinner();
	
	~QiPan();
};