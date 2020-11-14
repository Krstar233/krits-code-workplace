#include <iostream>
#include <limits.h>
using namespace std;
void MERGE(int A[],int p,int q,int r)
{
	int n1,n2;
	int i,j,k;
	
	n1=q-p+1;
	n2=r-q;
	int L[n1+1],R[n2+1];
	for (i=0;i<n1;i++)
	{
		L[i]=A[p+i];
	}
	for (i=0;i<n2;i++)
	{
		R[i]=A[q+i+1];
	}
	L[n1]=INT_MAX;
	R[n2]=INT_MAX;
	i=j=0;
	for (k=p;k<=r;k++)
	{
		if (L[i]>R[j])
		{
			A[k]=R[j];
			j++;
		}
		else
		{
			A[k]=L[i];
			i++;
		}
	}
}
void MERGE_SORT(int A[],int p,int r)
{
	if (p<r)
	{
		int q=(r+p)/2;
		MERGE_SORT(A,p,q);
		MERGE_SORT(A,q+1,r);
		MERGE(A,p,q,r);
	}
}
int main()
{
	int A[500];
	int n;
	
	while (cin>>n)
	{
		for (int i=0;i<n;i++)
		{
			cin>>A[i];
		}
		MERGE_SORT(A,0,n-1);
		for (int i=0;i<n;i++)
		{
			cout<<A[i];
			if (i!=n-1)	cout<<" ";
		}
		cout<<endl;
	}
}
