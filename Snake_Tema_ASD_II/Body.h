#pragma once
class Body

{	protected:
		int poz_x, poz_y;
	private:
		Body* next;
	public:
		Body();
		Body(int, int);
		~Body();
		Body * AddNewTail(Body*, int, int);
};

