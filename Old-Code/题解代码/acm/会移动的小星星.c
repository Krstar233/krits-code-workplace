//会动的星星.c
#include <stdio.h>
#include <windows.h>

void HideCursor();

int main()
{
	int x=0,y=0,a=0,b=0,i=0;			//a(横坐标),b(纵坐标)用于确立星星的位置，x,y用来刷新数组
	char dir;							//dir(键入方向)
	char face[100][30]={0};

	x=0;
	y=0;
	a=28;
	b=15;
	face[a][b]='*';
	while (y<30)
	{
		while (x<100)
		{
			printf("%c",face[x][y]);
				x++;
		}
		printf("\n");
		y++;
		x=0;
	}
	
    HideCursor();
	while (i==0)
	{
		HideCursor();
		dir=getch();
		system("CLS");
		if ('w'==dir)		//4个if语句用来判断星星的移动方向
		{

			x=0;			//x,y变成0为刷新数组做准备
			y=0;  
			while (y<30)		//这个循环是用来刷新数组的（这样整个数组就变成全空白了）
			{
			while (x<100)
			{
				face[x][y]=0;
				x++;
			}
			y++;
			x=0;
			}
			a=a;				//*号位置变化了
			b=b-1;
			face[a][b]='*';		//再次确定星星位置

		}
		if ('s'==dir)
		{
			x=0;
			y=0;
		while (y<30)
		{
			while (x<100)
			{
				face[x][y]=0;
				x++;
			}
			y++;
			x=0;
		}
			a=a;
			b=b+1;
			face[a][b]='*';

		}
		if ('a'==dir)
		{
			x=0;
			y=0;
		while (y<30)
		{
			while (x<100)
			{
				face[x][y]=0;
				x++;
			}
			y++;
			x=0;
		}
			a=a-1;
			b=b;
			face[a][b]='*';

		}
		if ('d'==dir)
		{
			x=0;
			y=0;
		while (y<30)
		{
			while (x<100)
			{
				face[x][y]=0;
				x++;
			}
			y++;
			x=0;
		}
			a=a+1;
			b=b;
			face[a][b]='*';

		}

		x=0;				//在一系列的判断之后，终于改变了整个数组的值，现在可以打印出来了~
		y=0;
		while (y<30)		//打印数组
		{
			while (x<100)
			{
			printf("%c",face[x][y]);
				x++;
			}
			printf("\n");
			y++;
			x=0;
		}
	

	}



	getch();
	return 0;
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}