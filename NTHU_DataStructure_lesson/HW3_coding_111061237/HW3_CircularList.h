#include <iostream>
using namespace std;

template <class T>
class CircleList;
template <class T>
class CircleListHeader;
template <class T>
class CNode
{
    friend class CircleList<T>;
    friend class CircleListHeader<T>;

private:
    T data;
    CNode<T> *link;
};

template <class T>
class CircleList
{
public:
    CircleList() { first = 0; } // 建構子將first, last初始化成0
    ~CircleList();              // desctructor
    // 鏈的處理運算
    int Size();
    void InsertFront();
    void InsertBack();
    void DeleteFrist();
    void DeleteBack();
    void DeleteOdd();
    CNode<T> Deconcatenate(CNode<T> *p);
    void Merge(CircleList<T> &b);

private:
    CNode<T> *first;
};
template <class T>
class CircleListHeader
{
public:
    CircleListHeader() { head = 0; } // 建構子將first, last初始化成0
    ~CircleListHeader();             // desctructor
    // 鏈的處理運算
    int Size();
    void InsertFront();
    void InsertBack();
    void DeleteFrist();
    void DeleteBack();
    void DeleteOdd();
    CNode<T> Deconcatenate(CNode<T> *p);
    void Merge(CircleListHeader<T> &b);

private:
    CNode<T> *head;
};