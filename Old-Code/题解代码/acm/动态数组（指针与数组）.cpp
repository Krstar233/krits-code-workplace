#include <stdio.h>
#include <iostream>
using namespace std;
char Maxchar(char *p, int n);
float Aver(int *p, int n);
float Minf(float *p, int n);
int main()
{
	int t;
	char cmd;
	int n;
	int *intp = NULL;
	char *chp = NULL;
	float *fp = NULL;
	char maxc;
	float minf;
	float aver;
	
	scanf("%d", &t);
	getchar();
	
	while (t--)
	{
		scanf("%c %d", &cmd, &n);
		getchar();
		
		switch (cmd)
		{
			case 'C':{
				chp = new char[n];
				for (int i = 0; i < n; i++)
				{
					scanf("%c", chp + i);
					getchar();
				}
				maxc = Maxchar(chp, n);
				cout << maxc << endl;
				delete chp;
				chp = NULL;
				break;
			}
			case 'I':{
				intp = new int[n];
				for (int i = 0; i < n; i++)
				{
					scanf("%d", intp + i);
					getchar();
				}
				aver = Aver(intp, n);
				cout << aver << endl;
				delete intp;
				intp = NULL;
				break;
			}
			case 'F':{
				fp = new float[n];
				for (int i = 0; i < n; i++)
				{
					scanf("%f", fp + i);
					getchar();
				}
				minf = Minf(fp, n);
				cout << minf << endl;
				delete fp;
				fp = NULL;
				break;
			}
		}
	}
	
}
char Maxchar(char *p, int n)
{
	char max = *p;
	
	for (int i = 0; i < n; i++)
	{
		if (max < *(p + i))
		{
			max = *(p + i);
		}
	}
	return max;
}
float Aver(int *p, int n)
{
	int aver = 0;
	
	for (int i = 0; i < n; i++)
	{
		aver += *(p + i);
	}
	return aver / (float)n;
}
float Minf(float *p, int n)
{
	float min = *p;
	
	for (int i = 0; i < n; i++)
	{
		if (min > *(p + i))
			min = *(p + i);
	}
	return min;
}

