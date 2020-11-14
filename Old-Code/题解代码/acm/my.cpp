#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include "my.h"
#define PI 3.1415926
using namespace std;

int Fahrenheit_convert_Celsius(int f)
{
	float c;
	
	c=5.0*(f-32.0)/9.0;
	
	return c;
}

void cul_circle_ball(float r, float h)
{
	double c1,sa,sb,va,vb;
	
	c1=2.0*PI*r;
	sa=PI*r*r;
	sb=4.0*PI*r*r;
	va=4.0/3.0*PI*r*r*r;
	vb=sa*h;
	
	printf("C1=%.2f\n",c1);
	printf("Sa=%.2f\n",sa);
	printf("Sb=%.2f\n",sb);
	printf("Va=%.2f\n",va);
	printf("Vb=%.2f\n",vb);
	
}


int add(float a, float b)
{
	float sum;

	sum=a+b;
	
	return sum;
}

void show1()
{
	printf("####\n");
	printf(" ####\n");
	printf("  ####\n");
	printf("   ####\n");
}

int cul_average(float a, float b, float c)
{
	float average;

	average=(a+b+c)/3.0;
	
	return average;
}

void int_cul(int num1, int num2)
{
	printf("%d+%d=%d\n",num1,num2,num1+num2);
	printf("%d-%d=%d\n",num1,num2,num1-num2);
	printf("%d*%d=%d\n",num1,num2,num1*num2);
}

double cul_mortality_rate(int num1, int num2)
{
	double percent;
	
	percent=(float)num2/(float)num1;
	return percent;
}

int cul_digit_sum(int num)
{
	int bai,shi,ge,sum;

	bai=num/100;
	shi=num%100/10;
	ge=num%100%10;
	sum=bai+shi+ge;
	
	return sum;	
}

int cul_area(float r, int n)
{
	float s;
	
	s=n*r*r*sin(2*PI/n)/2.0;
	
	return s;
}

void cul_equation(double a, double b, double c)
{
	double x1,x2;

	x1=(-b+sqrt(b*b-4.0*a*c))/(2.0*a);
	x2=(-b-sqrt(b*b-4.0*a*c))/(2.0*a);
	printf("x1=%.2f x2=%.2f",x1,x2);
}

double cul_abs(double a)
{
	if (a<0)	a=-a;
	
	return a;
}

int exchange(int num)
{
	int ge,shi,bai;

	bai=num/100;
	shi=num%100/10;
	ge=num%100%10;
	
	if (ge==0)
	{
		return shi * 10 + bai;	
	}	
	else
	{
		return bai * 100 + shi * 10 + ge;	
	}
}

double cul_distence(double x1, double y1, double x2, double y2)
{
	double distence;
	
	distence=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	return distence;
}

void print8d(int a, int b, int c)
{	
	printf ("%8d %8d %8d",a,b,c);
}

void ASDQ()
{
	printf ("Menu:A(dd) D(elete) S(ort) Q(uit),select one:\n");
	switch (getchar())
	{
		case 'A':{
			printf ("data is added\n");
			break;
		}
		case 'D':{
			printf ("data is deleted\n");
			break;
		}
		case 'S':{
			printf("data is sorted\n");
			break;
		}
		case 'Q':{
			exit (0);
			break;
		}
	}
}

int cul_profit(int a)
{
	int praise;
	
	if (a<=100000)
		praise=a*0.1;
	else if (a<=200000)
		praise=100000*0.1+(a-100000)*0.075;
	else if (a<=400000)
		praise=100000*0.1+100000*0.075+(a-200000)*0.05;
	else if (a<=600000)
		praise=100000*0.1+100000*0.075+200000*0.05+(a-200000)*0.03;
	else if (a<=1000000)
		praise=100000*0.1+100000*0.075+200000*0.05+200000*0.03+(a-400000)*0.015;
	else praise=100000*0.1+100000*0.075+200000*0.05+200000*0.03+400000*0.015+(a-100000)*0.01;
	
	return praise;
}

void poker(char hua, int num)
{
	if (hua >= 'a' && hua <= 'z')
		hua = hua - ('a' - 'A'); 
	switch (hua)
	{
		case 'A':{
			printf("ºÚÌÒ");
			break;
		}
		case 'B':{
			printf("ºìÌÒ");
			break;
		}
		case 'C':{
			printf("Ã·»¨");
			break;
		}
		case 'D':{
			printf("·½¿é");
			break;
		}
	}
	switch (num)
	{
		case 1:{
			printf("A");
			break;
		}
		case 11:{
			printf("J");
			break;
		}
		case 12:{
			printf("Q");
			break;
		}
		case 13:{
			printf("K");
			break;
		}
		default :{
			printf("%d",num);
			break;
		}
	}
}

void judge_Aa1other(char ch)
{
	if (ch>='A'&&ch<='Z')
	{
		printf("upper");
	}
	else if (ch>='a'&&ch<='z')
	{
		printf("lower");
	}
	else if (ch>='0'&&ch<='9')
	{
		printf("digit");
	}
	else 
	{
		printf("others");
	}
}

