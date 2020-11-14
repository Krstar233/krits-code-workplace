#include <stdio.h>
#include <string.h>
float aver(int score[], int n);
int findMax(int score[], int n);
int findMin(int score[], int n);
void BubbleSortByName(char name[][25], int score[], int n);
void SelectionSortByScore(char name[][25], int score[], int n); 
void print(char name[][25], int score[], int n); 
int findByname(char name[][25], int n,char s[]);
int insert(int index, char tmp_name[], int sc, char name[][25], int score[], int n);
int Delete(char tmp_name[], char name[][25], int score[], int n);
int main()
{
	int t;
	int n, m;
	char name[105][25], tmp_name[25];
	int score[105];
	char cmd[40];
	int index, sc, flag;
	
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
			else if (strcmp(cmd, "FIND") == 0)
			{
				scanf("%s", tmp_name);
				index = findByname(name, n, tmp_name);
				if (index == -1)
					printf ("NOT FOUND\n");
			/*	else
					printf ("%d\n", index);*/
			}
			else if (strcmp(cmd, "INSERT") == 0)
			{
				scanf("%d %s %d", &index, tmp_name, &sc);
				flag = insert(index, tmp_name, sc, name, score, n);
				if (flag == -1)
				{
					printf ("ERROR\n");
				}
				else
				{
					n++;
				}
			}
			else if (strcmp(cmd, "DELETE") == 0)
			{
				scanf("%s", tmp_name);
				flag = Delete(tmp_name, name, score, n);
				if (flag == -1)
					printf ("ERROR\n");
				else
					n--;
			}
			/*
			else if (strcmp(cmd, "PRINT") == 0)
			{
				print(name, score, n);
			}*/
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

void BubbleSortByName(char name[][25], int score[], int n)
{
	char tmp1[25];
	int tmp2;
	
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
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
		printf ("\n");
	}
}
void SelectionSortByScore(char name[][25], int score[], int n)
{
	int maxkey;
	int tmp1;
	char tmp2[25];
	
	for (int i = 0; i < n - 1; i++)
	{
		maxkey = i;
		
		for (int j = i; j < n; j++)
		{
			if (score[maxkey] == score[j])
			{
				if (strcmp(name[maxkey], name[j]) > 0)
					maxkey = j;
			}
			else if (score[maxkey] < score[j])
				maxkey = j;
		}
		
		tmp1 = score[maxkey];
		strcpy(tmp2, name[maxkey]);
		
		score[maxkey] = score[i];
		strcpy(name[maxkey], name[i]);
		
		score[i] = tmp1;
		strcpy(name[i], tmp2);
		
		for (int j = 0; j < n; j++)
		{
			printf ("%d", score[j]);
			if (j != n - 1)
				printf (" ");
		}
		printf ("\n");
	}
}
void print(char name[][25], int score[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf ("%s %d\n", name[i], score[i]);
	}
}

int findByname(char name[][25], int n, char s[])
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(name[i], s) == 0)
			return i + 1;
	}
	return -1;
}

int insert(int index, char tmp_name[], int sc, char name[][25], int score[], int n)
{
	int flag = findByname(name, n, tmp_name);
	if (flag != -1)
		return -1;
	for (int i = n; i > index - 1; i--)
	{
		strcpy(name[i], name[i - 1]);
		score[i] = score[i - 1];
	}
	strcpy(name[index - 1], tmp_name);
	score[index - 1] = sc;
	return 1;
}
int Delete(char tmp_name[], char name[][25], int score[], int n)
{
	int flag = findByname(name, n, tmp_name);
	if (flag == -1)
		return -1;
	else
	{
		for (int i = flag - 1; i < n - 1; i++)
		{
			strcpy(name[i], name[i + 1]);
			score[i] = score[i + 1]; 
		}
		return 1;
	}
}
