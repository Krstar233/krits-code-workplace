#include <iostream>
using namespace std;
int main(){
	int i = 5;
	int j = 6;
	int a[] = { 1,2,3,4,5 };

	for (int i : a) {
		cout << i << endl;
	}
	cout << "hello world" << endl;
	system("pause");
}