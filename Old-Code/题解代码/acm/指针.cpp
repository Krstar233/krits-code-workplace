#include <stdio.h>

int main()
{
	int i=0,n=3,*p,num[10]={0,1,2,3,4,5,6,7,8,9};
	p=num;	//p��װ��ַ�ĵط� 
	printf("*p=%d	num[0]=%d	num[1]=%d\n",*p,num[0],num[1]);
	p=&num[1];	//*p����װ��ַ��ָ��ĵط����������൱��n��
	/*	�� p �ı��Ǹı��p����װ�Ķ���(ĳ����ַ),�� *p �ı��Ǹı���p��װ��ַ��ָ��ĵط�	*/ 
	printf("*p=%d	num[0]=%d	num[1]=%d\n",*p,num[0],num[1]);
	p++;
	printf("*p=%d	num[0]=%d	num[1]=%d 	num[2]=%d\n",*p,num[0],num[1],num[2]);
	*p=42;
	printf("*p=%d	num[0]=%d	num[1]=%d 	num[2]=%d\n",*p,num[0],num[1],num[2]);
	
}
