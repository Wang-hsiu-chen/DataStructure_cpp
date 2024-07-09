#include <iostream>
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

private:
    ChainNode<T> *link;
};

template <class T>
class Chain
{
    typedef ChainNode<T> Position;

public:
    Chain();
    ~Chain(); // desctructor
    // 鏈的處理運算
    bool IsEmpty();
    int Size();
    void InsertHead(const T &e);
    void DeleteHead();
    void InsertBack(const T &e);
    void DeleteBack();
    inline const T &Front();
    inline const T &Back();
    T &Get(int index);
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
template <class T>
class Queue
{
    template <class U>
    friend void ChangeSize1D(U *&a, const int oldSize, const int newSize);

public:
    Queue(int queueCapacity = 10) : capacity(queueCapacity)
    {
        front = 0;
        rear = 0;
        if (capacity < 1)
            throw "Capacity must be > 0";
        array = new T[capacity];
        top = -1;
    }
    ~Queue() {}
    bool IsEmpty() const
    {
        return (Size() == 0);
    }
    void Pop()
    {
        if (IsEmpty())
            throw "Bag is empty, cannot delete";
        int deletePos = top / 2;
        copy(array + deletePos + 1, array + top + 1, array + deletePos);
        array[top--].~T();
    }
    inline int Size() const
    {
        return top + 1;
    }
    T Front()
    {
        if (IsEmpty())
            throw "Bag is empty";
        return array[0];
    }
    void Push(const T &item)
    {
        if (capacity == top + 1)
        {
            ChangeSize1D(array, capacity, 2 * capacity);
            capacity *= 2;
        }

        array[++top] = item;
    }

protected:
    T *array;
    int top, capacity;
    int front, rear;
};
class LinkedGraph
{
public:
    LinkedGraph(const int inputVertices = 0) : vertices(inputVertices), edges(0)
    {
        adjLists = new Chain<int>[vertices];
        fill(visited, visited + vertices, false);
    }
    void InitEdges(); // print out each vertice // input the vertices that it adjacents with
    void BFS(int v);
    void DFS(int v);
    void Components();
    void DfnLow(const int v); // Display the computed dfn[i] and low[i] of the graph and the articulation points found
    void DfnLow(const int u, const int v);
    void Setup1();
    void Setup2();

private:
    Chain<int> *adjLists;
    bool *visited = new bool[vertices];
    int *dfn = new int[vertices];
    int *low = new int[vertices];
    int vertices, edges;
    int num;
};
