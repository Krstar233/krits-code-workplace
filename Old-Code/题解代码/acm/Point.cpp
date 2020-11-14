#include <iostream>
using namespace std;

template <typename T>
struct Point{
	T x, y;
	Point(T x=0, T y=0): x(x), y(y) {}
};

template <typename T>
Point<T> operator + (const Point<T> &a, const Point<T> &b){
	return Point<T>(a.x+b.x, a.y+b.y);
}

template <typename T>
ostream& operator << (ostream &out, const Point<T> &a){
	out << "(" << a.x << "," << a.y << ")";
}
