#include "HW3_TemplateChain.h"

template <class T>
void Chain<T>::Chain()
{
    first = last = NULL;
}
template <class T>
void Chain<T>::~Chain()
{
    // Chain destructor. Delete all nodes
    // in chain.
    while (first != NULL)
    { // delete first
        ChainNode<T> *next = first->link;
        delete first;
        first = next;
    }
}
// 鏈的處理運算
template <class T>
inline bool Chain<T>::IsEmpty()
{
    return (first == last && first == NULL) ? true : false;
}
template <class T>
int Chain<T>::Size()
{
    int size = 0;
    ChainNode<T> *pointer = first;
    while (pointer != NULL)
    { // delete first
        size++;
        ChainNode<T> *next = pointer->link;
        pointer = next;
    }
    return size;
}
template <class T>
void Chain<T>::InsertHead(const T &e)
{
    ChainNode<T> *head;
    head->data = e;
    head->link = first;
    first = head;
}
template <class T>
void Chain<T>::DeleteHead()
{
    ChainNode<T> *temp;
    temp = first->link;
    delete first;
    first = temp;
}
template <class T>
inline const T &Chain<T>::Front()
{
    return first->data;
}
template <class T>
inline const T &Chain<T>::Back()
{
    return last->data;
}
template <class T>
void Chain<T>::InsertBack(const T &e)
{
    ChainNode<T> *back;
    back->data = e;
    back->link = NULL;
    last->link = back;
    last = back;
}
template <class T>
void Chain<T>::DeleteBack()
{
    ChainNode<T> *p = first;
    while (p->link != last)
        p = p->link;
    delete last;
    p->link = NULL;
    last = p;
}
template <class T>
T &Chain<T>::Get(int index)
{
    ChainNode<T> *desiredNode;
    int currentIndex = 0;
    desiredNode = first; // gets you to first node
    while (currentIndex < index)
        desiredNode = desiredNode->link;
    return desiredNode->data;
}
template <class T>
T &Chain<T>::Set(int index, const T &e)
{
    ChainNode<T> *desiredNode;
    int currentIndex = 0;
    desiredNode = first; // gets you to first node
    while (currentIndex < index)
        desiredNode = desiredNode->link;
    desiredNode->data = e;
    return desiredNode->data;
}
template <class T>
int Chain<T>::IndexOf(const T &e) const
{
    // search the chain for e
    ChainNode<T> *currentNode = first;
    int index = 0; // index of currentNode
    while (currentNode != NULL && currentNode->data != e)
    { // move to next node
        currentNode = currentNode->link;
        index++;
    }
    // make sure we found matching element
    if (currentNode == NULL)
        return -1;
    else
        return index;
}
template <class T>
void Chain<T>::Delete(int index)
{
    if (first == 0)
        throw "Cannot delete from empty chain";
    ChainNode<T> *deleteNode;
    if (index == 0)
    { // remove first node from chain
        deleteNode = first;
        first = first->link;
    }
    else
    { // use p to get to beforeNode
        ChainNode<T> *p = first;
        for (int i = 0; i < index - 1; i++)
        {
            if (p == 0)
                throw "Delete element does not exist";
            p = p->link;
        }
        deleteNode = p->link;
        p->link = p->link->link;
    }
    delete deleteNode;
}
template <class T>
void Chain<T>::DeleteOdd()
{
    // might have problems
    ChainNode<T> *temp = first;
    while (temp->link != NULL && temp->link->link != NULL)
    {
        temp = temp->link;
        ChainNode<T> *deleteNode = temp->link;
        temp->link = temp->link->link;
        delete deleteNode;
    }
}
template <class T>
void Chain<T>::Insert(int index, const T &e)
{
    if (index < 0)
        throw "Bad insert index";
    if (index == 0)
        // insert at front
        first = new chainNode<T>(e, first);
    else
    { // find predecessor of new element
        ChainNode<T> *p = first;
        for (int i = 0; i < index - 1; i++)
        {
            if (p == 0)
                throw "Bad insert index";
            p = p->next;
        }
        // insert after p
        p->link = new ChainNode<T>(e, p->link);
    }
}
template <class T>
void Chain<T>::DivideMid(Chain<T> &b)
{
    int size = Size();
    ChainNode<T> *midNode = first;
    for (int i = 0; i < size / 2 - 1; i++)
    {
        midNode = midNode->link;
    }
    b.first = midNode->link;
    b.last = last;
    last = midNode;
    last->link = NULL;
}
template <class T>
void Chain<T>::Concatenate(Chain<T> &b)
{
    last->link = b.first;
    delete last;
    last = b.last;
}
Chain Chain<T>::Deconcatenate(ChainNode<T> *p)
{
    // might have problems
    int size = Size();
    Chain<T> b;
    b.first = p->link;
    b.last = last;
    last = p;
    last->link = NULL;
    return b;
}
template <class T>
void Chain<T>::Merge(Chain<T> &b)
{
    ChainNode<T> *chain1 = first;
    ChainNode<T> *chain2 = b.first;
    while (chain1->link != NULL && chain2->link != NULL)
    {
        ChainNode<T> *temp = chain1->link;
        chain1->link = chain2;
        chain2 = chain2->link;
        chain1 = chain1->link;
        chain1->link = temp;
        chain1 = temp;
    }
    if (chain1->link == NULL)
    {
        chain1->link = chain2;
        last = b.last;
    }
    else if (chain2->link == NULL)
    {
        ChainNode<T> *temp = chain1->link;
        chain1->link = chain2;
        chain1 = chain1->link;
        chain1->link = temp;
        chain1 = temp;
    }
    chain2 = b.first;
    for (int i = 0; i < b.Size(); i++)
    {
        ChainNode<T> *temp = chain2;
        if (chain2->link != NULL)
            chain2 = chain2->link;
        delete temp;
    }
}
template <class T>
void Chain<T>::Reverse()
{
}
template <class T>
void Chain<T>::Delete(Position p)
{
}
template <class T>
void Chain<T>::Insert(Position p, const T &e)
{
}
