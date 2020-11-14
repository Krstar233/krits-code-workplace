#include <stdio.h>
void MAX(int n,float *x);
void MIN(int n,float *x);
int main()
{
	int n,i;
	float score[100]={0},aversc,*p,allsc;//aversc==averscore,allsc==all score
	
	while (scanf("%d",&n)!=EOF)
	{
		if (n<=2||n>100){while (getchar()!='\n');continue;}
		allsc=0;
		for (i=0;i<n;i++)	scanf("%f",&score[i]);	
		p=score;
		MAX(n,p);MIN(n,p);
		for (i=0;i<(n-2);i++)	allsc+=score[i];
		aversc=allsc/(n-2.0);
		printf("%.2f\n",aversc);
	}
	return 0;
}
void MAX(int n,float *x)
{
	int temp;
	for (int i=0;i<(n-1);i++)
	{
		if (*(x+i+1)<*(x+i))
		{
			temp=*(x+i);
			*(x+i)=*(x+i+1);
			*(x+i+1)=temp;
		}
	}
}
void MIN(int n,float *x)
{
	int temp;
	for (int i=0;i<(n-1);i++)
	{
		if (*(x+i+1)>*(x+i))
		{
			temp=*(x+i);
			*(x+i)=*(x+i+1);
			*(x+i+1)=temp;
		}
	}
}
