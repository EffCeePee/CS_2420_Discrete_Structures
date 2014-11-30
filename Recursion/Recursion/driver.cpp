void push (item val)
{
	data [used++] =  val;
}
		
void pop ()
{
	assert(!empty())
		--used;
}

Item Top()
{
	return data[used-1]
}

bool empty()
{
	if used > 0
		return true;
}

