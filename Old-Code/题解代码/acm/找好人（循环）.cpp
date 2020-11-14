#include <stdio.h>
#define A 0
#define B 1
#define C 2
#define D 3
#define not_A 4
#define not_B 5
#define not_C 6
#define not_D 7

void print (int x);
int main()
{
	int wrong=4,i,temp;
	int person[4];
	
	while (wrong--)
	{
		person[A]=not_A;
		person[B]=C;
		person[C]=D;
		person[D]=not_D;
		if (wrong==A)
			person[A]=A;
		else if (wrong==B)
			person[B]=not_C;
		else if (wrong==C)
			person[C]=not_D;
		else if (wrong==D)
			person[D]=D;
		for (i=0;i<4;i++)
		{ 
			if (person[i]<4)	
			{
				temp=person[i];
				break;
			}
		}
		for (i=0;i<4;i++)
		{
			if (temp!=person[i]&&person[i]<4)	break;
			else if (temp==person[i]-4)	break;
		}
		if (i==4)	
		{
			for (i=0;i<4;i++)
			{
				if (person[i]<4)	
				{
					print(person[i]);
					break;
				}
			}
		}
	}
}
void print (int x)
{
	switch (x)
	{
		case 0:	printf("A"); break;
		case 1:	printf("B"); break;
		case 2:	printf("C"); break;
		case 3:	printf("D"); break;
	}
}
