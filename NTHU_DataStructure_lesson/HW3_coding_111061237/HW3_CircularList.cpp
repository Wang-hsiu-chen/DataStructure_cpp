#include "HW3_CircularList.h"

template <class T>
CircleList<T>::CircleList() { first = NULL; }
template <class T>
CircleList<T>::~CircleList()
{
    while (first != NULL)
    {
        CNode<T> *temp = first->link;
        delete frist;
        if (temp != NULL)
            first = temp->link;
    }
}
template <class T>
int CircleList<T>::Size()
{
    int size = 0;
    if (first == NULL)
        return 0;
    CNode<T> *pointer = first;
    while (pointer->link != first)
    { // delete first
        size++;
        pointer = pointer->link;
    }
    return size + 1;
}
template <class T>
void CircleList<T>::InsertFront()
{
    if (first == NULL) // empty list
    {
        CNode<T> *newNode = new CNode<T>;
        newNode->link = newNode;
        first = newNode;
    }
    else if (first != NULL)
    {
        CNode<T> *newNode = new CNode<T>;
        CNode<T> *temp = first;
        while (temp->link != first)
            temp = temp->link;
        newNode->link = first;
        temp->link = newNode;
        first = newNode;
    }
}
template <class T>
void CircleList<T>::InsertBack()
{
    if (first == NULL) // empty list
    {
        CNode<T> *newNode = new CNode<T>;
        newNode->link = newNode;
        first = newNode;
    }
    else if (first != NULL)
    {
        CNode<T> *newNode = new CNode<T>;
        CNode<T> *temp = first;
        while (temp->link != first)
            temp = temp->link;
        newNode->link = temp->link;
        temp->link = newNode;
    }
}
template <class T>
void CircleList<T>::DeleteFrist()
{
    if (first == NULL)
        throw "it's a empty list";
    CNode<T> *temp = first;
    while (temp->link != first)
        temp = temp->link;
    temp->link = first->link;
    delete first;
    first = temp->link;
}
template <class T>
void CircleList<T>::DeleteBack()
{
    if (first == NULL)
        throw "it's a empty list";
    else if (first->link == first)
    {
        delete first;
        return;
    }
    CNode<T> *temp = first;
    while (temp->link->link != first)
        temp = temp->link;
    delete temp->link;
    temp->link = first;
}
template <class T>
void CircleList<T>::DeleteOdd()
{
    CNode<T> *temp = first;
    while (temp->link != first && temp->link->link != first)
    {
        temp = temp->link;
        CNode<T> *deleteNode = temp->link;
        temp->link = temp->link->link;
        delete deleteNode;
    }
}
template <class T>
void CircleList<T>::Deconcatenate(CNode *p)
{
}
template <class T>
void CircleList<T>::Merge(CircleList<T> &b)
{
}