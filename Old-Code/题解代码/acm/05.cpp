#include <stdio.h>
#include <string.h>
float aver(int score[], int n);
int findMax(int score[], int n);
int findMin(int score[], int n);
void BubbleSortByName(char name[][21], int score[], int n);
void SelectionSortByScore(char name[][21], int score[], int n); 
void print(char name[][21], int score[], int n); 

int main()
{
	int t;
	int n, m;
	char name[100][21];
	int score[100];
	char cmd[20];
	int index, sc;
	
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &m);
		getchar();
		for (int i = 0; i < n; i++)
		{
			scanf("%s %d", name[i], &score[i]);
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%s", cmd);
			if (strcmp(cmd, "QUERY_AVERAGE") == 0)
			{
				printf ("%.1f\n", aver(score, n));
			}
			else if (strcmp(cmd, "QUERY_MAX") == 0)
			{
				printf ("%d\n", findMax(score, n));
			}
			else if (strcmp(cmd, "QUERY_MIN") == 0)
			{
				printf ("%d\n", findMin(score, n));
			}
			else if (strcmp(cmd, "CHANGE") == 0)
			{
				scanf("%d %d", &index, &sc);
				score[index - 1] = sc;
			}
			else if (strcmp(cmd, "BUBBLE_SORT_BY_NAME_ASC") == 0)
			{
				BubbleSortByName(name, score, n);
				print(name, score, n);
			}
			else if (strcmp(cmd, "SELECTION_SORT_BY_GRADE_DESC") == 0)
			{
				SelectionSortByScore(name, score, n);
				print(name, score, n);
			}
			
		}
		printf ("\n");
	}
	return 0;
}

float aver(int score[], int n)
{
	float sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		sum += score[i];
	}
	return sum/n;
}

int findMax(int score[], int n)
{
	int max = score[0];
	
	for (int i = 0; i < n; i++)
	{
		if (max < score[i])
			max = score[i];
	}
	return max;
}

int findMin(int score[], int n)
{
	int min = score[0];
	
	for (int i = 0; i < n; i++)
	{
		if (min > score[i])
			min = score[i];
	}
	return min;
}

void BubbleSortByName(char name[][21], int score[], int n)
{
	char tmp1[21];
	int tmp2;
	
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; j < n - i - 1; j++)
		{
			if (strcmp(name[j], name[j + 1]) > 0)
			{
				strcpy(tmp1, name[j]);
				tmp2 = score[j];
				
				strcpy(name[j], name[j+1]);
				score[j] = score[j+1];
				
				strcpy(name[j+1], tmp1);
				score[j+1] = tmp2;
			}
		}
		for (int j = 0; j < n; j++)
		{
			printf ("%s", name[j]);
			if (j != n - 1)
				printf (" ");	
		}
	}
}
void SelectionSortByScore(char name[][21], int score[], int n)
{
	int minkey;
	int tmp1;
	char tmp2[21];
	for (int i = 0; i < n - 1; i++)
	{
		minkey = i;
		for (int j = i; j < n; j++)
		{
			if (score[minkey] > score[j]);
				minkey = j;
		}
		tmp1 = score[minkey];
		strcpy(tmp2, name[minkey]);
		
		score[minkey] = score[i];
		strcpy(name[minkey], name[i]);
		
		score[i] = tmp1;
		strcpy(name[i], tmp2);
		for (int j = 0; j < n; j++)
		{
			printf ("%d", score[j]);
			if (j != n - 1)
				printf (" ");
		}
	}
}
void print(char name[][21], char score[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf ("%s %d\n", name[i], score[i]);
	}
}
 
