#include "stdafx.h"
#include "Body.h"


Body::Body()
{
	next = NULL;
}

Body::Body(int x, int y)
{
	poz_x = x;
	poz_y = y;
}


Body::~Body()
{
	delete next;
}

Body * Body::AddNewTail(Body *head, int poz_x, int poz_y)
{
	Body *Temp = new Body();
	if (head->next == NULL) {
		head->poz_x = poz_x;
		head->poz_y = poz_y; 
		Temp->next = head;
	}
	else if (head->next != NULL) {
		Temp->next = head;
		Temp->poz_x = poz_x;
		Temp->poz_y = poz_y;
	}
	return Temp;
}

