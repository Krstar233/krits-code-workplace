#include <stdio.h>

int main()
{
	int num,ge,shi,bai;
	
	scanf("%d",&num);
	bai=num/100;
	shi=num%100/10;
	ge=num%100%10;
	if (ge==0)	
		printf("%d%d",shi,bai);		//�������λ��0������ӡ�� 
	else 
		printf("%d%d%d",ge,shi,bai);
}	

