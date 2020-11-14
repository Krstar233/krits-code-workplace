#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	int *p;
	while (t--){
		int n;
		
		cin >> n;
		
		try{
			p = new int[n];
		}catch( const bad_alloc& e ){
			return -1;
		}
		delete[] p;
	}
}
