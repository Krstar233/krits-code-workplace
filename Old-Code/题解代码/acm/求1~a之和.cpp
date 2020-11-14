#include <stdio.h>

int main()
{
	int a,b,c,i;
	double suma=0.00,sumb=0.00,sumc=0.00,sum=0.00;
	
	scanf("%d%d%d",&a,&b,&c);
	for (i=1;i<=a;i++)
		suma+=i;
	for (i=1;i<=b;i++)
		suma+=i*i;
	for (i=1;i<=c;i++)
		suma+=1.00/i;
	sum=suma+sumb+sumc;
	printf("%.2f",sum);	
}
/*input:
1 1 1
100 50 10
  output:
3.00
47977.93
*/
