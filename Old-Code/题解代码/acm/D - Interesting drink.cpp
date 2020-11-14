#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main()
{
	int shop_num,q,i,x,distence;
	vector<int> shop_price;
	vector<int>::iterator p;
	
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
		p=upper_bound(shop_price.begin(),shop_price.end(),x);
		distence=p-shop_price.begin();
		printf("%d\n",distence);
	}
}
