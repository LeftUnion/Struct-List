#ifndef LIST_HPP
#define LIST_HPP

#include <string>

template <class T>
class Node
{
    T value;
    Node* next;
};

template <class T>
class list
{
    Node<T>* first;
    Node<T>* last;
    int count;

    list(/* args */);
    ~list();
    
    void pushBack(T value);
    bool isEmpty();
};

template <class T>
void list<T>::pushBack(T value)
{
    Node<T>* tmp = new Node<T>;
    tmp->value = value;
    tmp->next = nullptr;

    if(this->isEmpty())
        first = last = tmp;
    else
    {
        last->next = tmp;
        last = tmp;
    }
    count++;
}

template <class T>
bool list<T>::isEmpty()
{
    return first == nullptr;
}

template <class T>
list<T>::list()
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

template <class T>
list<T>::~list()
{
}



#endif // LIST_HPP