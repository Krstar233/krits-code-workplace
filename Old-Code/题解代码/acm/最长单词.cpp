#include <stdio.h>
#include <string.h>

void MaxLenWord(char s[]);
int main()
{
	int t;
	char s[100];
	
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		gets(s);
		MaxLenWord(s);
	}
}
void MaxLenWord(char s[])
{
	int count = 0, max_count = 0, words_num = 0;
	char words[100][40];
	char tmp[40];
	int s_length = strlen(s);
	
	for (int i = 0; i <= s_length; i++)
	{
		if (s[i] != ' ' && s[i] != '\0')
		{
			count++;
		}
		else
		{
			if (max_count < count)
				max_count = count;
			count = 0;
		}
	}
	count = 0;
	for (int i = 0; i <= s_length; i++)
	{
		if (s[i] != ' ' && s[i] != '\0')
		{
			tmp[count] = s[i];
			count++;
		}
		else
		{
			tmp[count] = '\0';
			if (max_count == count)
			{
				strcpy(words[words_num], tmp);
				words_num++;
			}
			count = 0;
		}
	}
	for (int i = 0; i < words_num; i++)
	{
		printf ("%s", words[i]);
		if (i != words_num - 1)
			printf (" ");
	}
	printf ("\n");
}
