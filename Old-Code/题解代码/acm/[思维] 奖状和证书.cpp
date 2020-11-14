#include <stdio.h>

int main()
{
	int student,k,praise_a,praise_b,no_praise,max_praise,real_praise;
	
	scanf("%d%d",&student,&k);
	max_praise = student / 2;
	for (praise_a = 0,real_praise = 0;real_praise <= max_praise; praise_a++)
	{
		praise_b = k * praise_a;
		real_praise = praise_a + praise_b;
	}
	praise_a-=2;
	praise_b = k*praise_a;
	real_praise = praise_a + praise_b;
	no_praise = student - real_praise;
	printf("%d %d %d",praise_a,praise_b,no_praise);
}
