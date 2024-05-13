#include <iostream>
using namespace std;

template <class T>
class MaxPQ
{
    template <class U>
    friend void ChangeSize1D(U *&a, const int oldSize, const int newSize);

public:
    virtual ~MaxPQ() {}               // virtual destructor
    virtual bool IsEmpty() const = 0; // return true iff empty
    virtual const T &Top() const = 0; // return reference to the max
    virtual void Push(const T &) = 0;
    virtual void Pop() = 0;
};

template <class T>
class MaxHeap : public MaxPQ<T>
{
public:
    MaxHeap(int theCapacity = 10); // constructor
    bool IsEmpty() const;          // return true iff empty
    const T &Top() const;          // return reference to the max
    void Push(const T &);
    void Pop();

private:
    T *heap;      // element array
    int heapSize; // number of elements in heap
    int capacity; // size of the element array
};
template <class T>
class MinHeap : public MaxPQ<T>
{
public:
    MinHeap(int theCapacity = 10); // constructor
    bool IsEmpty() const;          // return true iff empty
    const T &Top() const;          // return reference to the max
    void Push(const T &);
    void Pop();

private:
    T *heap;      // element array
    int heapSize; // number of elements in heap
    int capacity; // size of the element array
};