#include <stdio.h>
#include <string.h>

void insert(char str[], char substr[], int index);
void DeleteChar(char str[], char ch);
void DeleteRange(char str[], int left, int right);
void InsertReverse(char str[]);
void Reverse(char str[]);
int CountVowel(char str[]);

int main()
{
	char str[10001] = {0};
	char substr[10001];
	char cmd[40];
	char ch;
	int index, left, right;
	
	while (1)
	{
		scanf("%s", cmd);
		if (strcmp(cmd, "OVER") == 0)
			break;
		if (strcmp(cmd, "INSERT_STR") == 0)
		{
			scanf ("%d %s", &index, substr);
			insert(str, substr, index);
			puts(str);
		}
		else if (strcmp(cmd, "DELETE_CHAR") == 0)
		{
			while (getchar() != ' ' && getchar() != '\n');
				scanf("%c", &ch);
			DeleteChar(str, ch);
			puts(str);
		}
		else if (strcmp(cmd, "DELETE_RANGE") == 0)
		{
			scanf("%d %d", &left, &right);
			DeleteRange(str, left, right);
			puts(str);
		}
		else if (strcmp(cmd, "INSERT_REVERSE_STR") == 0)
		{
			InsertReverse(str);
			puts(str);
		}
		else if (strcmp(cmd, "REVERSE_STR") == 0)
		{
			Reverse(str);
			puts(str);
		}
		else if (strcmp(cmd, "COUNT_VOWEL") == 0)
		{
			printf("%d\n",CountVowel(str));
		}
	}
}

void insert(char str[], char substr[], int index)
{
	char tmp1[10001], tmp2[10001];
	
	strncpy(tmp1, str, index - 1);
	tmp1[index - 1] = '\0';
	strcpy(tmp2, str + index - 1);
	strcat(tmp1, substr);
	strcat(tmp1, tmp2);
	strcpy(str, tmp1);
}
void DeleteChar(char str[], char ch)
{
	char tmp[10001];
	int key = 0;
	
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ch)
			str[i] = ' ';
	}
	for (int i = 0; i <= strlen(str); i++)
	{
		if (str[i] != ' ')
		{
			tmp[key] = str[i];
			key++;
		}
	}
	strcpy(str, tmp);
}
void DeleteRange(char str[], int left, int right)
{
	char tmp[10001];
	
	strncpy(tmp, str, left - 1);
	tmp[left - 1] = '\0';
	strcat(tmp, str + right);
	strcpy(str, tmp);
}
void InsertReverse(char str[])
{
	char tmp[10001];
	int str_length = strlen(str);
	
	for (int i = 0; i < str_length; i++)
	{
		tmp[i] = str[str_length - i - 1];	
	}
	tmp[str_length] = '\0';
	strcat(str, tmp);
}
void Reverse(char str[])
{
	char tmp[10001];
	int str_length = strlen(str);
	
	for (int i = 0; i < str_length; i++)
	{
		tmp[i] = str[str_length - i - 1];	
	}
	tmp[str_length] = '\0';
	strcpy(str, tmp);
}
int CountVowel(char str[])
{
	char aeiou[10] = {'a','e','i','o','u','A','E','I','O','U'};
	int sum = 0;
	
	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (str[i] == aeiou[j])
			{
				sum++;
				break;
			}
		}
	}
	return sum;
}
