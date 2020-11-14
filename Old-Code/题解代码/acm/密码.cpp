#include <stdio.h>
#include <string.h>
int jud_A(char c);
int jud_a(char c);
int jud_1(char c);
int jud_ch(char c);
int jud_other(char c);

int main()
{
	int m,i,len,j,tof[5];
	char password[51];
	
	scanf("%d\n",&m);
	for (i=0;i<m;i++)
	{
		memset(tof,0,sizeof(tof));
		gets(password);
		len=strlen(password);
		if (len<8||len>16)	
		{
			printf("NO\n");
			continue;
		}
		for (j=0;j<len;j++)
		{
			if (jud_A(password[j])==1)	tof[0]=1;
			if (jud_a(password[j])==1)	tof[1]=1;
			if (jud_1(password[j])==1)	tof[2]=1;
			if (jud_ch(password[j])==1)	tof[3]=1;
			if (jud_other(password[j])==1)	tof[4]=1;	
		}
		if (tof[0]+tof[1]+tof[2]+tof[3]>=3&&tof[4]!=1)	printf("YES\n");
			else printf("NO\n");
	}
}
int jud_A(char c)
{
	if (c>='A'&&c<='Z')	return 1;
		else return 0;
}
int jud_a(char c)
{
	if (c>='a'&&c<='z')	return 1;
		else return 0;
}
int jud_1(char c)
{
	if (c>='0'&&c<='9')	return 1;
		else return 0;
}
int jud_ch(char c)
{
	if (c=='~'||c=='!'||c=='@'||c=='#'||c=='$'||c=='%'||c=='^')	return 1;
		else return 0;
}
int jud_other(char c)
{
	if (jud_A(c)==0&&jud_a(c)==0&&jud_1(c)==0&&jud_ch(c)==0)	return 1;
		else return 0;
}