void culculate()
{
	int a,b,c,result;
	char cul,equal;
	
	scanf("%d%c%d%c%d",&a,&cul,&b,&equal,&c);
	
	if (equal=='=')
	{
		switch (cul)
		{
			case '+':{
				result=a+b;
				break;
			}
			case '-':{
				result=a-b;
				break;
			}
			case '*':{
				result=a*b;
				break;
			}
			case '/':{
				result=a/b;
				break;
			}
			case '%':{
				result=a%b;
				break;
			}
			default :{
				printf("%d%c%d%c%d error op",a,cul,b,equal,c);
				return 0;
			}
		}
		if (c==result)
		{
			printf("%d%c%d%c%d correct",a,cul,b,equal,c);
		}
		else
		{
			printf("%d%c%d%c%d wrong",a,cul,b,equal,c);
		}
	}
	else printf("%d%c%d%c%d error op",a,cul,b,equal,c);
}

void num_conversion(int x)
{
	switch (x)
	{
		case 1:{
			printf("One");
			break;
		}
		case 2:{
			printf("Two");
			break;
		}
		case 3:{
			printf("Three");
			break;
		}
		case 4:{
			printf("Four");
			break;
		}
		case 5:{
			printf("Five");
			break;
		}
	}
}

int isDivisible(int a, int b)
{
	int ab,ba;
	
	ab=a%b;
	ba=b%a;
	if (ab==0&&ba!=0)
		return 1;
	else if (ba==0&&ab!=0)
		return 2;
	else if (ba==0&&ab==0)
		return 3;
	else
		return 4;
}

void judge_in(int x, int y)
{	
	if (x>=-1&&x<=1)
	{
		if (y>=-1&&y<=1)
		{
			printf ("yes");
		}
		else printf ("no");
	}
	else printf ("no");
}

int jud1 (double a,double b,double c);
int jud2 (double a,double b,double c);
void judge_triangle(double a, double b, double c)
{
	double p,area;
	
	if (a<b+c&&b<a+c&&c<a+b)
	{
		p=(a+b+c)/2;
		area=sqrt(p*(p-a)*(p-b)*(p-c));
		if (jud1(a,b,c)>0)
		{
			if (jud1(a,b,c)==3)	
			{
				printf ("equilateral triangle");
			}
			else if (jud2(a,b,c)==1)	printf ("isosceles right triangle");
			else printf("isosceles triangle");
		}
		else
		{
			if (jud2(a,b,c)==1)	printf ("right triangle");
			else printf ("general triangle");
		}
		printf (", %.1lf\n",area);
	}
	else printf("no triangle\n");
}
int jud1 (double a,double b,double c)
{
	int num=0;
	
	if (fabs(a-b)<0.001)	num++;
	if (fabs(c-b)<0.001)	num++;
	if (fabs(a-c)<0.001)	num++;
	
	return num;
}
int jud2 (double a,double b,double c)
{
	int tof=0;
	
	if (fabs(a*a+b*b-c*c)<0.001)	tof=1;
	if (fabs(c*c+b*b-a*a)<0.001)	tof=1;
	if (fabs(a*a+c*c-b*b)<0.001)	tof=1;
	return tof;
}

void cul1(double x, double y, int a)
{
	printf("%.6lf",x+a%3*(int)(x+y)%2/4);
}

int judge135(int a)
{
	if(a==1||a==3||a==5)
		return 0;
	else
		return 1;
}

void div_with_remain(int a, int b)
{
	printf("%d %d",a/b,a%b);
}

void pay(int yuan)
{
	int yuan100,yuan50,yuan20,yuan10,yuan5,yuan1;
	
	yuan100=yuan/100;
	yuan=yuan%100;
	yuan50=yuan/50;
	yuan=yuan%50;
	yuan20=yuan/20;
	yuan=yuan%20;
	yuan10=yuan/10;
	yuan=yuan%10;
	yuan5=yuan/5;
	yuan=yuan%5;
	yuan1=yuan;
	printf("%d %d %d %d %d %d",yuan100,yuan50,yuan20,yuan10,yuan5,yuan1);
}

void cul_time()
{
	int hour1,min1,s1,hour2,min2,s2,hour3,min3,s3;
	
	scanf("%d:%d:%d",&hour1,&min1,&s1);
	scanf("%d:%d:%d",&hour2,&min2,&s2);
	s3=s1-s2;
	min3=min1-min2;
	hour3=hour1-hour2;
	if (s3<0)	
	{
		s3=60+s3;
		min3--;
	}
	if (min3<0)
	{
		min3=60+min3;
		hour3--;
	}
	printf("%d:%d:%d",hour3,min3,s3);
}

int jud (int x);
int flower(int start, int end)
{
	while (start<=end)
	{
		if (jud(start)==1)	
			printf("%d\n",start);
		start++;
	}
}
int jud (int x)
{
	int ge,shi,bai,result;
	
	bai=x/100;
	shi=x%100/10;
	ge=x%100%10;
	result =ge*ge*ge+shi*shi*shi+bai*bai*bai;
	if (result==x)	return 1;
	else return 0;
}

