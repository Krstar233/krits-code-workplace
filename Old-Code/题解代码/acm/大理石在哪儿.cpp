#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10000;
bool myfunction (int i,int j) {return (i>j);}
struct fun1
{
	int x,y;
};
int main()
{
	int n,q,i,x,p;
	int kase=0;
	int a[maxn];

	cin>>n;
	for (i=0;i<n;i++)	cin>>a[i];
	sort(a,a+n,myfunction);
	for (i=0;i<n;i++)	cout<<a[i]<<" ";
}
