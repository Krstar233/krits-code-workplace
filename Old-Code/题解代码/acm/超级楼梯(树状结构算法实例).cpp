#include <stdio.h>		/*树状结构算法实例~	OwO */
int way1(int n,int *p);
int way2(int n,int *p);
int tree(int n,int *p);
int main()
{
	int m,n,i,*p,sum;
	
	scanf("%d",&m);
	for (i=0;i<m;i++)
	{
		sum=0;
		p=&sum;		//用指针指向记录树杈分支（路线）的变量，方便在大树的内部调用~ =w= ~ 233
		scanf("%d",&n);
	//	if (n<1||n>40)	continue;
		tree(n,p);		//进入这颗大树~ 
		printf("%d\n",sum);		//输出走过的路线的总个数 
	}
}
int tree(int n,int *p)	//每一个tree相等于一个分叉口，分出不同的情况way1，way2；（如果分叉多了也可以加way3,way4,way5...） 
{
	if (n-2!=0||n-1==0)	//确保走到最后一步的时候n==0
		way1(n,p);
	if (n-1!=0)			//确保走到最后一步的时候n==0 
		way2(n,p);
}
int	way1(int n,int *p)
{
	n--;
	if (n!=0)
		tree(n,p);		//如果还没结束，那么就又会遇到分叉口，那么就又进入另一个tree()中 
	else				 
	{					//如果结束了，那么就将这道路的尽头（树枝的端点）记录下来 
		*p=*p+1;		//记录的方式就是将指针指向的main()中的用于记录路线个数的变量+1 
	}
}
int way2(int n,int *p)
{
	n-=2;
	if (n!=0)
		tree(n,p);
	else				//用指针就可以不用担心用于记录的变量在中途改变了 
	{			
		*p=*p+1;		//每到道路尽头，就立即将用于记录的变量自增1，这样就可以记录下所有的路线个数了~ 
	}
}