void cul_Hex()
{
	int a,b,c;
	char cul;
	
	scanf("%x%c%x",&a,&cul,&b);
	switch (cul)
	{
		case '+':{
			c=a+b;
			break;
		}
		case '-':{
			c=a-b;
			break;
		}
	}
	printf("%o\n",c);
}

void jud_return()
{
	int i,n,tof=0;
	char num[20];
	
	tof=0;
	scanf("%s",num);
	n=strlen(num);
	for (i=0;i<n;i++)
	{
		if (num[i]!=num[n-i-1])
		{
			tof=1;
			break;
		}
	}
	if (tof==1)	printf("No\n");
	else printf("Yes\n");
}

int fact_(int n)
{
	int jie=1,i;
	
	for (i=1;i<=n;i++)
	{
		jie*=i;
	}
	return jie;
}

int numa(int a,int i);
int a_aa_aaa(int a, int n)
{
	int i,sum=0;
	
	for (i=1;i<=n;i++)
	{
		sum+=numa(a,i);
	}
	return sum;
}
int numa(int a,int i)
{
	int result=0,k;
	
	for (k=0;k<i;k++)
	{
		result+=a;
		a*=10;
	}
	return result;
}

void show()
{
	printf("####\n");
	printf(" ####\n");
	printf("  ####\n");
	printf("   ####");
}

int cul2(double x)
{
	int n,i;
	
	if (x<0.0)
		x=-x;
		/*input :-15.12 output:15.12*/
	else if (x<1.0)
		x=sin(2.0*x);
		/*input :0 output:0.00*/	
	else if (x<5.0)
		x=sqrt(x*x*x+x);
		/*input :1 output:1.41*/
	else x=2.0*x+10.0;
		/*input :5 output:20.00*/
	return x;
}

int monkey(int n)
{
	int i,sum;
	
	sum=1;
	for (i=1;i<n;i++)
	{
		sum=(sum+1)*2;
	}
	return sum;
}

long long N123sum(int n)
{
	int i,j;
	long long sum,jie;
	
	jie=1;
	sum=0;
	for (i=1;i<=n;i++)
	{
		jie=1;
		for (j=1;j<=i;j++)
		{
			jie*=j;
		}
		sum+=jie;
	}
	return sum;
}

void cul_count()
{
	char c;
	int num,abc,other,space;
	
	num=abc=other=space=0;
	while ((c=getchar())!='\n')
	{
		if (c>='a'&&c<='z')			abc++;
		else if (c>='A'&&c<='Z')	abc++;
		else if (c>='0'&&c<='9')	num++;
		else if (c==' ')			space++;
		else 	other++;
	}
	printf("%d %d %d %d",abc,num,space,other);
}

const int A = 0;
const int B = 1;
const int C = 2;
const int D = 3;
const int not_A = 4;
const int not_B = 5;
const int not_C = 6;
const int not_D = 7;

void print (int x);
int find()
{
	int wrong=4,i,temp;
	int person[4];
	
	while (wrong--)
	{
		person[A]=not_A;
		person[B]=C;
		person[C]=D;
		person[D]=not_D;
		if (wrong==A)
		{
			person[A]=A;
		}
		if (wrong==B)
		{
			person[B]=not_C;
		}
		if (wrong==C)
		{
			person[C]=not_D;
		}
		if (wrong==D)
		{
			person[D]=D;
		}
		for (i=0;i<4;i++)
			if (person[i]<4)	
			{
				temp=person[i];
				break;
			}
		for (i=0;i<4;i++)
		{
			if (temp!=person[i]&&person[i]<4)	break;
			else if (temp==person[i]-4)	break;
		}
		if (i==4)	
		{
			for (i=0;i<4;i++)
				if (person[i]<4)	
				{
					print(person[i]);
					break;
				}
		}
	}
}
void print (int x)
{
	switch (x)
	{
		case 0:	printf("A"); break;
		case 1:	printf("B"); break;
		case 2:	printf("C"); break;
		case 3:	printf("D"); break;
	}
}

int common_num(int a, int b)
{
	int i;
	int max_yue,min_bei;
	
	for (i=1;i<=a*b;i++)
	{
		if (a%i==0&&b%i==0)
		{
			max_yue=i;
		}
		else if (i%a==0&&i%b==0)
		{
			min_bei=i;
			break;
		}
	}
	printf ("%d %d",max_yue,min_bei);
}

int problem_3_add_1(int n)
{
	int n,times;
	
	times=0;
	while (n!=1)
	{
		if (n%2==1)
			n=3*n+1;
		else 	n/=2;
		times++;
	}
	return times;
}

void ball_fall(float m, int n)
{
	double sum=0.00;
		
	while (n--)
	{
		sum+=m;
		m/=2.00;
		if (n!=0)	sum+=m;
	}
	printf("%.2f %.2f",m,sum);
}

