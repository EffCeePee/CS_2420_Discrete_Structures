#include "Heap.h"
#include <iostream>
#include <iomanip>
using namespace heap_1;
using namespace std;


heap::heap()
{
	heapArray = new int[size];
	used = 0;
	index = 1;
}

heap::~heap()
{
	delete [] heapArray;
	heapArray = nullptr;

}

void heap::print()
{
	for(int i = 1; i <= used; i++)
	{
		cout << heapArray[i] << " ";
	}

	cout << endl;
}

void heap::insert(int num)
{
	if(used == 0)
	{
		heapArray[1] = num;
		used++;
		index++;
	}
	else if(used == size-1)
	{
		cout << "the heap is full" << endl;
	}
	else
	{
		
		index = used +1;
		heapArray[index] = num;
		used++;
	

		while(heapArray[(index/two)] < heapArray[index] && (index/two) != 0)
		{
				
			swap(heapArray[(index/two)],heapArray[index]);
			index = (index/two);
				
		}
	}

}

int heap::remove_front()
{
	if(used == 0)
	{
		cout << "the heap is empty" << endl;
		return 0;
	}
	else
	{
		index = 1;
		swap(heapArray[index], heapArray[used]);

		int temp = heapArray[used];
		heapArray[used] = NULL;
		used--;

		while(heapArray[index] < heapArray[(index * two) +1] || (heapArray[index] < heapArray[(index * two)]))
		{
			if(heapArray[index * two] > heapArray[(index * two) +1])
			{
				if(heapArray[index] < heapArray[index*two])
				{
					swap(heapArray[index], heapArray[index*two]);
					index = index*two;
				}
			}

			else if(heapArray[index * two] < heapArray[(index * 2)+1])
				{
					swap(heapArray[index], heapArray[(index*two)+1]);
					index = (index*two) + 1;
					
				}
			}
		

		return temp;

	}
}

void heap::swap(int &a, int &b)
{
	int temp;

	temp = a;
	a = b;
	b =  temp;
}



void heap::print_tree(int index, int size)
{
	cout <<::setw(4*size) << ""; // indentation
	if(index > size)
	{
		cout << "[Empty]" << endl;
	}
	else if (heapArray[index * two] > size && heapArray[(index * two) + 1] > size)
	{
		cout << heapArray[index];
		cout << "[Leaf]" << endl;
	}
	else
	{
		cout << heapArray[index] << endl;
		print_tree(heapArray[index * two], size+1);
		print_tree(heapArray[(index * two)+1], size+1);
	}

}

int heap::get_size()
{
	return size;
}