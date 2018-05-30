#pragma once
class Food
{
	int poz_x, poz_y;
public:
	Food();
	~Food();
	void reposition();
	int get_x();
	int get_y();
};

