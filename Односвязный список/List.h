#pragma once

#include "Node.h"

template <typename T>
class List
{
private:
    Node<T>* m_head = nullptr; 
    unsigned int m_size = 0;

public:
    List();
    List(const List& list);

    ~List();

    List& operator=(const List& right);

    void Add(const T data);
    void Add(Node<T>* new_node);

    void AddToHead(Node<T>* new_node);

    void Assign(const List& list);

    void Print() const;

    void DeleteFromHead();
    void DeleteFromTail();

    void RemoveAll();

    unsigned int GetSize() const {
        return m_size;
    };

    void Insert(Node<T>* new_node, unsigned int index);

    void DeleteAt(unsigned int position);
    Node<T>* NodeAt(unsigned int index) const;

    int Find(const T data) const;
    int FindAndReplace(const T oldData, const T newData);

    void Reverse();
};

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
    Node<T>* newNode = new Node<T>(data); 
    if (m_head == nullptr)
    {
        m_head = newNode;
    }
    else
    {
        Node<T>* temp = m_head; 
        while (temp->m_next != nullptr)
        {
            temp = temp->m_next;
        }
        temp->m_next = newNode;
    }
    ++m_size;
}

template<typename T>
inline void List<T>::Add(Node<T>* new_node)
{
    if (m_head == nullptr)
    {
        m_head = new_node;
    }
    else
    {
        Node<T>* temp = m_head; 
        while (temp->m_next != nullptr)
        {
            temp = temp->m_next;
        }
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
    RemoveAll();

    Node<T>* node = list.m_head; 
    while (node != nullptr)
    {
        Add(node->m_data);
        node = node->m_next;
    }
}

template<typename T>
inline void List<T>::Print() const
{
    Node<T>* temp = m_head; 
    while (temp != nullptr)
    {
        std::cout << temp->m_data;
        temp = temp->m_next;
    }
    std::cout << std::endl;
}

template<typename T>
inline void List<T>::DeleteFromHead()
{
    if (m_head != nullptr)
    {
        Node<T>* node = m_head;
        m_head = m_head->m_next;
        delete node;
        --m_size;
    }
}

template<typename T>
inline void List<T>::DeleteFromTail()
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
        Node<T>* temp = m_head;
        while (temp->m_next->m_next != nullptr)
        {
            temp = temp->m_next;
        }
        delete temp->m_next;
        temp->m_next = nullptr;
    }
    --m_size;
}

template<typename T>
inline void List<T>::RemoveAll()
{
    while (m_head != nullptr)
    {
        DeleteFromHead();
    }
}

template<typename T>
inline void List<T>::Insert(Node<T>* new_node, unsigned int index)
{
    if (new_node == nullptr || index > m_size)
    {
        return;
    }

    if (index == 0)
    {
        AddToHead(new_node);
    }
    else if (index == m_size)
    {
        Add(new_node);
    }
    else
    {
        Node<T>* prev = NodeAt(index - 1);
        new_node->m_next = prev->m_next;
        prev->m_next = new_node;
        ++m_size;
    }
}

template<typename T>
inline void List<T>::DeleteAt(unsigned int position)
{
    if (position >= m_size)
    {
        return;
    }

    if (position == 0)
    {
        DeleteFromHead();
    }
    else
    {
        Node<T>* prev = NodeAt(position - 1); 
        Node<T>* toDelete = prev->m_next;   
        prev->m_next = toDelete->m_next;
        delete toDelete;
        --m_size;
    }
}

template<typename T>
inline Node<T>* List<T>::NodeAt(unsigned int index) const
{
    if (index >= m_size)
    {
        return nullptr;
    }

    Node<T>* current = m_head; 
    for (unsigned int i = 0; i < index; ++i)
    {
        current = current->m_next;
    }
    return current;
}

template<typename T>
inline int List<T>::Find(const T data) const
{
    Node<T>* current = m_head; 
    int position = 0;

    while (current != nullptr)
    {
        if (current->m_data == data)
        {
            return position;
        }
        current = current->m_next;
        ++position;
    }
    return -1;
}

template<typename T>
inline int List<T>::FindAndReplace(const T oldData, const T newData)
{
    Node<T>* current = m_head; 
    int replacements = 0;

    while (current != nullptr)
    {
        if (current->m_data == oldData)
        {
            current->m_data = newData;
            ++replacements;
        }
        current = current->m_next;
    }
    return (replacements > 0) ? replacements : -1;
}

template<typename T>
inline void List<T>::Reverse()
{
    Node<T>* prev = nullptr;   
    Node<T>* current = m_head; 
    Node<T>* next = nullptr;   

    while (current != nullptr)
    {
        next = current->m_next;
        current->m_next = prev;
        prev = current;
        current = next;
    }
    m_head = prev;
}
