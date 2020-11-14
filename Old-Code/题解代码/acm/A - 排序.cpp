#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
	int len,i,j;
	int num[1015];
	char enter[1015];
	
	while (gets(enter)!=NULL)
	{
		len=0;
		j=0;
		memset(num,0,sizeof(int)*1015);
		len=strlen(enter);
		if (enter[0]=='5') j--;
		for (i=0;i<len;i++)
		{
			if (enter[i]!='5')
			{
				enter[i]-='0';
				num[j]=num[j]*10+enter[i];
			}
			else if (enter[i+1]!='5')
			{
				j++;
			}
		}
		if (enter[len-1]!='5')	j++;
		sort(num,num+j);
		for (i=0;i<j;i++)
		{
			printf ("%d",num[i]);
			if (i!=j-1) printf (" ");
		}
		printf ("\n");
	}
}
