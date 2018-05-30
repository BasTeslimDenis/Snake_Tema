#pragma once
#include "Body.h"
#include <iostream>

using namespace std;
class Snake:public Body
{
	int poz_x, poz_y;
	Body * snake_body;
public:
	Snake(int=15,int=15);
	Snake();
	~Snake();
	void movement(int x, int y, char key);
	int current_x();
	int current_y();
	void start_up(int,int);
};

