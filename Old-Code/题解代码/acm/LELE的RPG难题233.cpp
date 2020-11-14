#include <iostream>
#include <cstdio>
using namespace std;
static int first_color,count_way = 0;
int check_box (int this_color,int index,int last_color,int total)
{
	if (index != total || (index == total && total == 1))
	{
		if (this_color == last_color)	return 0;
		else return 1;
	}
	else
	{
		if (this_color == first_color)	return 0;
		else if (this_color == last_color)	return 0;
		else return 1;
	}
}
void box (int index,int last_color,int total)
{
	int color;
	
	for (color = 0;color < 3;color ++)
	{
		if (index == 1)	first_color = color;
		if (check_box (color,index,last_color,total))
		{
			if (index == total)
			{
				count_way ++;
			}
			else box (index + 1,color,total);
		}
	}
	return;
}
int main()
{
	int num;
	
	while (~scanf("%d",&num))
	{
		count_way = 0;
		box (1,-1,num);
		cout << count_way << endl;
	}
}
