#include <Windows.h>
#include <iostream>
#include "Board.h"
#include <conio.h>
#include <stdio.h>
#include <pthread.h>
#pragma comment(lib, "pthreadVC2.lib")
using namespace std;




//===============================
void HideCursor();
void gotoxy(int x, int y);
//===============================







//===============================
bool signal_end = false;
//===============================



void show(Board &board) {

	//=============打印主界面================
	for (int i = 0; i < board.getHeight(); i++) {
		for (int j = 0; j < board.getWeight(); j++) {
			if (i >= board.block->getX() && i < board.block->getX() + 4
				&& j >= board.block->getY() && j < board.block->getY() + 4) {
				int type = board.block->getType();
				int ti = i - board.block->getX();
				int tj = j - board.block->getY();
				if (board.block->shape[type][ti][tj] != 0) {
					cout << "# ";
					continue;
				}
			}
			if (board.map[i][j] == 0)
				cout << "  ";
			else
				cout << "# ";
		}
		cout << "+ " << endl;
	}
	for (int i = 0; i < board.getWeight() + 1; i++)
		cout << "+ ";
	cout << endl;

	//======打印正在下落的方块的位置=======
	//cout << "(" << board.block->getX() << "," << board.block->getY() << ")" << endl;


	//=====打印得分=====
	cout << "Score:" << board.getScore() << endl;

	
	//=====打印下一种方块=====

	int pianyi = 2;
	gotoxy(board.getWeight()*2+2, 0);
	cout << "NEXT BLOCK";
	gotoxy(board.getWeight() * 2 + 2, 1);
	cout << "+ + + + + ";
	gotoxy(board.getWeight() * 2 + 2, pianyi);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int nexttype = board.block->getNexttype();
			if (board.block->shape[nexttype][i][j] == 0) {
				cout << "  ";
			}
			else
			{
				cout << "# ";
			}
		}
		cout << "+ ";
		gotoxy(board.getWeight()*2+2, i+1+pianyi);
	}
	gotoxy(board.getWeight()*2+2, 4+pianyi);
	for (int i = 0; i < 5; i++) {
		cout << "+ ";
	}
	gotoxy(0, board.getHeight()/2);
	//======================

}

void control(Board &board) {
	//======控制======
	char key;
	if (kbhit()) {
		key = getch();
		if ('a' == key) {
			board.block->moveLeft();
		}
		if ('s' == key) {
			board.block->moveDown();
		}
		if ('d' == key) {
			board.block->moveRight();
		}
		if ('w' == key) {
			board.block->moveUp();
		}
		if (' ' == key) {
			board.block->moveUp();
		}
		if (27/*esc*/ == key) {
			system("pause");
		}
	}
}

void* xuanran(void* args) {
	Board* board = (Board*)args;
	while (true)
	{
		HideCursor();
		gotoxy(0, 0);
		show(*board);
		control(*board);
		if (signal_end) {
			return NULL;
		}
		Sleep(100);
		//system("cls");
	}
	return NULL;
}// 渲染线程


//==================================================================================
void HideCursor()	//隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x, int y)	//移动光标位置
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//==================================================================================



void GameStartShow() {
	cout << "=====================================" << endl;
	cout << "               俄罗斯方块			  " << endl;
	cout << "向左移动方块 -- a | 向右移动方块 -- d" << endl;
	cout << "向下移动方块 -- s | 逆时针旋转方块 -- w/space" << endl;
	cout << "   暂停游戏 -- esc  ..." << endl;
	cout << "=====================================" << endl;
	system("pause");
	system("cls");
}
int main() {
	Board board(10, 20);
	char key;

	GameStartShow();
	pthread_t shows;
	int ret = pthread_create(&shows, NULL, xuanran, &board);

	if (ret != 0)
	{
		cout << "pthread_create error: error_code=" << ret << endl;
		system("pause");
		return 0;
	}


	while (true)
	{
		if (board.block->detect(1))
			board.block->moveDown();

		else
		{
			/*cout << "----" << endl;*/
			board.confirm();
		}

		//---------------
		//show(board);
		//control(board);
		//---------------


		if (board.isEnd()) {
			signal_end = true;
			break;
		}
		/*fflush(stdin);*/

		Sleep(board.getTime());
		//system("cls");

	}

	//pthread_exit(&shows);
	Sleep(500);
	gotoxy(0, (board.getHeight()+2));
	cout << "GAME OVER!" << endl;
	system("pause");
}