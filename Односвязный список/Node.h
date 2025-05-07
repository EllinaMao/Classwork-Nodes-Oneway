#pragma once

/**/

/////   template <typename T>    DZ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/////   Создаем список Person  , тестируем в main : создали список, добавить Person , удалить, вівести на екран весь список  

template <typename T>
class Node
{
public:
    T m_data;          // Data stored in the node
    Node* m_next;      // Pointer to the next node

    Node(const T& data) : m_data(data), m_next(nullptr) {}
};

