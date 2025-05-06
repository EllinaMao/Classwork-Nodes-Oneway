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
template <typename T>
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
    void Add(const T data);
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
    unsigned int GetSize() const {
        return m_size;
    };


    void Insert(Node* new_node, unsigned int index);

    void DeleteAt(unsigned int position); // Delete element at a given position.
    Node* NodeAt(unsigned int index) const;

    int Find(const T data) const; // Find element, return position or -1 if not found.
    int FindAndReplace(const char oldData, const T newData); // Find and replace element, return count of replacements or -1 if not found.

    void Reverse(); // Reverse the list.


};
/*

Добавить в класс из задания 1 следующие функции: вставка элемента в заданную позицию, удаление элемента по заданной позиции, поиск заданного элемента (функция возвращает позицию найденного элемента в случае успеха или NULL в случае неудачи), поиск и замена заданного элемента (функция возвращает количество замененных элементов в случае успеха или -1 в случае неудачи), переворот списка.


*/
/*


void List::DeleteAt(unsigned int position)
{
    if (position >= m_size) {
        return;
    }

    if (position == 0) {
        DeleteFromHead();
    }
    else {
        Node* prev = NodeAt(position - 1);
        Node* toDelete = prev->m_next;
        prev->m_next = toDelete->m_next;
        delete toDelete;
        --m_size;
    }
}
int List::Find(const char data) const
{
    Node* current = m_head;
    int position = 0;

    while (current != nullptr) {
        if (current->m_data == data) {
            return position;
        }
        current = current->m_next;
        ++position;
    }

    return -1; // Element not found
}

int List::FindAndReplace(const char oldData, const char newData)
{
    Node* current = m_head;
    int replacements = 0;

    while (current != nullptr) {
        if (current->m_data == oldData) {
            current->m_data = newData;
            ++replacements;
        }
        current = current->m_next;
    }

    return (replacements > 0) ? replacements : -1;
}
void List::Reverse()
{
    Node* prev = nullptr;
    Node* current = m_head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->m_next;
        current->m_next = prev;
        prev = current;
        current = next;
    }

    m_head = prev;
}


Node* List::NodeAt(unsigned int index) const
{
    if (index >= m_size) {
        return nullptr;
    }

    Node* current = m_head;
    for (unsigned int i = 0; i < index; ++i) {
        current = current->m_next;
    }

    return current;
}


void List::Assign(const List& list)
{
    RemoveAll();

    Node* node = list.m_head;

    while (node != nullptr)
    {
        Add(node->m_data);

        node = node->m_next;
    }
}

void List::Print() const
{
    // Запоминание адреса головного элемента.
    Node* temp = m_head;

    // Пока еще есть элементы.
    while (temp != nullptr)
    {
        // Вывод данных.
        cout << temp->m_data;

        // Переход на следующий элемент.
        temp = temp->m_next;
    }

    cout << endl;
}

//////////////  RemoveAt (int index)  DZ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void List::DeleteFromHead()//1й
{
    if (m_head != nullptr)
    {
        // Запоминание адреса головного элемента.
        Node* node = m_head;

        // Перебрасывание головы на следующий элемент.
        m_head = m_head->m_next;

        // Удаление бывшего головного элемента.
        delete node;

        --m_size;
    }
}

void List::DeleteFromTail()
{
    if (m_head == nullptr)
    {
        return;
    }

    if (m_head->m_next == nullptr)
    {
        delete m_head;
        m_head = nullptr;
    }
    else
    {
        Node* temp = m_head;

       //two times to find almoust last element
        while (temp->m_next->m_next != nullptr)
        {
            temp = temp->m_next;
        }
        // delete last
        delete temp->m_next;
        temp->m_next = nullptr;
    }

    --m_size;
}


void List::RemoveAll()
{
    // Пока еще есть элементы.
    while (m_head != nullptr)
    {
        // Удаление элементов по одному.
        DeleteFromHead();
    }
}

*/

template<typename T>
inline List<T>::List() : m_head(nullptr), m_size(0U) {}

template<typename T>
inline List<T>::List(const List& list)
{
    Assign(list);

}

template<typename T>
inline List<T>::~List()
{
    RemoveAll();
}

template<typename T>
List<T>& List<T>::operator=(const List& right)
{
    
    if (this != &right)
    {
        Assign(right);
    }

    return *this;
    
}

template<typename T>
inline void List<T>::Add(const T data)

    {
        // Cоздание нового элемента.
        Node* newNode = new Node(data);

        if (m_head == nullptr)//////якщо список пустий
        {
            // Новый элемент становится головным элементом списка.
            m_head = newNode;
        }
        else
        {
            Node* temp = m_head;

            while (temp->m_next != nullptr)
            {
                temp = temp->m_next;
            }

            // Новый элемент становится в конец списка.
            temp->m_next = newNode;
        }

        ++m_size;
    

}

template<typename T>
inline void List<T>::Add(Node<T>* new_node)
{
	if (m_head == nullptr)//////якщо список пустий
	{
		// Новый элемент становится головным элементом списка.
		m_head = new_node;
	}
	else
	{
		Node* temp = m_head;
		while (temp->m_next != nullptr)
		{
			temp = temp->m_next;
		}
		// Новый элемент становится в конец списка.
		temp->m_next = new_node;
	}
	++m_size;
}

template<typename T>
inline void List<T>::AddToHead(Node<T>* new_node)
{
	if (m_size > 0)
	{
		new_node->m_next = m_head;
		m_head = new_node;
	}
	else
	{
		m_head = new_node;
	}
	++m_size;
}

template<typename T>
inline void List<T>::Assign(const List& list)
{
	// Удаление всех элементов списка.
RemoveAll();

Node* node = list.m_head;

    while (node != nullptr)
    {
        Add(node->m_data);

        node = node->m_next;
    }
}

template<typename T>
inline void List<T>::RemoveAll()
{
    // Пока еще есть элементы.
    while (m_head != nullptr)
    {
        // Удаление элементов по одному.
        DeleteFromHead();
    }
}

template<typename T>
inline void List<T>::Insert(Node<T>* new_node, unsigned int index) {
    if (new_node == nullptr || index > m_size) {
        return; 
    }

    if (index == 0) {
        AddToHead(new_node); // Вставка в начало.
    }
    else if (index == m_size) {
        Add(new_node); // Вставка в конец.
    }
    else {
        // Вставка в середину.
        Node* prev = NodeAt(index - 1);
        new_node->m_next = prev->m_next;
        prev->m_next = new_node;
        ++m_size; // Увеличиваем размер списка.
    }
}
