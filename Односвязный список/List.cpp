#include "List.h"

#include <iostream>

using namespace std;

List::List() :  m_head(nullptr),   m_size(0U)
{
}

List::List(const List& list) :  m_head(nullptr), m_size(0U)
{
    Assign(list);
}

List::~List()
{
    RemoveAll();
}

List& List::operator=(const List& right)
{
    if (this != &right)
    {
        Assign(right);
    }

    return *this;
}

unsigned int List::GetSize() const
{
    return m_size;
}

void List::Add(const char data)////data - данні котрі хочемо додати до списку  в кінець
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

void List::Add(Node* new_node)
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

void List::AddToHead(Node* new_node)
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

void List::Insert(Node* new_node, unsigned int index)
{
    if (index < m_size)
    {
        if (index == 0U)
        {
            AddToHead(new_node);
        }
        else if (index == m_size - 1U)
        {
            Add(new_node);
        }
        else {

            Node* current = NodeAt(index);
            new_node->m_next = current;

        }



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