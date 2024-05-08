#include "HW3_CircularList.h"

template <class T>
CircleList() { first = 0; }
template <class T>
~CircleList()
{
}
template <class T>
int Size()
{
}
template <class T>
void InsertFront()
{

    CNode<T> *newNode = new CNode<T>(e);
    if (last)
    {
        newNode->link = last->link;
        last->link = newNode;
    }
    else
    {
        last = newNode;
        newNode->link = newNode;
    }
}
template <class T>
void InsertBack()
{
    CNode<T> *newNode = new CNode<T>(e);
    if (last)
    {
        newNode->link = last->link;
        last = last->link = newNode;
    }
    else
    {
        last = newNode;
        newNode->link = newNode;
    }
}
template <class T>
void DeleteFrist()
{
}
template <class T>
void DeleteBack()
{
}
template <class T>
void InsertBack()
{
}
template <class T>
void Delete()
{
}
template <class T>
void Deconcatenate()
{
}
template <class T>
void Merge(CircleList<T> &b)
{
}