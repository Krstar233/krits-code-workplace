#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define High 20	//High是 行数 
#define Width 60	//Width是 列数
void print (int surface[High][Width]);
int move (int surface[High][Width],char dir,int* x,int* y,int *score);
void HideCursor();
void gotoxy(int x, int y);

struct seat
{
	int x,y;
}; 
int main()
{
	int surface[High][Width]={0};
	int i,j;
	int score;
	char dir,t;
	seat head;
	seat food;
	
	//初始化界面			surface[i][j]==-1	输出 #
	//						surface[i][j]==1	输出 蛇头@
	//						surface[i][j]==-2	输出 食物 F
	system("color f0");
	head.x=High/2;
	head.y=Width/2;
	food.x=rand()%(High-6)+3;
	food.y=rand()%(Width-6)+3;
	surface[food.x][food.y]=-2;
	dir='d';
	score=0;
	
	srand((int)time(0));
	for (i=0;i<High;i++)
	{
		for (j=0;j<Width;j++)
		{
			if (i==0||i==High-1)
			{
				surface[i][j]=-1;
			}
			else if(j==0||j==Width-1)
			{
				surface[i][j]=-1;
			}
			if (i==head.x&&j==head.y)
			{
				surface[i][j]=1;
				surface[i][j-1]=2;
				surface[i][j-2]=3;
				surface[i][j-3]=4;
			}
		}
	}
	//蛇身的移动：ok
	//吃到食物的处理: ok
	//打印:ok
	while (move(surface,dir,&head.x,&head.y,&score)!=0)
	{
		HideCursor();
		gotoxy(1,1);
		print(surface);
		if (score<500) 	Sleep (200);
		else if (score <1500)	Sleep (150);
		else Sleep (100);
		if (kbhit())
		{
			t=getch();
			if (t>='A'&&t<='Z')
				t+=32;
			if (t=='a'||t=='s'||t=='d'||t=='w')
				dir=t;
		}
	}
	printf ("*******************\n");
	printf ("*   游戏结束!!!   *\n");
	printf ("*   分数:%-8d *\n",score);
	printf ("*******************\n");
	Sleep(800);
	system("pause");
}
void print (int surface[High][Width])
{
	int i,j;
	for (i=0;i<High;i++)
	{
		for (j=0;j<Width;j++)
		{
			switch (surface[i][j])
			{
				case -1:{
					printf ("#");
					break;
				}
				case 0:{
					printf (" ");
					break;
				}
				case 1:{
					printf ("@");
					break;
				}
				case -2:{
					printf ("F");
					break;
				}
				default :{
					printf ("*");
					break;
				}
			}
		}
		printf ("\n");
	}
}
//蛇身的移动 	和	吃到食物的处理 
int move (int surface[High][Width],char dir,int *x,int *y,int *score)
{
	int i,j,a;
	int *max;
	seat food;
	a=0;
	max=&a;
	for (i=0;i<High;i++)
	{
		for (j=0;j<Width;j++)
		{
			if (surface[i][j]>0)
			{
				surface[i][j]++;
				if (*max<surface[i][j])	max=&surface[i][j];
			}
		}
	}
	a=0;	//这里a的用途变了 
	switch (dir)
	{
		case 'a':{
			if (surface[*x][*y-1]==0) 
			{
				*y=*y-1;
				surface[*x][*y]=1;
			}
			else if (surface[*x][*y-1]==-2) 
			{	
				*y=*y-1;
				surface[*x][*y]=1;	
				a=1;
			}
			else return 0;
			break;
		}
		case 'w':{
			if (surface[*x-1][*y]==0)
			{
				*x=*x-1;
				surface[*x][*y]=1;
			}
			else if (surface[*x-1][*y]==-2) 
			{	
				*x=*x-1;
				surface[*x][*y]=1;
				a=1;
			}
			else return 0;
			break;
		}
		case 'd':{
			if (surface[*x][*y+1]==0)	
			{
				*y=*y+1;
				surface[*x][*y]=1;
			}
			else if (surface[*x][*y+1]==-2) 
			{	
				*y=*y+1;
				surface[*x][*y]=1;	
				a=1;
			}
			else return 0;
			break;
		}
		case 's':{
			if (surface[*x+1][*y]==0)
			{
				*x=*x+1;
				surface[*x][*y]=1;
			}	
			else if (surface[*x+1][*y]==-2) 
			{	
				*x=*x+1;
				surface[*x][*y]=1;
				a=1;
			}
			else return 0;
			break;
		}
		default :{
			break;
		}
	}
	if (a==0)	*max=0;//没吃到食物就不变长
	else
	{
		do
		{
			food.x=rand()%(High-2)+1;
			food.y=rand()%(Width-2)+1;
		}
		while (surface[food.x][food.y]!=0);
		surface[food.x][food.y]=-2;
			(*score)+=100;
	}
	return 1;
}
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}



