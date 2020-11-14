#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
	int  t;
	int n;
	
	scanf("%d",&t);
	while (t--)
	{
		int sum = 0;
		int yu;
		scanf("%d",&n);
		getchar();
		for (int i = 0; i < n; i++)
		{
			int j = 0;
			char type[20], s[100];
			gets(s);
			
			while (s[j] != ' ')
			{
				type[j] = s[j];
				j++;
			}
			type[j] = '\0';
			if (strcmp(type, "int") == 0)
				sum += 4;
			else if (strcmp(type, "bool") == 0)
				sum += 1;
			else if (strcmp(type, "long") == 0)
				sum += 8;
			else if (strcmp(type, "double") == 0)
				sum += 8;
			else if (strcmp(type, "char") == 0)
				sum += 1;
			else if (strcmp(type, "float") == 0)
				sum += 4;
		}
		yu = sum % 1024;
		sum = sum / 1024;
		if (yu != 0)
			sum++;
		cout << sum << endl;
	}
}
