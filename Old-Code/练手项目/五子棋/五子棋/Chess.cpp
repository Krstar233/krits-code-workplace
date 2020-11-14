#include "Chess.h"



Chess::Chess()
{
}

Chess::Chess(int type)
{
	this->type = type;
	if (type == 1) {
		this->name = "ºÚÆå";
	}
	else if (type == 2) {
		this->name = "°×Æå";
	}
}


Chess::~Chess()
{
}
