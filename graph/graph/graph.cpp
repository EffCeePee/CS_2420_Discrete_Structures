// Franklin Colton Parry
// Course: CS 2420
// Instructor:  Peterson
// File: graph.cpp
// Date 12/12/13

/* I Colton Parry have not used any code other than my own
(or that in the text book) for this project.   I also 
have not used any function or datat-structure from the 
Standard-Template Library.  I understand that any
violation of this disclaimer will result in a 0 for the project.
*/

#include "graph.h"
#include <cassert>
#include <iostream>

using namespace graph_1;
using namespace std;

graph::graph()
{
	edges[MAXIMUM][MAXIMUM];
	many_vertices = 0;
}


graph::~graph(void)
{

}

void graph::add_vertex(const int& label)
	{
        int new_vertex_number;
        int other_number;

        assert(size( ) < MAXIMUM);
        new_vertex_number = many_vertices;
        many_vertices++;
        for (other_number = 0; other_number < many_vertices; ++other_number)
        {
            edges[other_number][new_vertex_number] = -1;
            edges[new_vertex_number][other_number] = -1;
        }
        labels[new_vertex_number] = label;
    }

void graph::add_edge(int row, int column, int weight)
{
	    {
        assert(row < size( ));
        assert(column < size( ));
        edges[row][column] = weight;
    }
}

int graph::get_weight(int row, int column)
{
	return  edges[row][column];
}

bool graph::is_edge(int row, int column) const
	{
        assert(row < size( ));
        assert(column < size( ));
        if(edges[row][column] != -1)
		{
			return true;
		}
		else
		{
			return false;
		}

    }

void graph::depth_first(int col)
{
	int row = 0;
	bool marked[MAXIMUM];
	
	cout << col << " ";
	for(col = 0; col < size(); col++)
	{
		if(is_edge(row, col))
		{
			marked[row] = true;
			help_d_f(col, marked);
		}
		
	}

}

void graph::help_d_f(int row, bool marked[])
{
	int col = 0;
	if(marked[row] == false);
		cout << row << " ";

	for(col = 0; col < size(); col++)
	{
		if(is_edge(row, col))
		{
			marked[col] = true;
			help_d_f(col,marked);
		}
	}


}

