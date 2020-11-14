#include <stdio.h>

int main()
{
	int a,praise;
	
	scanf("%d",&a);
	switch (a)
	{
		case (a<=100000):{
			praise=a*0.1;
			printf("%d",praise)
			break;
		}
		case (a<=200000):{
			praise=100000*0.1+(a-100000)*0.075;
			break;
		}
		case (a<=400000):{
			praise=100000*0.1+100000*0.075+(a-200000)*0.05;
			break;
		}
		case (a<=600000):{
			praise=100000*0.1+100000*0.075+200000*0.05+(a-400000)*0.03;
			break;
		}
		case (a<=1000000):{
			praise=100000*0.1+100000*0.075+200000*0.05+200000*0.03+(a-600000)*0.015;
			break;
		}
		default :{
			praise=100000*0.1+100000*0.075+200000*0.05+200000*0.03+400000*0.015+(a-1000000)*0.01;
			break;
		}
	}
	printf("%d",praise);
}
