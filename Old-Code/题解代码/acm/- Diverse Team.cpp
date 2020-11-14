#include <stdio.h>

int main()
{
	int n,k,j,h=0,tof;
	int a[115],i,ans[115]={0},ans_[115]={0};
	
	scanf("%d%d",&n,&k);
	for (i=0;i<n;i++)
	{
		tof=0;
		scanf("%d",&a[i]);
		for (j=0;j<k;j++)
		{
			if (a[i]==ans[j])	tof=1;
		}
		if (tof==0&&h<k)
		{
			ans[h]=a[i];
			ans_[h]=i+1;
			h++;
		}
	}
	if	(h==k)
	{
		printf("YES\n");
		for (j=0;j<k;j++)
		{
			printf("%d ",ans_[j]);
		}
	}
	else printf("NO");
}
