// Franklin Colton Parry
// Course: CS 2420
// Instructor:  Peterson
// File: driver.cpp
// Date 12/12/13

/* I Colton Parry have not used any code other than my own
(or that in the text book) for this project.   I also 
have not used any function or datat-structure from the 
Standard-Template Library.  I understand that any
violation of this disclaimer will result in a 0 for the project.
*/
#include <iostream>
#include "set.h"
using namespace std;
using namespace graph_1;

//prototype
void short_dist(graph,int);

int main()
{

	graph g;
	

	g.add_vertex(0);
	g.add_vertex(1);
	g.add_vertex(2);
	g.add_vertex(3);
	g.add_vertex(4);
	g.add_vertex(5);


	for(int i = 0; i < g.size(); i++)
	{
		for(int j = 0; j < g.size(); j++)
		{
			g.add_edge(i,j,-1);
		}

	}
	
	
	g.add_edge(0,1,2);
	g.add_edge(0,5,9);
	g.add_edge(1,2,8);
	g.add_edge(1,3,15);
	g.add_edge(1,5,6);
	g.add_edge(2,3,1);
	g.add_edge(4,2,7);
	g.add_edge(4,3,3);
	g.add_edge(5,4,3);




	cout << "Depth First Search" << endl;
	g.depth_first(0);

	cout << endl;
	
	short_dist(g,0);


	system("PAUSE");
	return 0;
}


//void short_dist(graph,int)


void short_dist(graph g, int start)
{


// step one initialize the distance array
const int SIZE = 20;
int distance[SIZE];
int predecessor[SIZE];
int sum = 0;
int v = 0;

for(int i = 0; i < g.size(); i++)
	{
	  distance[i] = -1;	
	}

// step two initialize the set of allowed verticies to be the empty set

set * s = new set();


// step three compute the complete distance array

for(int i = 1; i < g.size(); i++)
{
	for(v; v < g.size(); v++)
	{
		if( ( s->is_in(v) == false && g.is_edge(v, i) == true))
		
		
		sum = distance[v] + 1;
		if(sum < distance[v])
			distance[v] = sum;
			predecessor[v] = i;

	}


}

// step four  print out the distance from the star to v

int vertex_on_path = v;

cout << vertex_on_path << endl;
	while(vertex_on_path != start) 
	{
		vertex_on_path = predecessor[vertex_on_path];
		cout << vertex_on_path << endl;
	}



}