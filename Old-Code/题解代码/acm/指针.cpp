#include <stdio.h>

int main()
{
	int i=0,n=3,*p,num[10]={0,1,2,3,4,5,6,7,8,9};
	p=num;	//p是装地址的地方 
	printf("*p=%d	num[0]=%d	num[1]=%d\n",*p,num[0],num[1]);
	p=&num[1];	//*p是所装地址所指向的地方（在这里相当于n）
	/*	对 p 改变是改变的p内所装的东西(某个地址),对 *p 改变是改变了p所装地址所指向的地方	*/ 
	printf("*p=%d	num[0]=%d	num[1]=%d\n",*p,num[0],num[1]);
	p++;
	printf("*p=%d	num[0]=%d	num[1]=%d 	num[2]=%d\n",*p,num[0],num[1],num[2]);
	*p=42;
	printf("*p=%d	num[0]=%d	num[1]=%d 	num[2]=%d\n",*p,num[0],num[1],num[2]);
	
}
