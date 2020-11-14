#include <stdio.h>
#include <math.h>
double distence(int x1,int y1,int x2,int y2);
double hailun(double a1,double a2,double a3);

int main()
{
	int x[100],y[100],n,i;
	double a,b,c,s;
	
	while (scanf("%d",&n)!=EOF)
	{
		s=0.0;
		if (n==0)	break;
			else if (n<3||n>100)	continue;
		for	(i=0;i<n;i++)
			scanf("%d%d",&x[i],&y[i]);
		//以下计算多边形面积 
		for (i=1;i<n-1;i++)
		{
			a = distence(x[0],y[0],x[i],y[i]);
			b = distence(x[0],y[0],x[i+1],y[i+1]);
			c = distence(x[i],y[i],x[i+1],y[i+1]);
			s += hailun(a,b,c);
		}
		printf ("%.1lf\n",s);
	}
}

double distence(int x1,int y1,int x2,int y2)	//输入两点坐标 
{
	double dis;
	
	dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	return dis;
}

double hailun (double a1,double a2,double a3)//输入三角形三边 
{
	double area,p;
	
	p=(a1+a2+a3)/2.0;
	area=sqrt(p*(p-a1)*(p-a2)*(p-a3));
	return area;
}
