#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct matrix{
	int x,y;
	matrix(int x=0, int y=0): x(x), y(y) {}
}m[26];
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string name;
		cin >> name;
		int k = name[0] - 'A';
		cin >> m[k].x >> m[k].y;
	}
	string expr;
	while (cin >> expr){
		stack<matrix> a;
		int ans = 0;
		bool ok = true;
		for (int i = 0; i < expr.length(); i++){
			
			if ('A' <= expr[i] && expr[i] <= 'Z'){
				
				a.push(m[expr[i] - 'A']);
			}else if (expr[i] == ')'){
				matrix a2 = a.top();a.pop();
				matrix a1 = a.top();a.pop();
				if (a1.y == a2.x){
					ans += a1.x * a1.y * a2.y;
					matrix a3(a1.x, a2.y);
					a.push(a3);
				}else{
					cout << "error" << endl;
					ok = false;
					break;
				}
			}
		}
		if (ok)
			cout << ans << endl;		
	}
}
