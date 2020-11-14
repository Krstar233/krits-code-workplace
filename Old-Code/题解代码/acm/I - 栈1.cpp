#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int main()
{
	int t;
	char ch1[10], ch2[10];
	
	while (cin >> t)
	{
		int io[1000];
		int out;
		int in = 0;
		int key = 0;
		bool flag = true;
		stack<char> train;
		scanf(" %s %s", ch1, ch2);
		out = strlen(ch2) - 1;
		in = strlen(ch1) - 1;
		while (in >= 0)
		{
			while (true)
			{
				train.push(ch1[in--]);
				io[key++] = 1;
				if (train.size() != 0 && train.top() == ch2[out])
				{
					break;
				}
				if (in < 0)
					break;
			}
			if (train.size() != 0)
			{
				if (train.top() == ch2[out])
				{
					train.pop();
					out--;
					io[key++] = 0;
				}
				else
				{
					flag = false;
				}
			}
		}
		if (flag)
		{
			cout << "Yes." << endl;
			for (int i = 0; i < key; i++)
			{
				if (io[i] == 1)
				{
					cout << "in" << endl;
				}
				else
				{
					cout << "out" << endl;
				}
			}
		}
		else
		{
			cout << "No." << endl;
		}
		cout << "FINISH" << endl;
	}
}
