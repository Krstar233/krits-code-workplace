//�ᶯ������.c
#include <stdio.h>
#include <windows.h>

void HideCursor();

int main()
{
	int x=0,y=0,a=0,b=0,i=0;			//a(������),b(������)����ȷ�����ǵ�λ�ã�x,y����ˢ������
	char dir;							//dir(���뷽��)
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
		if ('w'==dir)		//4��if��������ж����ǵ��ƶ�����
		{

			x=0;			//x,y���0Ϊˢ��������׼��
			y=0;  
			while (y<30)		//���ѭ��������ˢ������ģ�������������ͱ��ȫ�հ��ˣ�
			{
			while (x<100)
			{
				face[x][y]=0;
				x++;
			}
			y++;
			x=0;
			}
			a=a;				//*��λ�ñ仯��
			b=b-1;
			face[a][b]='*';		//�ٴ�ȷ������λ��

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

		x=0;				//��һϵ�е��ж�֮�����ڸı������������ֵ�����ڿ��Դ�ӡ������~
		y=0;
		while (y<30)		//��ӡ����
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