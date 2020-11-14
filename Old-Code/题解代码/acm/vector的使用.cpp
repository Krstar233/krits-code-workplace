#include <iostream>
#include <vector>
using namespace std;
void print (vector<int> &v)
{
	int i;
	for (i=0;i<v.size();i++)
	cout<<v[i]<<endl;
}
int main()
{
	int i;
	vector<int> v;
	vector<int>::iterator position;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	print (v);
	position=v.begin()+2;
	cout<<"------"<<endl;
	v.insert(v.begin()+2,3);
	print(v);
}
