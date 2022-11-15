#ifndef LIST_H
#define LIST_H

typedef char type;

typedef struct Node
{
    type value;
    struct Node* next;
} List;

List* last(List* root);
int getSize(List* root);
type getValue(List* it);

List* push(List** root, type value);
List* pop(List** root);

List* insert(List* it , List** root, type value);
List* removeElement(List* it , List** root);

#endif // LIST_H