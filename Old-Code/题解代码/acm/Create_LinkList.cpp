#include <stdio.h>
#include <stdlib.h>
struct Test_Info
{
	int a,b,c;
	struct Test_Info *next;
};
typedef Test_Info NODE;
NODE *Creat_LinkList()
{
	NODE *head,*tail,*pnew;
	
	head=(NODE *)malloc(sizeof(NODE));
	if (head==NULL)
	{
		printf ("no enough memory!\n");
		return (NULL);
	}
	tail=head;
	while (1)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if (a<0||b<0||c<0)
			break;
		pnew=(NODE *)malloc(sizeof(NODE));
		if (pnew==NULL)
		{
			printf("no enough memory!\n");
			break;
		}
		pnew->a=a;
		pnew->b=b;
		pnew->c=c;
		pnew->next=NULL;
		
		tail->next=pnew;
		tail=pnew;
	}
	return (head);
}
