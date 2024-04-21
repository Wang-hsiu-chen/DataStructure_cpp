#include <iostream>
using namespace std;

template <class T>
class Queue
{
    template <class U>
    friend ostream &operator<<(ostream &os, Queue<U> &queue);

public:
    Queue(int queueCapacity = 0);
    bool IsEmpty() const;
    void Push(const T &item);
    void Pop();
    T &Front() const;
    T &Rear() const;
    int Size() const;
    int Capacity() const;
    Queue<T> Merge(Queue<T> q);

private:
    T *queue;
    int front, rear, capacity;
};