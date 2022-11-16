#ifndef LIST_HPP
#define LIST_HPP

#include <string>
#include <exception>
#include <stdexcept>


template <class T>
class Node
{
    T value;
    Node* next;
};

template <class T>
class list
{
private:
    Node<T>* first;
    Node<T>* last;
    int count;

    list(/* args */);
    ~list();
public:    
    Node<T>* begin() const noexcept;
    Node<T>* end() const noexcept;
    void pushBack(T value);
    bool isEmpty() const;
    Node<T>* move(int index) const;
    void delFirst();
    void insert(T value, int index);
    void insert(T value, Node<T>* index);
    void clear() noexcept;

};

template <class T>
Node<T>* list<T>::begin() const noexcept
{
    return first;
}

template <class T>
Node<T>* list<T>::end() const noexcept
{
    return last;
}

template <class T>
Node<T>* list<T>::move(int index) const
{
    try
    {
        if(index < 0 || index >= count)
            throw std::invalid_argument("Out of indexes!");

        if(count > 0)
        {
            Node<T>* it = first;
            for(int i = 0; i < index; i++)
                it = it->next;

            return it
        }
        
        return nullptr;

    }
    catch(std::invalid_argument arg)
    {
        std::cerr <<  arg.what() << std::endl;
    }
}

template <class T>
void list<T>::delFirst()
{
    Node<T>* it = first;
    if(it != nullptr)
    {
        first = first->next;
        delete it;
    }
    return;
}

template <class T>
void list<T>::clear() noexcept
{
    while (first != nullptr)
        delFirst();
}

template <class T>
void list<T>::pushBack(T value)
{
    try
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
    catch(std::bad_alloc err)
    {
        std::cerr << err.what() << std::endl;
    }
}

template <class T>
bool list<T>::isEmpty() const
{
    return first == nullptr;
}

template <class T>
void list<T>::insert(T value, int index)
{
    try
    {
        if ((count != 0) && ((index < 0) || (index >= count)))
            throw std::invalid_argument("Out of indexes!");

        if(first == nullptr || index == count - 1)
        {
            pushBack(value);
        }
        else
        {
            Node<T>* tmp = new Node<T>;
            tmp->value = value;   
            if(index == 0)
            {
                tmp->next = first;
                first = tmp;
            }
            else
            {
                Node<T>* it = move(index - 1);
                tmp->next = it->next;
                it->next = tmp;
            }
        }

        count++;
    }
    catch(std::bad_alloc err)
    {
        std::cerr << err.what() << std::endl;
    }
    catch(std::invalid_argument arg)
    {
        std::cerr <<  arg.what() << std::endl;
    }

}

template <class T>
void list<T>::insert(T value, Node<T>* index)
{
    try
    {
        if ((count != 0) && ((index < 0) || (index >= count)))
            throw std::invalid_argument("Out of indexes!");

        if(this->isEmpty())
        {
            pushBack(value);
        }
        elif(inde)
        {

        }
    }
    catch(std::bad_alloc err)
    {
        std::cerr << err.what() << std::endl;
    }
    catch(std::invalid_argument arg)
    {
        std::cerr <<  arg.what() << std::endl;
    }

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