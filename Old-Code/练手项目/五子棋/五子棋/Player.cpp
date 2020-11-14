#include "Player.h"


Player::Player()
{
}

Player::Player(int type) //type == 1 代表黑棋棋手， type == 2 代表白棋棋手
{
	this->type = type;
}

void Player::putChess(QiPan &qipan, int x, int y)
{
	Chess chess(type);
	qipan.putChess(chess, x, y);
}

Player::~Player()
{
}
