#include <iostream>

#include "List.h"

using namespace std;
/*
Создайте шаблонный класс односвязного списка для работы с целыми значениями. Требуется создать реализации для типичных операций над элементами:

AddToHead – добавление элемента в голову
AddToTail – добавление элемента в хвост
DeleteFromHead – удаление элемента из головы
DeleteFromTail – удаление элемента из хвоста
DeleteAll – удаление всех элементов
Show – отображение всех элементов списка на экран
.....



Добавить в класс из задания 1 следующие функции: 
1. вставка элемента в заданную позицию,
2. удаление элемента по заданной позиции,
3. поиск заданного элемента (функция возвращает позицию найденного элемента в случае успеха или NULL в случае неудачи),
4. поиск и замена заданного элемента (функция возвращает количество замененных элементов в случае успеха или -1 в случае неудачи), 
5. переворот списка.


*/
int main()
{
	/////////////////////////////////////////////////

 //   List list;

 //  char string[] = "Hello world!";
 //   for (unsigned int i = 0U; i < strlen(string); ++i)
 //   {
 //       list.Add(string[i]);////   void Add(const char data);
 //   }
 //   list.Print();
/////////////////////////////////////////////////////////////////////
	////Node* new_nd = new Node('Q');
	////list.Add(new_nd);//////void Add(Node * new_node);
	//List list2 = list;
	//list2.Print();
	//List list3;
	////list3.Assign(list);
	////list3.Print();
	//list3 = list;
	//list3.Print();
	//cout << list3.GetSize() << endl;


    List list;
    list.AddToHead(new Node('a'));
    list.AddToHead(new Node('b'));
    list.AddToHead(new Node('c'));

    cout << "After add to head ";
    list.Print();


    list.Add(new Node('X'));
    list.Add(new Node('Y'));
    list.Add(new Node('Z'));

    cout << "After add to tail: ";
    list.Print();


    list.DeleteFromHead();
    cout << "After delete from head: ";
    list.Print();

    list.DeleteFromTail();
    cout << "After delete from tail: ";
    list.Print();

    // Удаляем все элементы
    list.RemoveAll();
    cout << "delete all: ";
    list.Print();


    return 0;
}