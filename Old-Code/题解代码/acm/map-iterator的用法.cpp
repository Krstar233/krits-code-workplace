#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int seq_num,i,x,seq_lon,a1,a2,b1,b2;
	map<int,vector<int> > sequences;
	map<int,vector<int> >::iterator p1;
	vector<int>::iterator p,iter;
	map<int,vector<int> > changed;
	vector<int> sum;
	
	scanf("%d",&seq_num);
	sum.push_back(0);
	for (i=1;i<=seq_num;i++)
	{
		sum.push_back(0);
		scanf("%d",&seq_lon);
		while (seq_lon--)
		{
			scanf("%d",&x);
			sequences[i].push_back(x);
			sum[i]+=x;
		}
	}
	for (i=1;i<=seq_num;i++)
	{
		for (p=sequences[i].begin();p!=sequences[i].end();p++)
		{
			x=sum[i]-(*p);
			for (p1=changed.begin();p1!=changed.end();p1++)
			{
				if ((*p1).first != i)
				{
					iter = find ((*p1).second.begin(),(*p1).second.end(),x);
					if (iter != (*p1).second.end())	break;
				}
			}
			if (p1==changed.end())
				changed[i].push_back(x);
			else
			{
				a1=i;
				a2=p-(sequences[i]).begin()+1;
				b1=(*p1).first;
				b2=iter-(*p1).second.begin()+1;
				cout<<"YES"<<endl<<a1<<" "<<a2<<endl<<b1<<" "<<b2<<endl;
				return 0;
			}
		}
	}
	cout<<"NO";
}
