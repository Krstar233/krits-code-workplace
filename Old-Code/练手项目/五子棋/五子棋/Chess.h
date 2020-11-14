#include <string>
#pragma once
using namespace std;
class Chess
{
	int type;
	string name;
public:
	Chess();
	Chess(int type);
	int getType() { return type; }
	~Chess();
};