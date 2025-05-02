#pragma once

#include "Node.h"

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




    void Assign(const List& list);

    // Распечатка содержимого списка (распечатка начинается с головного элемента).
    void Print() const;

    // Удаление элемента списка (удаляется головной элемент).
    void RemoveHead();

    // Удаление всех элементов списка.
    void RemoveAll();
	
    // Получение количества элементов, находящихся в списке.
    unsigned int GetSize() const;
};
