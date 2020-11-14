#include "Block.h"
#include <ctime>
#include <cstdlib>

void Block::init(int key, int dis[][4][4], int sou[][4]) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			dis[key][i][j] = sou[i][j];
		}
	}
}

Block::Block(Board* const board) {

	//初始化 方块数据
	int s0[4][4] = {
	0,0,0,0,
	1,1,1,1,
	0,0,0,0,
	0,0,0,0
	};
	int s1[4][4] = {
	0,1,0,0,
	0,1,0,0,
	0,1,0,0,
	0,1,0,0
	};
	int s2[4][4] = {
	0,0,0,0,
	1,0,0,0,
	1,1,1,0,
	0,0,0,0
	};
	int s3[4][4] = {
	0,0,0,0,
	0,0,1,0,
	0,0,1,0,
	0,1,1,0
	};
	int s4[4][4] = {
	0,0,0,0,
	0,1,1,1,
	0,0,0,1,
	0,0,0,0
	};
	int s5[4][4] = {
	0,1,1,0,
	0,1,0,0,
	0,1,0,0,
	0,0,0,0
	};
	int s6[4][4] = {
	0,0,0,0,
	0,0,0,1,
	0,1,1,1,
	0,0,0,0
	};
	int s7[4][4] = {
	0,0,1,1,
	0,0,0,1,
	0,0,0,1,
	0,0,0,0
	};
	int s8[4][4] = {
	0,1,1,1,
	0,1,0,0,
	0,0,0,0,
	0,0,0,0
	};
	int s9[4][4] = {
	0,1,0,0,
	0,1,0,0,
	0,1,1,0,
	0,0,0,0
	};
	int s10[4][4] = {
	0,0,0,0,
	0,1,1,0,
	0,1,1,0,
	0,0,0,0
	};
	int s11[4][4] = {
	0,0,0,0,
	0,0,1,1,
	0,1,1,0,
	0,0,0,0
	};
	int s12[4][4] = {
	0,0,0,0,
	0,1,0,0,
	0,1,1,0,
	0,0,1,0
	};
	int s13[4][4] = {
	0,0,0,0,
	0,1,0,0,
	1,1,1,0,
	0,0,0,0
	};
	int s14[4][4] = {
	0,0,0,0,
	0,0,1,0,
	0,1,1,0,
	0,0,1,0
	};
	int s15[4][4] = {
	0,0,0,0,
	1,1,1,0,
	0,1,0,0,
	0,0,0,0
	};
	int s16[4][4] = {
	0,0,0,0,
	0,1,0,0,
	0,1,1,0,
	0,1,0,0
	};
	int s17[4][4] = {
	0,0,0,0,
	1,1,0,0,
	0,1,1,0,
	0,0,0,0
	};
	int s18[4][4] = {
	0,0,0,0,
	0,0,1,0,
	0,1,1,0,
	0,1,0,0
	};
	init(0, shape, s0);
	init(1, shape, s1);
	init(2, shape, s2);
	init(3, shape, s3);
	init(4, shape, s4);
	init(5, shape, s5);
	init(6, shape, s6);
	init(7, shape, s7);
	init(8, shape, s8);
	init(9, shape, s9);
	init(10, shape, s10);
	init(11, shape, s11);
	init(12, shape, s12);
	init(13, shape, s13);
	init(14, shape, s14);
	init(15, shape, s15);
	init(16, shape, s16);
	init(17, shape, s17);
	init(18, shape, s18);
	//------------------------------------

	//初始化 每个方块逆时针旋转后所得方块的id
	NEXT[0] = 1;
	NEXT[1] = 0;

	NEXT[2] = 3;
	NEXT[3] = 4;
	NEXT[4] = 5;
	NEXT[5] = 2;

	NEXT[6] = 7;
	NEXT[7] = 8;
	NEXT[8] = 9;
	NEXT[9] = 6;

	NEXT[10] = 10;

	NEXT[11] = 12;
	NEXT[12] = 11;

	NEXT[13] = 14;
	NEXT[14] = 15;
	NEXT[15] = 16;
	NEXT[16] = 13;

	NEXT[17] = 18;
	NEXT[18] = 17;

	//------------------------------

	//初始化 下落起点
	x = -3;
	y = 4;

	//------------------------------

	//初始化 该方块的类型和下一方块的类型
	srand((unsigned)time(0));
	type = rand() % 19;
	nexttype = rand() % 19;
	/*type = 0;
	nexttype = 0;*/
	this->board = board;
}

void Block::toNext()
{
	x = -3;
	y = 4;
	type = nexttype;
	nexttype = rand() % 19;
	/*nexttype = 0;*/

}

void Block::moveRight()
{
	if (detect(3)) {
		y++;
	}
}

void Block::moveLeft()
{
	if (detect(2)) {
		y--;
	}
}

void Block::moveDown()
{
	if (detect(1)) {
		x++;
	}
}

void Block::moveUp()
{
	if (detect(0))
		type = NEXT[type];
}

bool Block::detect(int flag)
{
	int nextX, nextY;
	int tp = type;
	switch (flag)
	{
	case 0:
		nextX = x;	nextY = y; tp = NEXT[type]; break; //原地转
	case 1:
		nextX = x + 1;	nextY = y;	break;	//下
	case 2:
		nextX = x;	nextY = y - 1;  break;	//左
	case 3:
		nextX = x; nextY = y + 1;   break;	//右
	default:
		break;
	}
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int tx = nextX + i;
			int ty = nextY + j;
			if (shape[tp][i][j] == 0)
				continue;
			if (tx < -3 || tx >= board->getHeight() || ty < 0 || ty >= board->getWeight()) {
				return false;
			}	//可行区域扩展到地图上方 3 格
			if (tx >= 0 && tx < board->getHeight() && ty >= 0 && ty < board->getWeight()){
				if (board->map[tx][ty] != 0)
					return false;
			}
		}
	}
	return true;
}

Block::~Block()
{
}
