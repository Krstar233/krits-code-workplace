#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Grade_Info
{
	int score;
	struct Grade_Info *next;
};
typedef struct Grade_Info NODE;
NODE *Create_LinkList()
{
	NODE *head,*tail,*pnew;
	int score;
	
	head=(NODE *)malloc(sizeof(NODE));	//����ͷ�ڵ� 
	if (head==NULL)
	{
		printf("no enough memory!\n");	//����ʧ���򷵻� 
		return (NULL);
	}
	head->next=NULL;					//ͷ����ָ������NULL 
	tail=head;							//��ʼʱβָ��ָ��ͷ��� 
	
	printf("input the score of students:\n");
	while (1)							//����ѧ���ɼ��������� 
	{
		scanf("%d",&score);				//����ѧ���ɼ� 
		if (score<0)					//�ɼ�Ϊ����ѭ���˳� 
			break;
		pnew=(NODE *)malloc(sizeof(NODE));	//�����½ڵ� 
		if (pnew==NULL)
		{
			printf ("no enough memory!\n");
			return (NULL);
		}
		pnew->score=score;			//�½ڵ�������������ѧ���ɼ� 
		pnew->next=NULL;			//�½ڵ�ָ������NULL 
		
		tail->next=pnew;			//�½ڵ���뵽����β 
		tail=pnew;					//βָ��ָ��ǰ��β�ڵ� 
	}
	return (head);					//���ش����������ͷָ��
}
//���½ڵ�(pnew��ָ��Ľڵ�)���뵽��headΪͷָ�������ĵ�i���ڵ�֮��
void Insert_LinkList (NODE *head,NODE *pnew,int i)
{
	NODE *p;
	int j;
	
	p=head;
	for (j=0;j<i&&p!=NULL;j++)		//��pָ���i���ڵ� 
		p=p->next;
	if (p==NULL)					//������i���ڵ㲻���� 
	{
		printf ("the %d node not found!\n",i);
		return;
	}
	pnew->next=p->next;				//������ڵ��ָ����ָ���i���ڵ�ĺ�̽ڵ� 
	p->next=pnew;					//����i���ڵ��ָ����ָ�����ڵ� 
}
//ɾ����headΪͷָ�������ĵ�i���ڵ� 
void Delete_LinkList(NODE *head,int i)
{
	NODE *p,*q;
	int j;
	
	if (i==0)						//��ͷָ��Ͳ���ɾ�����򷵻� 
		return;
	p=head;
	for (j=1;j<i&&p->next!=NULL;j++)
		p=p->next;					//��pָ��Ҫɾ���ĵ�i���ڵ��ǰ���ڵ� 
	if (p->next==NULL)				//������i���ڵ㲻���� 
	{
		printf ("the %d node not found!",i);
		return ;
	}
	
	q=p->next;
	p->next=q->next;
	free(q);
} 
//����һ���½ڵ�
NODE *Create_NewNode(int score)
{
	NODE *pnew;
	
	pnew=(NODE *)malloc(sizeof(NODE));
	if (pnew==NULL)
	{
		printf("no enough memory!\n");
		return (NULL);
	}
	pnew->next=NULL;
	pnew->score=score;
	
	return (pnew);
} 
//������� 
void Display_LinkList(NODE *head)
{
	NODE *p;
	
	for (p=head->next;p!=NULL;p=p->next)
		printf ("%d ",p->score);
	printf ("\n");
}
//���������
void Free_LinkList(NODE *head)
{
	NODE *p,*q;
	
	p=head;
	while (p->next!=NULL)
	{
		q=p->next;
		p->next=q->next;		//��ɾ��ĳ���ڵ��˼������ 
		free(q);	
	}
	free (head);	
}
int main()
{
	NODE *student,*pnew;
	char order[30];
	int i,score;
	student=Create_LinkList();
	while (scanf("%s",order)!=EOF)		//����ָ�� 	��Ӧָ��ִ�ж�Ӧ���� 
	{
		if (strcmp(order,"display")==0)
			Display_LinkList(student);
		else if (strcmp(order,"insert")==0)
		{
			printf("student&score:");
			scanf("%d%d",&i,&score);
			pnew=Create_NewNode(score);
			Insert_LinkList (student,pnew,i);
		}
		else if (strcmp(order,"delete")==0)
		{
			printf("student:");
			scanf("%d",&i);
			Delete_LinkList(student,i);
		}
		else	printf("error!!\n");
	}
	Free_LinkList(student);
	return 0;
}
