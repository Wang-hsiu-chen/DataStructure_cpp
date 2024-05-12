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
    // might have problems
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
CNode<T> CircleList<T>::Deconcatenate(CNode<T> *p)
{
    // might have problems
    int size = Size();
    CircleList<T> b;
    CNode<T> *temp = p->link;
    b.first = p->link;
    p->link = first;
    while (temp->link != first)
        temp = temp->link;
    temp->link = b.first;
    return b;
}
template <class T>
void CircleList<T>::Merge(CircleList<T> &b)
{
    CNode<T> *chain1 = first;
    CNode<T> *chain2 = b.first;
    while (chain1->link != first && chain2->link != first)
    {
        CNode<T> *temp = chain1->link;
        chain1->link = chain2;
        chain2 = chain2->link;
        chain1 = chain1->link;
        chain1->link = temp;
        chain1 = temp;
    }
    if (chain1->link == first)
    {
        chain1->link = chain2;
        while (chain2->link != b.first)
            chain2 = chain2->link;
        chain2->link = first;
    }
    else if (chain2->link == b.first)
    {
        CNode<T> *temp = chain1->link;
        chain1->link = chain2;
        chain1 = chain1->link;
        chain1->link = temp;
        chain1 = temp;
    }
    chain2 = b.first;
    for (int i = 0; i < b.Size(); i++)
    {
        CNode<T> *temp = chain2;
        if (chain2->link != NULL)
            chain2 = chain2->link;
        delete temp;
    }
}
template <class T>
int CircleListHeader<T>::Size()
{
    int size = 0;
    CNode<T> *pointer = head;
    while (pointer->link != head)
    { // delete first
        size++;
        pointer = pointer->link;
    }
    return size;
}
template <class T>
void CircleListHeader<T>::InsertFront()
{
    CNode<T> *newNode = new CNode<T>;
    newNode->link = head->link;
    head->link = newNode;
}
template <class T>
void CircleListHeader<T>::InsertBack()
{
    CNode<T> *newNode = new CNode<T>;
    CNode<T> *temp = head;
    while (temp->link != head)
        temp = temp->link;
    newNode->link = head;
    temp->link = newNode;
}
template <class T>
void CircleListHeader<T>::DeleteFrist()
{
    if (head == head->link)
        throw "it's a empty list";
    CNode<T> *deleteNode = head->link;
    head->link = head->link->link;
    delete deleteNode;
}
template <class T>
void CircleListHeader<T>::DeleteBack()
{
    if (head == head->link)
        throw "it's a empty list";
    CNode<T> *temp = head;
    while (temp->link->link != head)
        temp = temp->link;
    delete temp->link;
    temp->link = head;
}
template <class T>
void CircleListHeader<T>::DeleteOdd()
{
    // might have problems
    if (head == head->link)
        throw "it's a empty list";
    CNode<T> *temp = head->link;
    while (temp->link != head && temp->link->link != head)
    {
        temp = temp->link;
        CNode<T> *deleteNode = temp->link;
        temp->link = temp->link->link;
        delete deleteNode;
    }
}
template <class T>
CNode<T> CircleListHeader<T>::Deconcatenate(CNode<T> *p)
{
    // might have problems
    int size = Size();
    CircleListHeader<T> b;
    CNode<T> *temp = p->link;
    b.head->link = p->link;
    p->link = head;
    while (temp->link != head)
        temp = temp->link;
    temp->link = b.head;
    return b;
}
template <class T>
void CircleListHeader<T>::Merge(CircleListHeader<T> &b)
{
    CNode<T> *chain1 = head;
    CNode<T> *chain2 = b.head;
    while (chain1->link != head && chain2->link != head)
    {
        CNode<T> *temp = chain1->link;
        chain1->link = chain2;
        chain2 = chain2->link;
        chain1 = chain1->link;
        chain1->link = temp;
        chain1 = temp;
    }
    if (chain1->link == head)
    {
        chain1->link = chain2;
        while (chain2->link != b.head)
            chain2 = chain2->link;
        chain2->link = head;
    }
    else if (chain2->link == b.head)
    {
        CNode<T> *temp = chain1->link;
        chain1->link = chain2;
        chain1 = chain1->link;
        chain1->link = temp;
        chain1 = temp;
    }
    chain2 = b.head;
    for (int i = 0; i < b.Size(); i++)
    {
        CNode<T> *temp = chain2;
        if (chain2->link != NULL)
            chain2 = chain2->link;
        delete temp;
    }
}