double sum1_a(int a, int b, int c)
{
	int i;
	double suma=0.00,sumb=0.00,sumc=0.00,sum=0.00;
	
	scanf("%d%d%d",&a,&b,&c);
	for (i=1;i<=a;i++)
		suma+=i;
	for (i=1;i<=b;i++)
		suma+=i*i;
	for (i=1;i<=c;i++)
		suma+=1.00/i;
	sum=suma+sumb+sumc;
	return sum;
}

int a_k_pow_sum(int n, int k)
{
	int i,j,result=0,an=1,t;

	result=0;
	for(i=1;i<=k;i++)
	{
		an=1;
		for (j=0;j<i;j++)
		{
			an*=n;
		}
		result+=an;
	}
	return result;
}

void power_alph()
{
	char ch,min='z';
	
	while ((ch=getchar())!='\n')
	{
		if (ch<min)
			min=ch;
	}
	printf("%c",min);
}

void jud_perfect_number()
{
	int t,num,i,sum;
	
	scanf("%d",&t);
	while (t--)
	{
		sum=0;
		scanf("%d",&num);
		for (i=1;i<num;i++)
		{
			if (num%i==0)
			{
				sum+=i;
			}
		}
		if (sum==num)
		{
			printf ("yes");
			for (i=1;i<num;i++)
			{
				if (num%i==0)
				{
					printf(",%d",i);
				}
			}
			printf ("\n");
		}
		else 
		{
			printf ("no");
			for (i=1;i<num;i++)
			{
				if (num%i==0)
				{
					printf(",%d",i);
				}
			}
			printf ("\n");
		}
	}
}

int prime_sum()
{
	int n,m,t,i,j,sum;
	
	scanf("%d",&t);
	while (t--)
	{
		sum=0;
		scanf("%d%d",&n,&m);
		for (i=n;i<=m;i++)
		{
			if (i<=1)	continue;
			for (j=2;j*j<=i;j++)
			{
				if (i%j==0)
					break;
			}
			if (j*j>i)
			{
				printf("%d ",i);
				sum+=i;
			}
		
		}
		if (sum==0)	printf("NO\n");
		else 
			printf("\n%d\n",sum);
	}
}

int judge_crash(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
{
		if ((y1<=y3&&y3<=y2)||(y1<=y4&&y4<=y2))
		{
			if ((x1<=x3&&x3<=x2)||(x1<=x4&&x4<=x2))
			{
				return 1;
			}
			else if ((y3<=y1&&y1<=y4)||(y3<=y2&&y2<=y4))
			{
				if ((x3<=x1&&x1<=x4)||(x3<=x2&&x2<=x4))
				{
					return 1;
				}
				else return 0;
			}
			else return 0;
		}
		else if ((y3<=y1&&y1<=y4)||(y3<=y2&&y2<=y4))
		{
			if ((x3<=x1&&x1<=x4)||(x3<=x2&&x2<=x4))
			{
				return 1;
			}
			else return 0;
		}
		else return 0;
	}
}

int diamond_praise(int n, int m, double x, double y, double r)
{
	int i,j,num;
	double dis;
	
	num=0;
	for (i=0;i<=m;i++)
	{
		for (j=0;j<=n;j++)
		{
			dis = sqrt((i-x)*(i-x)+(j-y)*(j-y));
			if (dis<r||fabs(dis-r)<1e-6)
				num++;
		}
	}
	return num;
}

void pyramid(int num, char ch)
{
	int t,i,j,k;
	
	for (i=1;i<=num;i++)
	{
		for (j=0;j<(2*num-1)-(2*i-1);j++)
			printf (" ");
		for (j=0;j<(2*i-1);j++)
			printf ("%c",ch);
		printf("\n");
	}
}

int jud3(int n)
{
	int arrn[8],i=0,k,num=0,n1;
	
	n1=n;
	while (n!=0)
	{
		arrn[i]=n%10;
		n/=10;
		i++;
	}
	for (k=0;k<i;k++)
	{
		num+=arrn[k];
		num*=10;
	}
	num/=10;
	if (num==n1)	return 1;
	else return 0;
}
int jud4(int n)
{
	int i;
	if (n==1)	return 0;
	for (i=2;i*i<=n;i++)
	{
		if (n%i==0)	break;
	}
	if (i*i>n)
		return 1;
	else return 0;
}
int symmetry_prime(int num)
{
	if (jud3(num))
	{
		if (jud4(num))
			return 1;
		else return 0;
	}
	else return 0;
	
}

void figure(int n)
{
	int i,j;
	
	for (i = 1; i <= n; i ++)
	{
		for (j = 0; j < n - i; j ++)
			printf (" ");
		for (j = 0; j < 2 * i - 1; j ++)
			printf ("#");
		printf ("\n");
	}
}

void string_statistics()
{
	int like_A_num = 0, like_a_num = 0, number = 0;
	char ch;
	
	while ((ch = getchar ()) != '#')
	{
		if (ch >= 'A' && ch <= 'Z')	like_A_num ++;
		if (ch >= 'a' && ch <= 'z')	like_a_num ++;
		if (ch >= '0' && ch <= '9') number ++;
	}
	printf ("%d\n",like_A_num);
	printf ("%d\n",like_a_num);
	printf ("%d\n",number);
}

