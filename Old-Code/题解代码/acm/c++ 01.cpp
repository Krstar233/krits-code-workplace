#include <iostream>
using namespace std;

struct Point{
	int x, y;
	Point(int x=0, int y=0): x(x), y(y) {}
};

Point operator + (const Point &a, const Point &b){
	return Point(a.x+b.x, a.y+b.y);
}

ostream& operator << (ostream &out, const Point &a){
	out << "(" << a.x << "," << a.y << ")";
}
int main()
{
	Point a, b(1, 2);
	cout << a << endl;
	a.x = 3;
	b = a + b;
	cout << b << endl;
	return 0;
}
