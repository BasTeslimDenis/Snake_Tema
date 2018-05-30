#include "stdafx.h"
#include "Snake.h"
#include "Body.h"


Snake::Snake(int x, int y)
{
	snake_body = new Body(x,y-1);
}

Snake::Snake()
{
}


Snake::~Snake()
{
	delete snake_body;
}

void Snake::movement(int x, int y, char key)
{
	if (key == 'w' || key == 'W')
		poz_y += 1;
	else if (key == 'd' || key == 'D')
		poz_x += 1;
	else if (key == 's' || key == 'S')
		poz_y -= 1;
	else if (key == 'a' || key == 'A')
		poz_x -= 1;
}

int Snake::current_x()
{
	return poz_x;
}

int Snake::current_y()
{
	return poz_y;
}

void Snake::start_up(int x, int y)
{
	poz_x = x;
	poz_y = y;
}