void choose()
{
	int t;
	int num, len, d, sign, max_len, min_d, max_sign;
	int i;
	
	scanf ("%d", &num);
	scanf ("%d%d%d",&len, &d, &sign);
	max_len = len;
	min_d = d;
	max_sign = sign;
	for (i = 1; i < num; i ++)
	{
		scanf ("%d%d%d",&len, &d, &sign);
		if (max_len < len)
		{
			max_len = len;
			min_d = d;
			max_sign = sign;
		}
		if (len == max_len)
		{
			if (min_d > d)
			{
				min_d = d;
				max_sign = sign;
 			}
			if (d == min_d)
			{
				if (max_sign < sign)
				{
					max_sign = sign;
				}
			}
		}
	}
	printf ("%d\n",max_sign);
}

void string_secret()
{
	int k, b, len, i;
	char ch[5015];
	
	while (scanf ("%d %d", &k, &b) != EOF)
	{
		getchar ();
		gets (ch);
		len = strlen (ch);
		for (i = 0; i < len; i ++)
		{
			if (ch[i] >= 'A' && ch[i] <= 'Z')
			{
				ch[i] = ch[i] - 'A';
				ch[i] = ( k * ch[i] + b ) % 26;
				ch[i] = ch[i] + 'A';
			}
			if (ch[i] >= 'a' && ch[i] <= 'z')
			{
				ch[i] = ch[i] - 'a';
				ch[i] =( k * ch[i] + b ) % 26;
				ch[i] = ch[i] + 'a';
			}
		}
		puts (ch);
	}
}

void arr_divisible(int num [20])
{
	int i, j;
	
	for (i = 0; i < 20; i ++)
	{
		for (j = 0; j < 20; j ++)
		{
			if (i != j)	
			{
				if (num [i] % num [j] == 0)
				{
					printf ("%d\n", num [i]);
					break;
				}
			}
		}
	}
}

double dog_belly(int n, char trc, int a, int b)
{
	int n,i,a,b;
	double s, max_s;
	char trc;

	max_s = 0;
	for (i = 0; i < n; i ++)
	{
		if (trc == 'T')
		{
			s = (a * b) / 2.0;
		}
		else if (trc == 'R')
		{
			s = a * b;	
		}
		else if (trc == 'C')
		{
			s = a * a * PI;
		}
		if (max_s < s)	max_s = s;
		while (getchar () != '\n');
	}
	return max_s;
}

int nagetive_number_count(int num[10])
{
	int i,sum;
	
	sum = 0;
	for (i = 0; i < 10; i ++)
	{
		if (num[i] < 0) sum ++;
	}	
	return sum;
}

void arr_common(int a[6], int b[8])
{
	int i,j;
	
	for (i=0;i<6;i++)
	{
		for (j=0;j<8;j++)
		{
			if (a[i]==b[j])
			{
				printf ("%d\n",a[i]);
			}
		}
	}
}

void array_add(int a[15][15], int b[15][15], int n, int m)
{
	int i,j;
	int c[15][15];
	
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			scanf ("%d",&a[i][j]);
		}
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			scanf ("%d",&b[i][j]);
		}
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
			printf ("%d",c[i][j]);
			if (j!=m-1)	printf (" ");
		}
		printf ("\n");
	}
}

void bubble_sort(int num[], int n)
{
	int i,j,k,tmp;

	for (i=0;i<n;i++)
	{
		for (j=0;j<n-i-1;j++)
		{
			if (num[j]>num[j+1])
			{
				tmp=num[j];
				num[j]=num[j+1];
				num[j+1]=tmp;
			}
		}
		if (i==0)
		{
			for (k=0;k<n;k++)
			{
				printf ("%d",num[k]);
				if (k!=n-1) printf (" ");
			}
			printf ("\n");
		}
	}
	for (i=0;i<n;i++)
	{
		printf ("%d",num[i]);
		if (i!=n-1) printf (" ");
	}
	printf ("\n");
}

void choose_sort()
{
	int t,n,i,j,k,min,tmp,flag;
	int num[20];
			
	scanf ("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
		}
		for (i=0;i<n-1;i++)
		{
			min=num[i];
			flag=i;
			for (j=i;j<n;j++)
			{
				if (num[j]<min)
				{
					min=num[j];
					flag=j;
				}
			}
			tmp=num[i];
			num[i]=num[flag];
			num[flag]=tmp;
			for (k=0;k<n;k++)
			{
				printf("%d",num[k]);
				if (k!=n-1)	printf (" ");
			}
			printf ("\n");
		}
	}
}

void odd_even_sort()
{
	int t,n,i,j,flag,tmp,tag;
	int num[500];
	
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
		}
		flag=0;
		for (i=0;i<n;i++)
		{
			if (num[i]%2!=0)
			{
				flag=0;
				for (j=i;j<n;j++)
				{
					if (num[j]%2==0)
					{
						tag=j;
						flag=1;
					}
				}
				if (flag==0)	break;
				tmp=num[i];
				num[i]=num[tag];
				num[tag]=tmp;
			}
		}
		printf("%d ",n);
		for (i=0;i<n;i++)
		{
			printf ("%d",num[i]);
			if (i!=n-1)	printf (" ");
		}
		printf ("\n");
	}
}

