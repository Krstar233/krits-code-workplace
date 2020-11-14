#include "QiPan.h"

bool QiPan::check2(int *count) {
	if (count[0] >= 5) {
		this->winner = 1;
		return true;
	}
	if (count[1] >= 5) {
		this->winner = 2;
		return true;
	}
}
bool QiPan::check(int x, int y)
{
	int count[2] = { 0 };

	//竖直方向判断是否有五子连珠
	for (int i = 0; i < size; i++) {
		if (a[i][y] == 1) {
			count[0]++;
		}
		else count[0] = 0;
		if (a[i][y] == 2) {
			count[2]++;
		}
		else count[1] = 0;
	}
	if (check2(count))
		return true;
	count[0] = count[1] = 0;

	//水平方向
	for (int j = 0; j < size; j++) {
		if (a[x][j] == 1) {
			count[0]++;
		}
		else count[0] = 0;
		if (a[x][j] == 2) {
			count[2]++;
		}
		else count[1] = 0;
	}
	if (check2(count))
		return true;
	count[0] = count[1] = 0;

	//斜向下
	int i_key = x, j_key = y;
	for (; i_key != 0 && j_key != 0; i_key--, j_key--);
	for (; i_key < size && j_key < size; i_key++, j_key++) {
		if (a[i_key][j_key] == 1) {
			count[0]++;
		}
		else count[0] = 0;
		if (a[i_key][j_key] == 2) {
			count[2]++;
		}
		else count[1] = 0;
	}
	if (check2(count))
		return true;
	count[0] = count[1] = 0;

	//斜向上
	int i_key = x, j_key = y;
	for (; i_key != 0 && j_key < size; i_key--, j_key++);
	for (; i_key < size && j_key >= 0; i_key++, j_key--) {
		if (a[i_key][j_key] == 1) {
			count[0]++;
		}
		else count[0] = 0;
		if (a[i_key][j_key] == 2) {
			count[2]++;
		}
		else count[1] = 0;
	}
	if (check2(count))
		return true;

	return false;
}

QiPan::QiPan()
{
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			a[i][j] = 0;
	this->size = 15;
}

void QiPan::putChess(Chess chess, int x, int y)
{
	this->a[x][y] = chess.getType();
}

bool QiPan::win()
{
	bool signal_break = false;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (check(i, j)) {
				signal_break = true;
				break;
			}
		}
		if (signal_break) break;
	}
	return signal_break;
}

string QiPan::getStringWinner()
{
	if (winner == 1) return "黑棋棋手";
	else if (winner == 2)	return "白棋棋手";
	else return "HIM";
}

QiPan::~QiPan()
{
}
