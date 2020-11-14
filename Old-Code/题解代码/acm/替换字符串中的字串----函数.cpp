#include <stdio.h>
#include <string.h>

void str_copy(char s1[], char s2[], int n, int m);
int main()
{
	char s1[100];
	char s2[100];
	int n, m;
	
	scanf("%d",&n);
	getchar();
	gets(s1);
	scanf("%d",&m);
	str_copy(s1, s2, n, m);
	puts(s2);
}
void str_copy(char s1[], char s2[], int n, int m)
{	
	for (int i = m - 1; i < n; i++)
	{
		s2[i - (m - 1)] = s1[i];
	}
	s2[n - (m - 1)] = '\0'; 
}
