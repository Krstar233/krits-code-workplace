#include <iostream>
#include <queue>
using namespace std;

int main(){
	int a[] = {1,3,5,3,4};
	priority_queue<int> q;
	for (int i = 0; i < 5; i++){
		q.push(a[i]);
	}
	while (!q.empty()){
		int tmp = q.top();
		q.pop();
		cout << tmp << endl;
	}
}
