#pragma once

/**/

/////   template <typename T>    DZ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/////   Создаем список Person  , тестируем в main : создали список, добавить Person , удалить, вівести на екран весь список  

template <typename T >
class Node////структура що зберігає данні одного вузла(одиниця данних), це може бути і клас
{
public:
    // Данные.
   T m_data;////може бути елемент Person замість char   ( у шаблонах тип T)

   // Person obj;

    // Адрес следующего элемента списка.
    Node* m_next;//////обовязкове поле що звязує один екземпляр ланцюга данних з іншим

    Node(const T data);
};

template<typename T>
inline Node<T>::Node(const T data)
{
    m_data = data;
	m_next = nullptr;/////вказує на наступний елемент списку, якщо його немає то NULL
}
