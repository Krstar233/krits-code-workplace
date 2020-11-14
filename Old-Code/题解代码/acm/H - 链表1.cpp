#include <iostream>
using namespace std;

char data[100000];
int nxt[100000];
int total = 1;
int tail = 0;
int cur = 0;

void back_add(char ch)
{
	data[total] = ch;
	nxt[total] = -1;
	nxt[tail] = total;
	tail = total;
	total++;
}
void cur_add(char ch)
{
	data[total] = ch;
	nxt[total] = nxt[cur];
	nxt[cur] = total;
	cur = nxt[cur];
	total++;
}
int main()
{
	char ch;
	bool endadd = true;
	nxt[0] = -1;
	data[0] = 0;
	while (scanf("%c", &ch) != EOF)
	{
		if (ch == '\n')
		{
			for (int i = nxt[0]; i != -1; i = nxt[i])
			{
				printf ("%c", data[i]);
			}
			cout << endl;
			nxt[0] = -1;
			total = 1;
			tail = 0;
			cur = 0;
			data[0] = 0;
			endadd = true;
			continue;
		}
		else if (ch == '[')
		{
			if (total != 1)
				endadd = false;
			cur = 0;
			continue;
		}
		else if (ch == ']')
		{
			endadd = true;
			continue;
		}
		
		if (endadd)
		{
			back_add(ch);
		}
		else
		{
			cur_add(ch);
		}
	}
}
