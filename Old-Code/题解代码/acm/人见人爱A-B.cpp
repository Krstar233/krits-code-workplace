#include <stdio.h>

int main()
{
	int a[100],b[100],c[100],n,m,i,j,t,l,temp;	//a[],b[]分别表示集合A和集合B;c[]表示 A-B 
	
	while (scanf("%d%d",&n,&m)!=EOF)
	{
	if (n==0&&m==0)
	{
		break;
	}
	for (i=0;i<n;i++)	scanf("%d",&a[i]);	//输入集合A
	for (i=0;i<m;i++)	scanf("%d",&b[i]);	//输入集合B
	l=0;
	//以下是执行A-B的操作
	for (i=0;i<n;i++)
	{
		t=0;
		for (j=0;j<m;j++)
		{
			if (a[i]==b[j])	t=-1;	//如果期间有发现集合A中的元素集合B中也有，立即记录下来 
		}
		if (t==0)	//如果没发现有相同元素(说明这个元素是集合A-B中的一个)，就立即将这个元素记入c[]中 
		{
			c[l]=a[i];
			l++;
		}
	}
	if (l==0)	printf("NULL");		//如果没有记录到A-B不是空集，那就输出NULL 
	else
	{
		//以下将c[]中的元素按从小到大排序 
		for (j=0;j<l-1;j++)
		{
			for (i=0;i<l-j-1;i++)
			{
				if (c[i]>c[i+1])
				{
					temp=c[i];
					c[i]=c[i+1];
					c[i+1]=temp;
				}
			}
		}
		//打印c[]
		for (i=0;i<l;i++)	printf("%d ",c[i]); 
	}
	printf ("\n");
	}
}
