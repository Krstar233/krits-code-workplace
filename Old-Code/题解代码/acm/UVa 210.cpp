#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
deque<deque<string> > waiting;
deque<deque<string> > zuzhi;
vector<map<string, int> > com_nums;
int q;
bool lock = false;
int which_lock = 100;
int Int(deque<string> &com) {
	string s = com.back();
	int ans = s[0];
	return ans;
}
int Int(string s) {
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		int a = s[i] - '0';
		ans *= 10;
		ans += a;
	}
	return ans;
}
void dealwith(string s, int which_com) {
//	cout << which_com << ":" << s << endl;
	waiting.front().pop_front();
	if (s == "lock") {
		if (lock && which_com != which_lock) {
			deque<string> cur_com = waiting.front();
			waiting.pop_front();
			zuzhi.push_back(cur_com);
			q = 0;
			return;
		}
		else {
			lock = true;
			which_lock = which_com;
		}
	}
	else if (s == "unlock") {
		if (!zuzhi.empty()) {
			deque<string> first_zuzhi = zuzhi.front();
			zuzhi.pop_front();
			waiting.push_front(first_zuzhi);
			lock = false;
			return;
		}
		lock = false;
	}
	else if (s == "end") {
		waiting.pop_front();
	}
	else {
		vector<string> detail;
		string de_s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ') {
				de_s += s[i];
			}
			else {
				detail.push_back(de_s);
				de_s.clear();
			}
		}
		detail.push_back(de_s);
		if (detail[0] == "print") {
			cout << which_com + 1 << ": " << com_nums[which_com][detail[1]] << endl;
		}
		else {
			com_nums[which_com][detail[0]] = Int(detail[2]);
		}
	}
	if (!waiting.empty()) {
			waiting.push_back(waiting.front());
			waiting.pop_front();
		}
}

int main() {
	int n, Q;
	vector<int> ts;

	cin >> n;
	for (int i = 0; i < 5; i++) {
		int t;
		cin >> t;
		ts.push_back(t);
	}
	cin >> Q;
	getchar();

	for (int i = 0; i < n; i++) {
		string s;
		deque<string> com;
		map<string, int> m;
		com_nums.push_back(m);
		while (getline(cin, s)) {
			com.push_back(s);
			if (s == "end") {
				break;
			}
		}
		s.clear();
		s += i;
		com.push_back(s);
		waiting.push_back(com);
	}
	while (!waiting.empty()) {
		q = Q;
		while (q--) {
			string s = waiting.front().front();
			dealwith(s, Int(waiting.front()));
		}
	}
}
