#include <stdio.h>

int main()
{
	int a[100],b[100],c[100],n,m,i,j,t,l,temp;	//a[],b[]�ֱ��ʾ����A�ͼ���B;c[]��ʾ A-B 
	
	while (scanf("%d%d",&n,&m)!=EOF)
	{
	if (n==0&&m==0)
	{
		break;
	}
	for (i=0;i<n;i++)	scanf("%d",&a[i]);	//���뼯��A
	for (i=0;i<m;i++)	scanf("%d",&b[i]);	//���뼯��B
	l=0;
	//������ִ��A-B�Ĳ���
	for (i=0;i<n;i++)
	{
		t=0;
		for (j=0;j<m;j++)
		{
			if (a[i]==b[j])	t=-1;	//����ڼ��з��ּ���A�е�Ԫ�ؼ���B��Ҳ�У�������¼���� 
		}
		if (t==0)	//���û��������ͬԪ��(˵�����Ԫ���Ǽ���A-B�е�һ��)�������������Ԫ�ؼ���c[]�� 
		{
			c[l]=a[i];
			l++;
		}
	}
	if (l==0)	printf("NULL");		//���û�м�¼��A-B���ǿռ����Ǿ����NULL 
	else
	{
		//���½�c[]�е�Ԫ�ذ���С�������� 
		for (j=0;j<l-1;j++)
		{
			for (i=0;i<l-j-1;i++)
			{
				if (c[i]>c[i+1])
				{
					temp=c[i];
					c[i]=c[i+1];
					c[i+1]=temp;
				}
			}
		}
		//��ӡc[]
		for (i=0;i<l;i++)	printf("%d ",c[i]); 
	}
	printf ("\n");
	}
}
