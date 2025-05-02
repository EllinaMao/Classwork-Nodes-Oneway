#include <iostream>

#include "List.h"

using namespace std;

int main()
{
	///////////////////////////////////////////////

    List list;

   char string[] = "Hello world!";


 

    for (unsigned int i = 0U; i < strlen(string); ++i)
    {
        list.Add(string[i]);////   void Add(const char data);
    }

    list.Print();

	

	////////////////////////////////////////////////////////////////////
		

	//Node* new_nd = new Node('Q');

	//list.Add(new_nd);//////void Add(Node * new_node);




	List list2 = list;
	list2.Print();
	List list3;

	//list3.Assign(list);
	//list3.Print();
	list3 = list;
	list3.Print();
	cout << list3.GetSize() << endl;



    return 0;
}