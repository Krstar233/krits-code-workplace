#include <stdio.h>
#define MAX_SCORE 100
struct score
{
	float grade[5];
	float avergrade,maxgrade,mingrade;
};
typedef struct score SC;
float search_max(float num[5]);
float search_min(float num[5]);
float averscore(float num[5]);
int main()
{
	int i,j;
	SC student[5];
	for (i=0;i<5;i++)
	{
		printf("student_%d:",i+1);
		for (j=0;j<5;j++)
		{
			scanf("%f",&student[i].grade[j]);
		}
		student[i].maxgrade=search_max(student[i].grade);
		student[i].mingrade=search_min(student[i].grade);
		student[i].avergrade=averscore(student[i].grade);
		printf ("\n");
	}
	printf("student\t\tavergrade\tmaxgrade\tmingrade\n");
	for (i=0;i<5;i++)
	{
		printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\n",i+1,student[i].avergrade,student[i].maxgrade,student[i].mingrade);
	}
}
float search_max(float num[5])
{
	int i,max=0;
	for (i=0;i<5;i++)
	{
		if (max<num[i])
		{
			max=num[i];
		}
	}
	return max;
}
float search_min(float num[5])
{
	int i,min=MAX_SCORE;
	
	for (i=0;i<5;i++)
	{
		if (min>num[i])
		{
			min=num[i];
		}
	}
}
float averscore(float num[5])
{
	int i,sum=0;
	
	for (i=0;i<5;i++)
	{
		sum+=num[i];
	}
	return (sum/5.0);
}
