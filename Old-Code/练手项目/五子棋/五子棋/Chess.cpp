#include "Chess.h"



Chess::Chess()
{
}

Chess::Chess(int type)
{
	this->type = type;
	if (type == 1) {
		this->name = "����";
	}
	else if (type == 2) {
		this->name = "����";
	}
}


Chess::~Chess()
{
}
