#include <iostream>
#include "QiPan.h"
#include "Chess.h"
#include "Player.h"

using namespace std;

int main() {
	QiPan qipan;
	Player player1(1), player2(2);
	bool choose = true;

	while (!qipan.win())
	{
		int x, y;
		while (cin >> x >> y && ( !(x >= 0 && x < 15) || !(y >= 0 && y < 15) ) ) {
			cout << "请重新输入：" << endl;
		}
		if (choose) {
			player1.putChess(qipan, x, y);
			choose = !choose;
		}
		else
		{
			player2.putChess(qipan, x, y);
			choose = !choose;
		}
	}
	cout << qipan.getStringWinner() << "是最后的赢家！" << endl;
}