void arr_statistics()
{
	int t;
	int n,num[35];
	int zheng,fu,more_aver,less_aver,min,max;
	int aver;
	
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		int i;
		aver=0;
		max=0;
		more_aver=0;
		less_aver=0;
		fu=0;
		zheng=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
		}
		min=num[0];
		for(i=0;i<n;i++)
		{
			if (min>=num[i])	min=num[i];
			if (max<=num[i])	max=num[i];
			aver+=num[i];
		}
		aver/=n;
		for (i=0;i<n;i++)
		{
			if (num[i]>aver)	more_aver++;
			if (num[i]<aver)	less_aver++;
			if (num[i]>0)	zheng++;
			if (num[i]<0)	fu++;
		}
		printf ("%.2f %d %d\n",(float)aver,more_aver,less_aver);
		printf ("%d %d\n",zheng,fu);
		printf ("max=%d min=%d\n\n",max,min);
	}
}

void arr_delete()
{
	int n,x;
	int num[10],total,flag;
	
	scanf("%d",&n);
	while (n--)
	{
		int i,j;
		total=10;
		flag=0;
		for (i=0;i<10;i++)
		{
			scanf("%d",&num[i]);
		}
		scanf ("%d",&x);
		for (i=0;i<10;i++)
		{
			if (x==num[i])
			{
				total--;
				flag=1;
				for (j=i;j<total;j++)
				{
					num[j]=num[j+1];
				}
			}
		}
		if (flag==0)
		{
			printf ("Not found\n");
			continue;
		}
		else
		{
			for (i=0;i<total;i++)
			{
				printf ("%d",num[i]);
				if (i!=total-1)	printf (" ");
			}
			printf("\n");
		}
	}
}

void common_item()
{
	int t;
	int num[3][100],com[100];
	int n[3];
	
	scanf("%d",&t);
	while (t--)
	{
		int i,j,k,q;
		int x;
		int flag1,flag2;
		int c_com=0;
		for (i=0;i<3;i++)
		{
			scanf ("%d",&n[i]);
			for (j=0;j<n[i];j++)
			{
				scanf ("%d",&num[i][j]);
			}
		}
		for (i=0;i<n[0];i++)
		{
			flag1=flag2=0;
			x=num[0][i];
			for (j=0;j<n[1];j++)
			{
				if (x==num[1][j])
				{
					for (q=0;q<c_com;q++)
					{
						if (x==com[q])	break;
					}
					if (q==c_com)
					{
						flag1=1;
					}
				}
			}
			for (k=0;k<n[2];k++)
			{
				if (x==num[2][k])
				{
					for (q=0;q<c_com;q++)
					{
						if (x==com[q])	break;
					}
					if (q==c_com)
					{
						flag2=1;
					}
				}
			}
			if (flag1==1&&flag2==1)
			{
				com[c_com]=x;
				c_com++;	
			}
		}
		sort(com,com+c_com);
		printf ("%d:",c_com);
		for (i=0;i<c_com;i++)
		{
			printf ("%d",com[i]);
			if (i!=c_com-1)	printf (" ");
		}
		printf ("\n");
	}
}

