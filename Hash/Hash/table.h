// FILE: table1.h (part of the namespace main_savitch_12A)
// TEMPLATE CLASS PROVIDED: table<RecordType> (a table of records with keys).
//    This class is a container template class for a table of records.
//    The template parameter, RecordType, is the data type of the records in the
//    table. It may be any of the bulit-in C++ types (int, char, etc.), or a
//    class with a default constructor, an assignment operator, and an integer
//    member variable called key.
// 
// MEMBER CONSTANT for the table<RecordType> class:
//   static const size_type CAPACITY = ________
//     table<RecordType>::CAPACITY is the maximum number of records held by a table.
//
// CONSTRUCTOR for the table<RecordType> template class:
//   table( )
//     Postcondition: The table has been initialized as an empty table.
//
// MODIFICATION MEMBER FUNCTIONS for the table<RecordType> class:
//   void insert(const RecordType& entry)
//     Precondition: entry.key >= 0. Also if entry.key is not already a key in
//     the table, then the table has space for another record
//     (i.e., size( ) < CAPACITY).
//     Postcondition: If the table already had a record with a key equal to
//     entry.key, then that record is replaced by entry. Otherwise, entry has
//     been added as a new record of the table.
//
//   void remove(int key)
//     Postcondition: If a record was in the table with the specified key, then
//     that record has been removed; otherwise the table is unchanged.
//
// CONSTANT MEMBER FUNCTIONS for the table<RecordType> class:
//   bool is_present(const Item& target) const
//     Postcondition: The return value is true if there is a record in the
//     table with the specified key. Otherwise, the return value is false.
//
//   void find(int key, bool& found, RecordType& result) const
//     Postcondition: If a record is in the table with the specified key, then
//     found is true and result is set to a copy of the record with that key.
//     Otherwise found is false and the result contains garbage.
//
//    size_type size( ) const
//      Postcondition: Return value is the total number of records in the
//      table.
//
//  VALUE SEMANTICS for the table<RecordType> template class:
//    Assignments and the copy constructor may be used with table objects.

#ifndef TABLE1_H
#define TABLE1_H

#include <string>
#include <iostream>
#include "element.h"


namespace main_savitch_12A
{
    
    class table
    {
    public:
        // MEMBER CONSTANT -- See Appendix E if this fails to compile.
        static const int CAPACITY = 811;
        // CONSTRUCTOR
        table( );
		// DESTRUCTOR
		~table();
        // MODIFICATION MEMBER FUNCTIONS
        void insert(const element& entry);
        void clear();
        // CONSTANT MEMBER FUNCTIONS
        bool is_present(int key) const;
        void find(int key, bool& found, element& result) const;
        int size( ) const { return used; }
		element retrieve( ) const;
    private:
        // MEMBER CONSTANTS -- These are used in the key field of special records.
        static const int NEVER_USED = -1;
        static const int PREVIOUSLY_USED = -2;
        // MEMBER VARIABLES
        element data[CAPACITY];
        int used;
        // HELPER FUNCTIONS
        int hash(string key) const;
        int next_index(int index) const;
        void find_index(int key, bool& found, int& index) const;
        bool never_used(int index) const;
        bool is_vacant(int index) const;
    };
}
#include "table1.template" // Include the implementation.
#endif