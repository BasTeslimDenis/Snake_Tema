#include "stdafx.h"
#include "Food.h"
#include <random>


Food::Food()
{
	poz_x = rand() % 28 + 1;
	poz_y = rand() % 28 + 1;
}

Food::~Food()
{
}

void Food::reposition()
{
	poz_x = rand() % 28 + 1;
	poz_y = rand() % 28 + 1;
}

int Food::get_x() {
	return poz_x;
}

int Food::get_y() {
	return poz_y;
}