// Franklin Colton Parry
// Course: CS 2420
// Instructor:  Peterson
// File: graph.h
// Date 12/12/13

/* I Colton Parry have not used any code other than my own
(or that in the text book) for this project.   I also 
have not used any function or datat-structure from the 
Standard-Template Library.  I understand that any
violation of this disclaimer will result in a 0 for the project.
*/

#pragma once
#ifndef GRAPH_H
#define GRAPH_H

namespace graph_1
{
    class graph
    {
    public:
        // MEMBER CONSTANTS
        static const int MAXIMUM = 20;
        // CONSTRUCTOR
        graph( );
		graph(int, int);
		~graph( );

        // MEMBER FUNCTIONS
        void add_vertex(const int& label);
        void add_edge(int row, int column, int weight);
        
        //int& operator [ ] (int vertex);
        // CONSTANT MEMBER FUNCTIONS
        int size( ) const { return many_vertices; };
		bool is_edge(int row, int column) const;
		int get_weight(int row, int column);

		// depth first search functions
	    void depth_first(int);
		void help_d_f(int, bool []);

       

    private:

		// member variables
        int edges[MAXIMUM][MAXIMUM];
        int labels[MAXIMUM];
        int many_vertices;
		

    };
}

#endif