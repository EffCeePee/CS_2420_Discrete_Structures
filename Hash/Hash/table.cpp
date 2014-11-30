// FILE: table1.template
// TEMPLATE CLASS IMPLEMENTED: table (see table1.h for documentation)
// INVARIANT for the table ADT:
//   1. The number of records in the table is in the member variable used.
//   2. The actual records of the table are stored in the array data, with
//      a maximum of CAPACITY entries. Each used spot in the array has a 
//      non-negative key. Any unused record in the array has a key field of
//      NEVER_USED (if it has never been used) or PREVIOUSLY_USED (if it once
//      was used, but is  now vacant).

#include <cassert>  // Provides assert
#include "element.h"
#include "table.h" 
#include <string>
#include <iostream>

using namespace main_savitch_12A;

   
    const int CAPACITY;  
    const int NEVER_USED = -1;
    const int PREVIOUSLY_USED;


    table::table( )
    {
        int i;

        used = 0;
        for (i = 0; i < CAPACITY; ++i)
            data[i].key = NEVER_USED;  // Indicates a spot that's never been used.
    }

	table::~table()
	{
		delete [] data;
	}


    
    void table::insert(const element& entry)
    // Library facilities used: cassert
    {
        bool already_present;   // True if entry.key is already in the table
        int index;              // data[index] is location for the new entry

        assert(entry.key >= 0);

        // Set index so that data[index] is the spot to place the new entry.
        find_index(entry.key, already_present, index);

        // If the key wasn't already there, then find the location for the new entry.
        if (!already_present)
        {
            assert(size( ) < CAPACITY);
            index = hash(entry.key);
            while (!is_vacant(index))
                index = next_index(index);
            ++used;
        }

        data[index] = entry;
    }

    
    void table::clear()
    {
		delete [] data;
		table;
    }


    
    bool table::is_present(int key) const
    // Library facilities used: assert.h
    {
        bool found;
        int index;

        assert(key >= 0);

        find_index(key, found, index);
        return found;
    }

    
    void table::find(int key, bool& found, element& result) const
    // Library facilities used: cassert.h
    {
        int index;

        assert(key >= 0);

        find_index(key, found, index);
        if (found)
            result = data[index];
    }

    
    int table::hash(string key) const
    {
        return (key % CAPACITY);
    }

    
    int table::next_index(int index) const
    // Library facilities used: cstdlib
    {
        return ((index+1) % CAPACITY);
    }

    
    void table::find_index(int key, bool& found, int& i) const
    // Library facilities used: cstdlib
    {
	int count; // Number of entries that have been examined

	count = 0;
	i = hash(key);
	while((count < CAPACITY) && (data[i].key != NEVER_USED) && (data[i].key != key))
	{
	    ++count;
	    i = next_index(i);
	}
	found = (data[i].key == key);
    }

    
    bool table::never_used(int index) const
    {
	return (data[index].key == NEVER_USED);
    }
	
    
    bool table::is_vacant(int index) const
    {
	return (data[index].key == NEVER_USED) || (data[index].key == PREVIOUSLY_USED);
    }

	element table::retrieve( ) const
	{

	}
