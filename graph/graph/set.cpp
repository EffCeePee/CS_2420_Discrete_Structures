#include "set.h"


set::set(void)
{
	l = new List();
}


set::~set()
{
	l->~List();
	l = NULL;

}

bool set::is_in(int d)
{
	return l->find(d);
}

void set::insert(int d)
{
	if(is_in(d) == false )
	{
		l->insert(d);
	}
}