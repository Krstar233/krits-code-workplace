#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num,i;
	int *score;
	int max_score,min_score;
	int tof=0;
	double averscore;
	averscore=0;
	max_score=0;
	min_score=0;
	
	while(1)
	{
	averscore=0;
	max_score=0;
	min_score=0;
	printf ("Please input the number of students:");
	tof=scanf ("%d",&num);
	if (tof==EOF)
	{
		break;
	}
	score=(int *)malloc(num*sizeof(int));
	if (score==NULL)
	{
		printf("ERROR!!\n");
	}
	printf ("Please input every student's score:");
	for (i=0;i<num;i++)
	{
		scanf("%d",score+i);
		averscore+=*(score+i);	
	}
	averscore=averscore/num;
	min_score=*score;
	for (i=0;i<num;i++)
	{
		if (min_score>*(score+i))
		{
			min_score=*(score+i);
		}
		if (max_score<*(score+i))
		{
			max_score=*(score+i);
		}
	}
	printf("\n");
	printf("----------------------------------------\n");
	printf("The average score of the students is %.2lf\n",averscore);
	printf("The highest score of the students is %d\n",max_score);
	printf("The lowest score of the students is %d\n",min_score);
	printf("----------------------------------------\n\n\n");
	}
	free(score);
}
