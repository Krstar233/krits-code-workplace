#include <stdio.h>
#include <string.h>
/*		C�ĺϷ���ʶ�� ��
	1.ֻ�������ֺ���ĸ�Լ��»�����ɣ�
	2.��һ���ַ�����Ϊ��ĸ���»��ߣ� 
	3.�����ǹؼ��֣�				*/ 
int jud1(char x);
int jud2(char x);

int main()
{
	int i,t_or_f,n,k;
	char variate[50];
	
	scanf("%d",&n);
		if (n>=50||n<=0)	return 0;
		for (k=0;k<n;k++)
		{
			scanf("%s",variate);
			i=0;t_or_f=1;
		if (jud1(variate[0])==0)	{printf("no\n");continue;}
		while (variate[i]!='\0')
		{
			if (jud2(variate[i])==0)	{t_or_f=-1;break;}
			i++;
		}
		if (t_or_f==-1)	printf("no\n");
		else printf("yes\n");
		memset(variate,0,sizeof(variate));
		}
		n=0;k=0;memset(variate,0,sizeof(variate));
		
}
int jud1(char x)
{
	if (x=='_')	return 1;
	else if (x>='A'&&x<='Z')	return 1;
	else if (x>='a'&&x<='z')	return 1;
	else return 0;
}
int jud2(char x)
{
	if (x=='_')	return 1;
	else if (x>='A'&&x<='Z')	return 1;
	else if (x>='a'&&x<='z')	return 1;
	else if (x>='0'&&x<='9')	return 1;
	else return 0;
}

