#pragma once

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;

class Search
{
public:
	bool sequential_find(int num);
	bool recursive_binary_find(int num);
	bool recursive_binary_find(int num, int low, int high);
	bool iterative_binary_find(int num);

	void init_array();
	void init_sorted_array();
	void set_seed(int seed);
	int getSize();

	// this is just for practice and debugging.
	friend ostream& operator<< (ostream& out, const Search& s)
	{
		// put the code in here.
		for(int i = 0; i < s.size; i++)
		{
			out << s.array[i] << " "; 
		}
		return out;
	};

	Search(int size,int seed=0);
	~Search();

private:

	int size;
	int* array;
	
};

