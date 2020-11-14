#include <stdio.h>
#include <string.h>
char copy(char x[]);
int jud(char x[]);
int main()
{
	char s[101],s1[101],max,i;
	
	/*1.录入字符串	ok
	  2.将所有的字符拷贝到副本	ok
	  3.处理副本	ok 
	  	3.1.将副本中的大写传换成小写
			3.2比较副本中的字母大写
      4.打印	ok 
	*/
	while (gets(s)!=NULL)
	{
		memcpy(s1,s,sizeof(char)*101);
		max=copy(s1);
		if (jud (s)==0||strlen(s)>100)	continue;
		for (i=0;s[i]!='\0';i++)
		{
			printf ("%c",s[i]);
			if (s[i]==max)	printf ("(max)");
		}
		printf ("\n");
	}
	return 0;
}
int jud(char x[])
{
	int tf=1;
	for (int i=0;x[i]!='\0';i++)
		{
			if (x[i]<65||x[i]>122||(x[i]>90&&x[i]<97))	{tf=0;break;}
		}
	if (tf==0)	return 0;
	else return 1;
}
char copy(char x[])
{
	int i,temp;
	for (i=0;x[i+1]!='\0';i++)
	{
		if (x[i]>x[i+1])
		{
			temp=x[i];
			x[i]=x[i+1];
			x[i+1]=temp;
		}
	}
	return x[i];
}
