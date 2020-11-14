#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
//#include <memory.h>
void add(char a[], char b[], char c[]);
int main()
{
	int t;
	char a[1005], b[1005], c[1005];
	int Case = 0;
	
	scanf("%d",&t);
	getchar();
	while (t--)
	{
		Case++;
		scanf("%s",a);
		scanf("%s",b);
		add(a, b, c);
		printf("Case %d:\n",Case);
		printf("%s + %s = %s\n",a, b, c);
		if (t != 0) printf ("\n");
	} 
}
void add(char a1[], char b1[], char c[])
{
	char res[1005];
	char t[1005];
	char a[1005], b[1005];
	strcpy(a, a1);
	strcpy(b, b1);
	int alen = strlen(a);
	int blen = strlen(b);
	int len;
	char tmp;
	int flag = 0;
 	if (blen > alen)
 	{
 		strcpy(t, b);
 		strcpy(b, a);
 		strcpy(a, t);
	}
	alen = strlen(a);
	blen = strlen(b);
	len = alen;
	for (int i = 0; i < alen; i++)
		a[i] -= '0';
	for (int i = 0; i < blen; i++)
		b[i] -= '0';
	for (int i = 0; i < len; i++)
	{
		if (alen - i - 1 >= 0 && blen - i - 1 >= 0)
		{
			if (flag == 1)
			{
				tmp = a[alen - i - 1] + b[blen - i - 1] + 1;
				flag = 0;
			}
			else tmp = a[alen - i - 1] + b[blen - i - 1];
			if (tmp / 10 > 0)
				flag = 1;
			tmp = tmp % 10;
			res[i] = tmp;
		}
		else
		{
			if (flag == 1)
			{
				tmp = a[alen - i - 1] + 1;
				flag = 0;
			}
			else tmp = a[alen - i - 1];
			if (tmp / 10 > 0)
				flag = 1;
			tmp = tmp % 10;
			res[i] = tmp;
		}
	}
	if (flag == 1)
	{
		res[len] = 1;
		len++;
		flag = 0;
	}
	for (int i = 0; i < len; i++)
	{
		c[i] = res[len - i - 1];
		c[i] += '0';
	}
	c[len] = '\0';
	for (int i = 0; i < alen; i++)
		a[i] += '0';
	for (int i = 0; i < blen; i++)
		b[i] += '0';
}
