#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int num[500];
	int n;
	while (cin>>n)
	{
		int i,j,key;
		for (i=0;i<n;i++)
		{
			cin>>num[i];
		}
		for (j=1;j<n;j++)
		{
			key=num[j];
			i=j-1;
			while (i>=0&&num[i]<key)		//寻找到已排好的序列中，比key大的第一个位置 
			{
				num[i+1]=num[i];
				i--;
			}
			num[i+1]=key;
		}
		for (i=0;i<n;i++)
		{
			cout<<num[i];
			if (i!=n-1)	cout<<" ";
		}
		cout<<endl;
	}
}
