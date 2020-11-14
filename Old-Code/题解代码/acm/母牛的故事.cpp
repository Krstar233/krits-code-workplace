#include <stdio.h>

int main()
{
	int n,cow,calf[60],t_cow,i;//"calf" is girl calf
	
	while (scanf("%d",&n)!=EOF)
	{
		if (n<=0||n>=55)	continue;
		t_cow=1;
		for (cow=1,i=2;i<=n;i++)
		{
			if (i>4) cow=cow+calf[i-3];
			calf[i]=cow;
			t_cow+=calf[i];
		}
		printf("%d\n",t_cow);
	}
	return 0;
}
