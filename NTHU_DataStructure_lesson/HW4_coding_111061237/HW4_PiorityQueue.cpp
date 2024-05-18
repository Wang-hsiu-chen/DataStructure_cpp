#include "HW4_PiorityQueue.h"

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
MaxHeap<T>::MaxHeap(int theCapacity) : capacity(theCapacity), heapSize(0)
{
    if (theCapacity < 1)
        throw "Capacity must be >= 1";
    heap = new T[capacity + 1]; // heap[0] unused
}
template <class T>
bool MaxHeap<T>::IsEmpty() const
{
}
template <class T>
const T &MaxHeap<T>::Top() const
{
}
template <class T>
void MaxHeap<T>::Push(const T &e)
{
    if (heapSize == capacity)
    { // double the capacity
        ChangeSize1D(heap, capacity, 2 * capacity);
        capacity *= 2;
    }
    int currentNode = ++heapSize;
    while (currentNode != 1 && heap[currentNode / 2] < e)
    {                                              // bubbling up
        heap[currentNode] = heap[currentNode / 2]; // move parent down
        currentNode /= 2;
    }
    heap[currentNode] = e;
}
template <class T>
void MaxHeap<T>::Pop()
{
    if (IsEmpty())
        throw "Heap is empty.Cannot delete.";
    heap[1].~T();               // delete max element
    T lastE = heap[heapSize--]; // remove last element from heap
    // trickle down to find a position to place the last element
    int currentNode = 1; // root
    int child = 2;       // a child of current node
    while (child <= heapSize)
    {
        // set child to larger child of currentNode
        if (child < heapSize && heap[child] < heap[child + 1])
            child++;
        if (lastE >= heap[child])
            break;
        heap[currentNode] = heap[child]; // move child up
        currentNode = child;
        child *= 2; // move down a level
    }
    heap[currentNode] = lastE;
}
template <class T>
void MaxHeap<T>::OutputHeap()
{
    for (int i = 1; i <= heapSize; i++)
        cout << heap[i] << " ";
    cout << endl;
}
template <class T>
MinHeap<T>::MinHeap(int theCapacity) : capacity(theCapacity), heapSize(0)
{
    if (theCapacity < 1)
        throw "Capacity must be >= 1";
    heap = new T[capacity + 1]; // heap[0] unused
}
template <class T>
bool MinHeap<T>::IsEmpty() const
{
}
template <class T>
const T &MinHeap<T>::Top() const
{
}
template <class T>
void MinHeap<T>::Push(const T &t)
{
}
template <class T>
void MinHeap<T>::Pop()
{
}
