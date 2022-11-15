#include "list.h"
#include <stdlib.h>

// root->[]->[]->[]->NULL
// root->NULL
// root->[]->NULL
int getSize(List* root)
{
    List* it = root;
    int count = 0;
    
    while (it != NULL)
    {
        count++;
        it = it->next;
    }
    
    return count;
}

type getValue(List* it)
{
    if (it != NULL)
        return it->value;
    else 
        return NULL;
}

List* last(List* root)
{
    List* it = root;
    if(it == NULL)
        return NULL;

    while (it->next != NULL)
        it = it->next;

    return it;
}

List* push(List** root, type value)
{
    List* tmp = (List*)malloc(sizeof(List));
    tmp->value = value;
    tmp->next = NULL;

    List* it = last(*root);
    if(it == NULL)
        *root = tmp;
    else
        it->next = tmp;

    return tmp;
}
        
List* pop(List** root)
{
    List* it = last(*root); 
    if(it == NULL)
        return NULL;

    if(it == *root)
    {
        free(it);
        return *root = NULL;
    }

    List* prev = *root;
    while (prev->next != it)
        prev = prev->next;
    
    free(it);
    return prev->next = NULL;
}

List* insert(List* it , List** root, type value)
{
    if(it == NULL)
        return NULL;

    if(it == last(*root))
        return push(root, value);

    List* tmp = (List*)malloc(sizeof(List));
    tmp->value = value;
    if(it == root)
    {
        tmp->next = *root;
        return *root = tmp;
    }

    tmp->next = it->next;
    it->next = tmp;

    return tmp;
}

List* removeElement(List* it , List** root)
{
    if(it == NULL)
        return NULL;

    if(it == last(*root))
       return pop(root);

    List* prev = *root;
    while (prev->next != it)
        prev = prev->next;
    
    prev->next = it->next;
    free(it);
    return prev->next;
}