#include <iostream>
using namespace std;
int main()
{
	long long Y, B;
	long long y, g, b;
	cin >> Y >> B;
	cin >> y >> g >> b;
	
	long long need_Y = y * 2 + g - Y;
	long long need_B = g + 3 * b - B;
	long long result = 0;
	if (need_Y > 0)
		result += need_Y;
	if (need_B > 0)
		result += need_B;
	
	cout << result;
	
}
