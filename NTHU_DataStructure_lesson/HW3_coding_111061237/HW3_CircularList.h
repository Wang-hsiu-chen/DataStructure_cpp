#include <iostream>
using namespace std;

template <class T>
class CircleList; // 前向宣告
template <class T>
class CNode
{
    friend class CircleList<T>;

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
    void Deconcatenate(CNode *p);
    void Merge(CircleList<T> &b);

private:
    CNode<T> *first;
};
