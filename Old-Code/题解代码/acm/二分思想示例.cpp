/*����˼��.cpp*/
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
		start=-1;			//start��end��Ҫ����������������֮�� 
		j=(start+end)/2;
		//����ʹ���˶���˼�� 
		while (end-start!=1)
		{
			if (shop_price[j]>x)
			{
				end=j;
			}
			else if (shop_price[j]<=x)
			{
				start=j;
			}							//�������н����
			j=(start+end)/2;			//start���ջ�ָ�򲻴���x�����һ���������û�о�ָ����С������ǰһ��λ�� 
										//��end��ָ�����x�ĵ�һ���������û�о�ָ���������ĺ�һ��λ��  
		}
		printf("%d\n",end);
	}
}