void Magic_square_matrix()
{
	int t;
	int num[500][500];
	
	scanf("%d",&t);
	while (t--)
	{
		int n;
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
		int tmp;
		int flag = 0;
		scanf("%d",&n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d",&num[i][j]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			sum1 = 0;
			for (int j = 0; j < n; j++)
			{
				sum1 += num[i][j];
			}
			if (i == 0)	tmp = sum1;
			else if (tmp != sum1)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			printf ("NO\n");
			continue;
		}
		for (int j = 0; j < n; j++)
		{
			sum2 = 0;
			for (int i = 0; i < n; i++)
			{
				sum2 += num[i][j];
			}
			if (j == 0)	tmp = sum2;
			else if (tmp != sum2)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			printf ("NO\n");
			continue;
		}
		for (int i = 0; i < n; i++)
		{
			sum3 += num[i][i];
			sum4 += num[i][n - i - 1];
		}
		if (sum3 != sum4)	flag = 1;
		else if (!(sum1 == sum2 && sum1 == sum3))
			flag = 1;
		if (flag == 1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}

void insert_in_array(int num[10])
{
	int n = 10;
	int i = 0;
	
	while (i < 8 && num[i] == num[i+1] )	i++;
	if (i == 8) {}
	else if (num[i] < num[i + 1])
	{
		for (int k = n - 1; k > 0; k--)
		{
			int tmp = 0;
			if (num[k] < num[k - 1])
			{
				tmp = num[k];
				num[k] = num[k - 1];
				num[k - 1] = tmp;
			}
		}
	}
	else if (num[i] > num[i + 1])
	{
		for (int k = n - 1; k > 0; k--)
		{
			int tmp = 0;
			if (num[k] > num[k - 1])
			{
				tmp = num[k];
				num[k] = num[k - 1];
				num[k - 1] = tmp;
			}
		}
	}
	
	for (int k = 0; k < n; k++)
	{
		printf ("%d\n",num[k]);
	}
}

void Joseph_ring(int n)
{
	int num;
	bool flag[500] = {0};
	int i = 0;
	int sum = 0;

	num = n;
	while (1)
	{
		sum++;
		if (num == 1)	
			break;
		if (sum % 3 == 0)
		{
			flag[i] = 1;
			num--;
			printf ("%d ",i + 1);
		}
		i++;
		if (i == n) i = 0;
		while (flag[i] != 0)
		{
			i++;
			if (i == n)	
			{
				i = 0;
			}
		}
	}
	printf ("\n%d",i + 1);
}

void dig_26_num(int N)
{
	char str[50][105];

	for (int i = 0; i < N; i++)
	{
		gets(str[i]);
	}
	for (int i = 0; i < N - 1; i++)
	{
		char *min = str[i];
		char tmp[105];
		for (int j = i + 1; j < N; j++)
		{
			if (strlen(min) > strlen(str[j]))
				min = str[j];
			else if (strlen(min) == strlen(str[j]))
			{
				if (strcmp(min, str[j]) < 0)
					min = str[j];
			}
		}
		strcpy(tmp, min);
		strcpy(min, str[i]);
		strcpy(str[i], tmp);
	}
	for (int i = 0; i < N; i++)
	{
		puts(str[i]);
	}
}

void Matrix_rotation()
{
	char a[12][12];
	int n,m;
	
	scanf("%d %d",&n, &m);
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = getchar();
			getchar();
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			printf ("%c",a[j][i]);
			if (j != 0) printf(" ");
		}
		printf ("\n");
	}
}

int check1(int a[500][500], int i, int j, int n)
{
	int min = a[i][j];
	int k; 
	for (k = 0; k < n; k++)
		if (min > a[k][j])
			break;
	if (k == n)	return 1;
	else return 0;
}
void Saddle_point()
{
	int t;
	int num[500][500];
	int n,m;
	
	scanf("%d",&t);
	while (t--)
	{
		int flag = 0;
		scanf("%d%d",&n, &m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d",&num[i][j]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			int max = num[i][0];
			int max_j = 0;
			for (int j = 0; j < m; j++)
			{
				if (max < num[i][j])
				{
					max = num[i][j];
					max_j = j;
				}
			}
			if (check1(num, i, max_j, n) == 1)
			{
				printf("%d %d\n",i, max_j);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			printf ("-1\n");
	}
}

int Max(int a[10][10], int n, int j);
int Sum(int a[10][10], int n, int j);
void Matrix_max_sum()
{
	int t, n;
	int a[10][10];
	
	scanf("%d",&t);
	while (t--)
	{
		int sum = 0;
		scanf("%d",&n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for (int j = 0; j < n; j++)
		{
			printf ("%d %d\n",Max(a, n, j), Sum(a, n, j));
		}
	}
}
int Max(int a[10][10], int n, int j)
{
	int jmax = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i][j] > jmax)
		{
			jmax = a[i][j];
		}
	}
	return jmax;
}
int Sum(int a[10][10], int n, int j)
{
	int jsum = 0;
	for (int i = 0; i < n; i++)
	{
		jsum += a[i][j];
	}
	return jsum;
}

void change_string()
{
	char s[1005];
	
	while (gets(s))
	{
		int slen = strlen (s);
		for (int i = 0; i < slen -  2; i++)
		{
			if (s[i] == 'y' && s[i + 1] == 'o' && s[i + 2] == 'u')
			{
				s[i] = 'w';
				s[i + 1] = 'e';
				for (int j = i + 2; j < slen - 1; j++)
				{
					s[j] = s[j + 1];
				}
				slen--;
				s[slen] = '\0';
			}
		}
		puts(s);
	}
}

void IDcard()
{
	char s[20];
	int t;
	
	scanf("%d",&t);
	getchar();
	while (t--)
	{
		int sum = 0;
		int n;
		char last;
		gets(s);
		for (int i = 14; i > 5; i--)
		{
			s[i + 2] = s[i];
		}
		s[6] = '1';
		s[7] = '9';
		for (int i = 0; i < 17; i++)
		{
			s[i] -= '0';
		}
		sum = s[0] * 7 + s[1] * 9 + s[2] * 10 + s[3] * 5 +s[4] * 8 + s[5] * 4 + s[6] * 2 + s[7] * 1 
			+ s[8] * 6 + s[9] * 3 + s[10] * 7 + s[11] * 9 + s[12] * 10 + s[13] * 5 + s[14] * 8 + s[15] *4 + s[16] * 2;
		n = sum % 11;
		last = (12 - n) % 11;
		if (last == 10)	last = 'X';
		else last += '0';
		s[17] = last;
		for (int i = 0; i < 17; i++)
		{
			s[i] += '0';
		}
		s[18] = '\0';
		puts(s);
	}
}

