#include <iostream>
using namespace std;

class Date
{
	int year,month,day;
	
	public:
		Date (int x,int y,int z);
		Date () {cout<<"ok!\n";}
		~Date () {};
		void Set(int x,int y,int z);
		void Print();
		friend void fun(Date x);
		
};
void fun(Date x)
{
	int a;
	a=x.year;
}
Date::Date(int x,int y,int z)
{
	Set(x,y,z);
	cout<<"ok\n";
}
void Date::Print()
{
	cout << year << "/" << month << "/" << day << endl;
}
void Date::Set(int x,int y,int z)
{
	year=x;
	month=y;
	day=z;
}
int main()
{
	Date D1;
	Date D2(2018,11,11);
	
	D2.Print();
	D1.Set(2000,1,1);
	D1.Print();
}
