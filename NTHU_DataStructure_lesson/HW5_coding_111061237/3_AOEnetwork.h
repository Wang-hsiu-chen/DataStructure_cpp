#include <iostream>
#include <vector>
#include <utility>
#include <stack>
using namespace std;

template <class T>
class Chain;
template <class T>
class ChainNode
{
    friend class Chain<T>;

public:
    T data;
    T weight = 0;

private:
    ChainNode<T> *link;
};

template <class T>
class Chain
{
public:
    Chain();
    ~Chain(); // desctructor
    // 鏈的處理運算
    bool IsEmpty();
    int Size();
    void InsertHead(const T &e);
    void DeleteHead();
    void InsertBack(const T &v, const T &e);
    void DeleteBack();
    bool FindElement(T &e);
    int IndexOf(const T &e) const;
    inline const T &Front();
    inline const T &Back();
    T &GetWeight(int index);
    T &Set(int index, const T &e);
    void Delete(int index);
    void Insert(int index, const T &e);
    void DivideMid(Chain<T> &b);
    void Concatenate(Chain<T> &b);
    ChainNode<T> *Next();
    void ResetPointer();
    ChainNode<T> *pointer = first;

private:
    ChainNode<T> *first, *last;
};
template <class T>
void ChangeSize1D(T *&a, const int oldSize, const int newSize)
{
    if (newSize < 0)
        throw "New length must be >= 0";
    T *temp = new T[newSize];
    int number = min(oldSize, newSize);
    copy(a, a + number, temp);
    delete[] a;
    a = temp;
}
class LinkedGraph
{
public:
    LinkedGraph(const int inputVertices = 0) : vertices(inputVertices), edges(0)
    {
        adjLists = new Chain<int>[vertices];
        fill(visited, visited + vertices, false);
        earliestE = new int[vertices];
        latestE = new int[vertices];
        earliestA = new int[edges];
        latestA = new int[edges];
        topoSort = new int[vertices];
        dist = new int[vertices];
    }
    void InitEdges(); // print out each vertice // input the vertices that it adjacents with
    void ChangeToMetrix();
    void LongestPath();
    void TopologicalOrder();
    void TimeOfEvents();
    void TimeOfActivies();
    void ActivityTimeMatrix();
    void CriticalNetwork();
    void CountEdges();
    void Setup1();

private:
    Chain<int> *adjLists;
    bool *visited = new bool[vertices];
    int **matrix = new int *[vertices];
    int *topoSort;
    int *dist;
    int vertices, edges;
    int *earliestE;
    int *latestE;
    int *earliestA;
    int *latestA;
};
