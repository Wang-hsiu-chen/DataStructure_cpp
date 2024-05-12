#include "HW3_TemplateChain.h"

template <class T>
Chain<T>::Chain()
{
    first = last = NULL;
}
template <class T>
Chain<T>::~Chain()
{
    if (!IsEmpty())
    {
        ChainNode<T> *temp = first;

        while (temp != nullptr)
        {
            ChainNode<T> *deleteNode = temp;
            temp = temp->link;
            delete deleteNode;
        }
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
    ChainNode<T> *list = new ChainNode<T>;
    list->data = 20;
    ChainNode<T> *ptr = new ChainNode<T>;
    ptr->data = 28;
    ptr->link = NULL;
    list->link = ptr;
    ptr = new ChainNode<T>;
    ptr->data = 30;
    ptr->link = list;
    list = ptr;
    ptr = new ChainNode<T>;
    ptr->data = 42;
    ptr->link = list->link;
    list->link = ptr;
    ptr = list;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->link;
    }

    int size = 0;
    ChainNode<T> *pointer = first;
    while (pointer != NULL)
    { // delete first
        size++;
        pointer = pointer->link;
    }
    return size;
}
template <class T>
void Chain<T>::InsertHead(const T &e)
{
    ChainNode<T> *head = new ChainNode<T>;
    head->data = e;
    head->link = first;
    first = head;
    if (first->link == NULL)
        last = first;
}
template <class T>
void Chain<T>::DeleteHead()
{
    ChainNode<T> *temp = first->link;
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
    ChainNode<T> *newNode = new ChainNode<T>;
    newNode->data = e;
    newNode->link = NULL;
    if (first == NULL)
        first = last = newNode;
    else
        last->link = newNode;
    last = newNode;
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
    {
        if (desiredNode == NULL)
            throw "index doesn't exist";
        desiredNode = desiredNode->link;
        currentIndex++;
    }
    return desiredNode->data;
}
template <class T>
T &Chain<T>::Set(int index, const T &e)
{
    ChainNode<T> *desiredNode = first; // gets you to first node
    int currentIndex = 0;
    while (currentIndex < index)
    {
        if (desiredNode == NULL)
            throw "index doesn't exist";
        desiredNode = desiredNode->link;
        currentIndex++;
    }
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
    if (first == NULL)
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
            if (p == NULL)
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
    while (temp->link != NULL)
        temp = temp->link;
    last = temp;
}
template <class T>
void Chain<T>::Insert(int index, const T &e)
{
    if (index < 0)
        throw "Bad insert index";
    else
    { // find predecessor of new element
        ChainNode<T> *p = first;
        for (int i = 0; i < index - 1; i++)
        {
            if (p == NULL)
                throw "Bad insert index";
            p = p->link;
        }
        // insert after p
        ChainNode<T> *newNode = new ChainNode<T>;
        newNode->data = e;
        newNode->link = p->link;
        p->link = newNode;
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
    last = b.last;
    return;
}
template <class T>
Chain<T> Chain<T>::Deconcatenate(ChainNode<T> *p)
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
    b.first = NULL;
}
template <class T>
void Chain<T>::Reverse()
{
    ChainNode<T> *left = NULL;
    ChainNode<T> *pointer = first;
    ChainNode<T> *temp = first;
    ChainNode<T> *right = new ChainNode<T>;
    while (pointer->link != NULL)
    {
        right = pointer->link;
        pointer->link = left;
        left = pointer;
        pointer = right;
    }
    pointer->link = left;
    first = right;
    last = temp;
}
template <class T>
void Chain<T>::Delete(Position p)
{
    if (p == NULL)
        throw "Delete element does not exist";
    ChainNode<T> *temp = first;
    if (p == first)
    {
        temp = p;
        first = p->link;
        delete temp;
        return;
    }
    while (temp->link != p)
    {
        if (temp == NULL)
            throw "Delete element does not exist";
        temp = temp->link;
    }
    temp->link = temp->link->link;
    delete p;
}
template <class T>
void Chain<T>::Insert(Position p, const T &e)
{
    ChainNode<T> *temp = first;
    if (first == NULL)
        throw "chain is empty";
    while (temp != p)
    {
        temp = temp->link;
        if (temp == NULL)
            throw "Insert node doesn't exist";
    }
    ChainNode<T> *newNode = new ChainNode<T>;
    newNode->data = e;
    newNode->link = temp->link;
    temp->link = newNode;
    return;
}

// template <class T>
// inline T &LinkedStack<T>::Top()
// {
//     if (this->IsEmpty())
//         throw "Stack empty";
//     // top = this->Back();
//     return ;
// }
// template <class T>
// void LinkedStack<T>::Push(T &e)
// {
//     InsertBack(e);
//     // top = this->last;
// }
// template <class T>
// void LinkedStack<T>::Pop()
// {
//     DeleteBack();
//     top = this->last;
// }
// template <class T>
// inline T &LinkedQueue<T>::Front()
// {
//     if (IsEmpty())
//         throw "Queue empty";
//     front = this->first;
//     return front->data;
// }
// template <class T>
// inline T &LinkedQueue<T>::Rear()
// {
//     if (IsEmpty())
//         throw "Queue empty";
//     rear = this->last;
//     return rear->data;
// }