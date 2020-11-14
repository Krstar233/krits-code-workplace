#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void rule(char &c)
{
	if (c >= 'A' && c <= 'Z')
	{
		if (c <= 'C')
			c = '2';
		else if (c <= 'F')
			c = '3';
		else if (c <= 'I')
			c = '4';
		else if (c <= 'L')
			c = '5';
		else if (c <= 'O')
			c = '6';
		else if (c <= 'S')
			c = '7';
		else if (c <= 'V')
			c = '8';
		else if (c <= 'Y')
			c = '9';
	}
}
int main()
{
	int n;

	while (cin >> n)
	{
		vector<string> tel;
		string s;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			for (int j = 0; j < s.length(); j++)
			{
				if (s[j] == '-')
				{
					s.erase(j,1);
				}
			}
			for (int j = 0; j < s.length(); j++)
			{
				rule (s[j]);
			}
			s.insert(3,"-");
			tel.push_back(s);
		}
		sort(tel.begin(),tel.end());
		int sum = 1;
		string s1;
		string x = tel[0];
		int flag = 0;
		for (int i = 1; i < n; i++)
		{
			if (x.compare(tel[i]) == 0)
			{
				sum++;
			}
			else
			{
				if (sum != 1)
				{
					cout << x << " " << sum << endl;
					flag = 1;
				}
				x = tel[i];
				sum = 1;
			}
			if (i == n - 1)
			{
				if (sum != 1)
				{
					cout << x << " " << sum << endl;
					flag = 1;
				}
			}
		}
		if (flag == 0)
			cout << "No duplicates." << endl;
	}
}
