#include <stdio.h>
#include <windows.h>

int main(void)
{
	float money;
	char name[40];
	
	printf("Hello~What's your name?\n");
	printf("Please input:");
	scanf("%s",&name);
	printf("OK,%s.How much money do you have?\n",name);
	printf("Please input:$___\b\b\b");
	scanf("%f",&money);
	printf("The %s's family just may be $%.2f richer!\n",name,money);
	
	system("pause");
	return 0;
}

