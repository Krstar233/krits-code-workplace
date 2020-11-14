#include <stdio.h>
#include <stdlib.h> 
int min (int *num,int n);
void change (int *a,int *b);
int main()
{
	int n,num[100],i,a,j;
	
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&num[i]);	
	}
	for (i=0;i<n;i++)
	{
		a=min(&num[i],n-i);
		for (j=i;j<n-i;j++)
		{
			if (a==num[j])	break;
		}
		change(&num[j],&num[i]);
	}
	for (i=0;i<n;i++)
	{
		printf("%d",num[i]);
	}
}
int min (int *num,int n)
{
	int t,i,*p;
	
	p=num;
	t=*num;
	for (i=0;i<n;i++)
	{
		if (t>*num)	change (&t,&*num);
		num++;
	}
	return t;
}
void change (int *a,int *b)
{
	int t;
	
	t=*a;
	*a=*b;
	*b=t;
}


