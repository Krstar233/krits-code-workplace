#include "Board.h"
#include <algorithm>
#include <iostream>

Board::Board()
{
}

Board::Board(int weight, int height)
{
	this->weight = weight;
	this->height = height;
	score = 0;
	maxscore = 0;
	downTime = 1000;
	block = new Block(this);
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++) {
			map[i][j] = 0;
		}
	}
}

void Board::confirm()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int tx = block->getX() + i;
			int ty = block->getY() + j;
			
			if (tx < 0 || tx >= height || ty < 0 || ty >= weight)
				continue;

			if (block->shape[block->getType()][i][j] != 0)
				map[tx][ty] = block->shape[block->getType()][i][j];
		}
	}

	int cnt = 0;

	for (int i = height - 1; i >= 0; i--) {
		bool flag = false;
		for (int j = 0; j < weight; j++) {
			if (map[i][j] == 0) {
				flag = true;
				break;
			}
		}
		if (flag)
			continue;

		cnt++;

		for (int j = i; j >= 0; j--) {
			for (int k = 0; k < weight; k++) {
				if (j != 0) {
					/*std::cout << "*";*/
					map[j][k] = map[j - 1][k];
				}
				else
					map[j][k] = 0;
			}
		}
		i++;
	}

	score += 5;

	if (cnt) {
		score += 10 * (1 << cnt);
	}

	maxscore = std::max(maxscore, score);
	if (downTime > 800) {
		downTime -= 20;
	}
	else if (downTime > 400) {
		downTime -= downTime*0.1;
	}

	block->toNext();
}

bool Board::isEnd()
{
	if (!block->detect(1)) {
		if (block->getX() < 0) {	
			/*std::cout << "END!!" << std::endl;*/
			return true;
		}//¿ÉÄÜ³ö bug
	}
	return false;
}

Board::~Board()
{
}
