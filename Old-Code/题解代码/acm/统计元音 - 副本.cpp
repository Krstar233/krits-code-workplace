#include <stdio.h>
#include <string.h>

int main ()
{
	char sen[120];
	int i,j,n,a,e,_i,o,u,k;
	
	scanf("%d",&n);
	while (getchar()!='\n');
	for (j=0;j<n;j++)
	{
		gets(sen);
		a=e=_i=o=u=0;
		k=strlen(sen);
		for (i=0;i<k;i++)
		{
			if (sen[i]=='a')	a++;
			if (sen[i]=='e')	e++;
			if (sen[i]=='i')	_i++;
			if (sen[i]=='o')	o++;
			if (sen[i]=='u')	u++;
		}
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a,e,_i,o,u);
		if (j!=n-1)	printf("\n");
	}
	return 0;
}