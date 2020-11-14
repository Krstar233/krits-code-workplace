#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
void HideCursor();
int main()
{
	int i,j;
	int x=1;
	int y=10;
	int velocity_x=1,velocity_y=1;;
	int left=0,right=50;
	int top=0,bottom=25;
	char input;
	while (1)
	{
		if (x>=bottom||x<=top)
			velocity_x=-velocity_x;
		if (y>=right||y<=left)
			velocity_y=-velocity_y;
		x+=velocity_x;
		y+=velocity_y;
		if (kbhit())
		{
			input=getch();
			if ('A'<=input&&input<='Z')	input+='a'-'A';
			switch (input)
			{
				case 'a':	if (velocity_y>-2)	
								velocity_y--;
							break;
				case 'd':	if (velocity_y<2)
								velocity_y++;
							break;
				case 's':	if (velocity_x<2)
								velocity_x++;
							break;
				case 'w':	if (velocity_x>-2)
								velocity_x--;
							break;
			}
		}
		HideCursor();
		system("cls");
		for (i=0;i<x;i++)
			printf ("\n");
		for (j=0;j<y;j++)
			printf (" ");
		printf ("o\n");
		Sleep(60);
	}
}
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
