#include <stdio.h>
#include <string.h>
int carry(char cmd[], int queue[], int end);
void print(int queue[], int end);
int main()
{
	int t;
	int n;
	int end;
	int queue[100];
	char cmd[40];
	
	scanf("%d",&t);
	while (t--)
	{
		end = 0;
		scanf("%d",&n);
		getchar();
		for	(int i = 0; i < n; i++)
		{
			scanf("%s",cmd);
			end = carry(cmd, queue, end); 
		}
		print(queue, end);	
	} 
}
int carry(char cmd[], int queue[], int end)
{
	int x;
	if (strcmp(cmd, "push") == 0)
	{
		scanf("%d",&x);
		queue[end] = x;
		end++;
	}
	else if(strcmp(cmd, "pop") == 0)
	{
		for (int j = 0; j < end - 1; j++)
		{
			queue[j] = queue[j + 1];
		}
		end--;
	}
	return end;
}
void print(int queue[], int end)
{
	if (end != 0)
	{
		for (int i = 0; i < end; i++)
		{
			printf ("%d",queue[i]);
			if (i != end - 1)
				printf (" ");
		}
		printf ("\n");
	}
	else
		printf ("no eggs!\n");
}
