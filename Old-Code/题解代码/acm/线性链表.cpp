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
	
	head=(NODE *)malloc(sizeof(NODE));	//创建头节点 
	if (head==NULL)
	{
		printf("no enough memory!\n");	//创建失败则返回 
		return (NULL);
	}
	head->next=NULL;					//头结点的指针域置NULL 
	tail=head;							//开始时尾指针指向头结点 
	
	printf("input the score of students:\n");
	while (1)							//创建学生成绩线性链表 
	{
		scanf("%d",&score);				//输入学生成绩 
		if (score<0)					//成绩为负，循环退出 
			break;
		pnew=(NODE *)malloc(sizeof(NODE));	//创建新节点 
		if (pnew==NULL)
		{
			printf ("no enough memory!\n");
			return (NULL);
		}
		pnew->score=score;			//新节点数据域放输入的学生成绩 
		pnew->next=NULL;			//新节点指针域置NULL 
		
		tail->next=pnew;			//新节点插入到链表尾 
		tail=pnew;					//尾指针指向当前的尾节点 
	}
	return (head);					//返回创建的链表的头指针
}
//将新节点(pnew所指向的节点)插入到以head为头指针的链表的第i个节点之后
void Insert_LinkList (NODE *head,NODE *pnew,int i)
{
	NODE *p;
	int j;
	
	p=head;
	for (j=0;j<i&&p!=NULL;j++)		//将p指向第i个节点 
		p=p->next;
	if (p==NULL)					//表明第i个节点不存在 
	{
		printf ("the %d node not found!\n",i);
		return;
	}
	pnew->next=p->next;				//将插入节点的指针域指向第i个节点的后继节点 
	p->next=pnew;					//将第i个节点的指针域指向插入节点 
}
//删除以head为头指针的链表的第i个节点 
void Delete_LinkList(NODE *head,int i)
{
	NODE *p,*q;
	int j;
	
	if (i==0)						//是头指针就不能删除，则返回 
		return;
	p=head;
	for (j=1;j<i&&p->next!=NULL;j++)
		p=p->next;					//将p指向要删除的第i个节点的前驱节点 
	if (p->next==NULL)				//表明第i个节点不存在 
	{
		printf ("the %d node not found!",i);
		return ;
	}
	
	q=p->next;
	p->next=q->next;
	free(q);
} 
//创建一个新节点
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
//输出链表 
void Display_LinkList(NODE *head)
{
	NODE *p;
	
	for (p=head->next;p!=NULL;p=p->next)
		printf ("%d ",p->score);
	printf ("\n");
}
//链表的销毁
void Free_LinkList(NODE *head)
{
	NODE *p,*q;
	
	p=head;
	while (p->next!=NULL)
	{
		q=p->next;
		p->next=q->next;		//跟删除某个节点的思想类似 
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
	while (scanf("%s",order)!=EOF)		//输入指令 	对应指令执行对应操作 
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
