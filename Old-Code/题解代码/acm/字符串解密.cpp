#include <stdio.h>

int main ()
{
	int k, b;
	char ch;
	
	while (scanf ("%d %d", &k, &b) != EOF)
	{
		while (getchar () != '\n');
		while ((ch = getchar ()) != '\n')
		{
			if (ch >= 'A' && ch <= 'Z')
			{
				ch = ch - 'A';
				ch = ( k * ch + b ) % 26;
				ch = ch + 'A';
			}
			if (ch >= 'a' && ch <= 'z')
			{
				ch = ch - 'a';
				ch =( k * ch + b ) % 26;
				ch = ch + 'a';
			}
			printf ("%c", ch);
		}
		printf ("\n");
	}
}
