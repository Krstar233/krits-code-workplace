/*二分思想.cpp*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	int shop_num,q,i,x,distence,j,start,end;;
	vector<int> shop_price;
	
	scanf("%d",&shop_num);
	for (i=0;i<shop_num;i++)
	{
		scanf("%d",&x);
		shop_price.push_back(x);
	}
	scanf("%d",&q);
	sort (shop_price.begin(),shop_price.end());
	for (i=0;i<q;i++)
	{
		scanf("%d",&x);
		end=shop_num;
		start=-1;			//start和end都要放在数字条的两端之外 
		j=(start+end)/2;
		//下面使用了二分思想 
		while (end-start!=1)
		{
			if (shop_price[j]>x)
			{
				end=j;
			}
			else if (shop_price[j]<=x)
			{
				start=j;
			}							//最后的运行结果：
			j=(start+end)/2;			//start最终会指向不大于x的最后一个数，如果没有就指向最小的数的前一个位置 
										//而end将指向大于x的第一个数，如果没有就指向最大的数的后一个位置  
		}
		printf("%d\n",end);
	}
}
