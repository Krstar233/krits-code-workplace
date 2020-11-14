#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

double atoF(string s) {
	double res = 0;
	bool point = false;
	bool nagative = false;
	int wei = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '.') {
			point = true;
			continue;
		}
		if (s[i] == '-') {
			nagative = true;
			continue;
		}
		if (point)	wei++;
		res *= 10;
		res += s[i] - '0';
	}
	while (wei--)	res *= 0.1;
	if (nagative)
		res *= -1;
	return res;
}

double fabs(double x) {
	if (x < 0)
		return -x;
	return x;
}

int main() {
	int t;

	cin >> t;
	cin.get();

	while (t--)
	{
		stack<string> cul;
		stack<double> val;
		string s;
		getline(cin, s);

		string s2 = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ') {
				s2 += s[i];
			}
			else{
				cul.push(s2);
				s2 = "";
			}
		}cul.push(s2);
		
		while (!cul.empty())
		{
			string s1 = cul.top(); cul.pop();
			if (s1 == "+" || s1 == "-" || s1 == "*" || s1 == "/") {
				double a = val.top(); val.pop();
				double b = val.top(); val.pop();
				double c;
				if (s1 == "+")
					c = a + b;
				if (s1 == "-")
					c = a - b;
				if (s1 == "*")
					c = a * b;
				if (s1 == "/")
					c = a / b;

				val.push(c);
			}
			else{
				val.push(atoF(s1));
			}
		}
		double res = val.top(); val.pop();
		if (fabs(res - 0) < 1e-6)
			res = 0;

		cout << fixed << setprecision(6) << res << endl;
	}
}