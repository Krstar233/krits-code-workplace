#include <iostream>
#include <algorithm>
using namespace std;

bool compare(const int& a, const int& b){
	return a > b;
}
int main(){
	int a[] = {1,2,4,6,3,4,6,8,42,3,4,564,54,65,45};
	sort(a, a+15, compare);
	for (int i = 0; i < 15; i++){
		cout << a[i] << endl;
	}
}