void add(char a[], char b[], char c[]);
void long_long_long()
{
	int t;
	char a[1005], b[1005], c[1005];
	int Case = 0;
	
	scanf("%d",&t);
	getchar();
	while (t--)
	{
		Case++;
		scanf("%s",a);
		scanf("%s",b);
		add(a, b, c);
		printf("Case %d:\n",Case);
		printf("%s + %s = %s\n",a, b, c);
		if (t != 0) printf ("\n");
	} 
}
void add(char a1[], char b1[], char c[])
{
	char res[1005];
	char t[1005];
	char a[1005], b[1005];
	strcpy(a, a1);
	strcpy(b, b1);
	int alen = strlen(a);
	int blen = strlen(b);
	int len;
	char tmp;
	int flag = 0;
 	if (blen > alen)
 	{
 		strcpy(t, b);
 		strcpy(b, a);
 		strcpy(a, t);
	}
	alen = strlen(a);
	blen = strlen(b);
	len = alen;
	for (int i = 0; i < alen; i++)
		a[i] -= '0';
	for (int i = 0; i < blen; i++)
		b[i] -= '0';
	for (int i = 0; i < len; i++)
	{
		if (alen - i - 1 >= 0 && blen - i - 1 >= 0)
		{
			if (flag == 1)
			{
				tmp = a[alen - i - 1] + b[blen - i - 1] + 1;
				flag = 0;
			}
			else tmp = a[alen - i - 1] + b[blen - i - 1];
			if (tmp / 10 > 0)
				flag = 1;
			tmp = tmp % 10;
			res[i] = tmp;
		}
		else
		{
			if (flag == 1)
			{
				tmp = a[alen - i - 1] + 1;
				flag = 0;
			}
			else tmp = a[alen - i - 1];
			if (tmp / 10 > 0)
				flag = 1;
			tmp = tmp % 10;
			res[i] = tmp;
		}
	}
	if (flag == 1)
	{
		res[len] = 1;
		len++;
		flag = 0;
	}
	for (int i = 0; i < len; i++)
	{
		c[i] = res[len - i - 1];
		c[i] += '0';
	}
	c[len] = '\0';
	for (int i = 0; i < alen; i++)
		a[i] += '0';
	for (int i = 0; i < blen; i++)
		b[i] += '0';
}

void apple_ming()
{
	int N;
	int a[10];
	int x;
	
	scanf("%d",&N);
	while (N--)
	{
		int tall = 30;
		int flag;
		int i;
		for (i = 0; i < 10; i++)
			scanf("%d",&a[i]);
		sort(a, a + 10);
		scanf("%d",&x);
		tall += x;
		for (i = 0; i < 10; i++)
		{
			if (a[i] > tall)
				break;
		}
		printf ("%d\n",i);
	}
}

void Minesweeping()
{
	int n,m;
	char a[105][105];
	
	while (scanf("%d%d",&n, &m) != EOF)
	{
		getchar();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				a[i][j] = getchar();
			}
			getchar();
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] != '*')
				{
					a[i][j] = '0';
					if (i - 1 >= 0 && a[i - 1][j] == '*')
						a[i][j]++;
					if (i + 1 < n && a[i + 1][j] == '*')
						a[i][j]++;
					if (j - 1 >= 0 && a[i][j - 1] == '*')
						a[i][j]++;
					if (j + 1 < m && a[i][j + 1] == '*')
						a[i][j]++;
					if (i - 1 >= 0 && j - 1 >= 0 && a[i - 1][j - 1] == '*')
						a[i][j]++;
					if (i - 1 >= 0 && j + 1 < m && a[i - 1][j + 1] == '*')
						a[i][j]++;
					if (i + 1 < n && j - 1 >= 0 && a[i + 1][j - 1] == '*')
						a[i][j]++;
					if (i + 1 < n && j + 1 < m && a[i + 1][j + 1] == '*')
						a[i][j]++;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf ("%c",a[i][j]);
			}
			printf ("\n");
		}
	}
}

float fact(int n);
int Cmn(int m, int n)
{
	return (int)(fact(m) / (fact(n) * fact(m - n)));
}
float fact(int n)
{
	int result = 1;
	
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

int isprime(int n);
int m_n_prime_sum(int m, int n)
{
	int sum = 0;
	
	for (int i = m; i <= n; i++)
	{
		if (isprime(i))
		{
			sum += i;
		}
	}
	return sum;
}
int isprime(int n)
{
	int i;
	if (n == 1 || n == 0)
		return 0;
	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}


struct point
{
	int x, y;
	point(int a, int b){
		x = a;
		y = b;
	}
};
int check3(point a);
void in_or_out()
{
	int n;
	
	scanf("%d",&n);
	while (n--)
	{
		int x, y;
		
		scanf("%d%d",&x, &y);
		point a(x, y);
		
		if (check3(a))
			printf ("in\n");
		else
			printf ("out\n");
	}
}
int check3(point a)
{
	if (a.x >= 1 && a.x <= 5)
	{
		if (a.y >= 1 && a.y <= 5)
		{
			return 1;
		}
	}

	return 0;
}
