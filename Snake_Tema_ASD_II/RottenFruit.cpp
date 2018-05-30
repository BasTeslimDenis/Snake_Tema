#include "stdafx.h"
#include "RottenFruit.h"
#include "Food.h"
#include <random>


RottenFruit::RottenFruit()
{
	x = rand() % 28 + 1;
	y = rand() % 28 + 1;
		
}


RottenFruit::~RottenFruit()
{
}

int RottenFruit::get_x()
{
	return x;
}

int RottenFruit::get_y()
{
	return y;
}

void RottenFruit::reposition()
{
	x = rand() % 28 + 1;
	y = rand() % 28 + 1;
}

