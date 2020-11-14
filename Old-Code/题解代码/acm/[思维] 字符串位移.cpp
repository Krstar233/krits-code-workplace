#include <stdio.h>
#include <string.h>

void change(char s[]);
int main()
{
	char strs[50][55];
	char tmp[50][55], sample[55];
	int  n, min, sum, flag;
	
	while (scanf("%d", &n) != EOF)
	{
		sum = 0;
		flag = 0;

		for (int i = 0; i < n; i++)
		{
			scanf("%s", strs[i]);
			strcpy(tmp[i], strs[i]);
		}
		
		for (int i = 0; i < strlen(strs[0]); i++)
		{
			for (int j = 0; j < n; j++)
			{
				strcpy(tmp[j], strs[j]);
			}
			
			sum = 0;
			strcpy(sample, tmp[0]);
			
			for (int j = 0; j < i; j++)
			{
				change(sample);
			}
			for (int j = 0; j < n; j++)
			{
				while (strcmp(tmp[j], sample) != 0)
				{
					change(tmp[j]);
					sum++;
					
					if (sum > strlen(strs[0]) * n + n)
					{
						flag = 1;
						break;
					}
				}
				if (flag)
					break;
			}
			if (flag)
				break;
			
		//	printf("*%d\n", sum);
			if (i == 0)
			{
				//printf("*%d\n", sum);
				min = sum;
			} 
			else if (min > sum)
			{
			//	printf("*%d\n", sum);
				min = sum;
			}
		}
		if (flag)
			printf ("-1\n");
		else
			printf ("%d\n", min);
	}
}

void change(char s[])
{
	int n = strlen(s);
	char ch = s[0];
	for (int i = 0; i < n - 1; i++)
	{
		s[i] = s[i + 1];
	}
	s[n - 1] = ch;
	s[n] = '\0';
}
