#include <stdio.h>
#include <windows.h>
#define SQUARES 64
#define CROP 1e15
int main (void)
{
	double add=1,total=1;
	int count=1;
	
	printf("count	   grains added     total grains     fraction of US total\n");
	printf("%-11d%-17.2e%-17.2e%.2e\n",count,0,total,total/CROP);
	Sleep(300);
	
	while (count<SQUARES)
	{
		count=count+1;
		add=total*2;
		total=total+add;
		printf("%-11d%-17.2e%-17.2e%.2e\n",count,add,total,total/CROP);
		Sleep(300);
	}
	
	
	return 0;
}
