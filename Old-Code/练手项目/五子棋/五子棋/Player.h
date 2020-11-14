#pragma once

#include "Chess.h"
#include "QiPan.h"

class Player
{
private:
	int type;
public:
	Player();
	Player(int type);
	void putChess(QiPan &qipan, int x, int y);
	~Player();
};