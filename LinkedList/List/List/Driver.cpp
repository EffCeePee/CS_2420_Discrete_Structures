#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "list.h"  
using namespace std;
using namespace list_1;

int main()
{

	list test;

	test.insert_front(10);
	test.add_back(20);
	test.add_back(30);

	cout << test.head->data << endl;
	cout << test.head->next->data << endl;
    cout << test.head->next->next->data << endl;

	test.remove_all(30);

	cout << test.head->data << endl;
	cout << test.head->next->data << endl;

	

	
	system("PAUSE");
	return 0;
}
