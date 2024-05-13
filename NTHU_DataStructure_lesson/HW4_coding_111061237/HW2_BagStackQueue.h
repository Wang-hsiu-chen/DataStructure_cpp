#include <iostream>
using namespace std;

template <class T>
class Bag
{
    template <class U>
    friend void ChangeSize1D(U *&a, const int oldSize, const int newSize);

public:
    Bag(int bagCapacity = 10);
    virtual ~Bag();
    virtual int Size() const;
    virtual bool IsEmpty() const;
    virtual T &Element() const;
    virtual void Push(const T &);
    virtual void Pop();

protected:
    T *array;
    int top, capacity;
};

// stack
template <class T>
class Stack : public Bag<T>
{
    using Bag<T>::IsEmpty;
    using Bag<T>::capacity;
    using Bag<T>::array;
    using Bag<T>::top;
    template <class U>
    friend ostream &operator<<(ostream &os, Stack<U> &stack);
    template <class U>
    friend istream &operator>>(istream &is, Stack<U> &stack);
    template <class U>
    friend void ChangeSize1D(U *&a, const int oldSize, const int newSize);

public:
    Stack(int stackCapacity = 10);
    ~Stack();
    void Pop();
    T &Top() const;
};

// Queue
template <class T>
class Queue : public Bag<T>
{
    using Bag<T>::IsEmpty;
    using Bag<T>::capacity;
    using Bag<T>::array;
    template <class U>
    friend ostream &operator<<(ostream &os, Queue<U> &queue);
    template <class U>
    friend istream &operator>>(istream &is, Queue<U> &queue);
    template <class U>
    friend void ChangeSize1D(U *&a, const int oldSize, const int newSize);

public:
    Queue(int queueCapacity = 10);
    ~Queue();
    void Pop();
    int Size() const;
    void Push(const T &item);

protected:
    int front, rear;
};