#include <stdio.h>
#include <string.h>
void del_char(char *, char);
int main()
{
	char s[100];
	char ch;
	
	ch = getchar();
	getchar();
	gets(s);
	del_char(s, ch);
	puts(s);
}
void del_char(char *s, char ch)
{
	int s_length = strlen(s);
	
	for (int i = 0; i < s_length; i++)
	{
		if (s[i] == ch)
		{
			for (int j = i; j < s_length - 1; j++)
			{
				s[j] = s[j + 1];
			}
			i--;
			s_length--;
			s[s_length] = '\0';
		}
	}
}
