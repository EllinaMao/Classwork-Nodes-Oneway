#pragma once

#include "Node.h"
/*
Создайте шаблонный класс односвязного списка для работы с целыми значениями. Требуется создать реализации для типичных операций над элементами:

AddToHead – добавление элемента в голову
AddToTail – добавление элемента в хвост
DeleteFromHead – удаление элемента из головы
DeleteFromTail – удаление элемента из хвоста
DeleteAll – удаление всех элементов
Show – отображение всех элементов списка на экран




Добавить в класс из задания 1 следующие функции:
1. вставка элемента в заданную позицию,
2. удаление элемента по заданной позиции,
3. поиск заданного элемента (функция возвращает позицию найденного элемента в случае успеха или NULL в случае неудачи),
4. поиск и замена заданного элемента (функция возвращает количество замененных элементов в случае успеха или -1 в случае неудачи),
5. переворот списка.
*/
class List
{
private:

    // Адрес головного элемента списка.
    Node * m_head=nullptr;

    // Количество элементов списка.
    unsigned int m_size=0;

public:

    List();
    List(const List& list);

    ~List();

    List& operator=(const List& right);

    // Добавление элемента в список (новый элемент становится в конец списка).
    void Add(const char data);
    void Add(Node* new_node);

    void AddToHead(Node* new_node);

    // Получить элемент списка по индексу.

    void Assign(const List& list);

    // Распечатка содержимого списка (распечатка начинается с головного элемента).
    void Print() const;

    // Удаление элемента списка (удаляется головной элемент).
    void DeleteFromHead();
    void DeleteFromTail();


    // Удаление всех элементов списка.
    void RemoveAll();
	
    // Получение количества элементов, находящихся в списке.
    unsigned int GetSize() const;


    void Insert(Node* new_node, unsigned int index);

    void DeleteAt(unsigned int position); // Delete element at a given position.
    Node* NodeAt(unsigned int index) const;

    int Find(const char data) const; // Find element, return position or -1 if not found.
    int FindAndReplace(const char oldData, const char newData); // Find and replace element, return count of replacements or -1 if not found.

    void Reverse(); // Reverse the list.


};
/*

Добавить в класс из задания 1 следующие функции: вставка элемента в заданную позицию, удаление элемента по заданной позиции, поиск заданного элемента (функция возвращает позицию найденного элемента в случае успеха или NULL в случае неудачи), поиск и замена заданного элемента (функция возвращает количество замененных элементов в случае успеха или -1 в случае неудачи), переворот списка.


*/