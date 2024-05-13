#include "HW2_BagStackQueue.h"

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
Bag<T>::Bag(int bagCapacity) : capacity(bagCapacity)
{
    if (capacity < 1)
        throw "Capacity must be > 0";
    array = new T[capacity];
    top = -1;
}

template <class T>
Bag<T>::~Bag()
{
    delete[] array;
}

template <class T>
inline int Bag<T>::Size() const
{
    return top + 1;
}

template <class T>
bool Bag<T>::IsEmpty() const
{
    return (Size() == 0);
}

template <class T>
T &Bag<T>::Element() const
{
    if (IsEmpty())
        throw "Bag empty";
    return array[0];
}

template <class T>
void Bag<T>::Push(const T &x)
{
    if (capacity == top + 1)
    {
        ChangeSize1D(array, capacity, 2 * capacity);
        capacity *= 2;
    }
    array[++top] = x;
}

template <class T>
void Bag<T>::Pop()
{
    if (IsEmpty())
        throw "Bag is empty, cannot delete";
    int deletePos = top / 2;
    copy(array + deletePos + 1, array + top + 1, array + deletePos);
    array[top--].~T();
}

// stack
template <class T>
Stack<T>::Stack(int stackCapacity) : Bag<T>(stackCapacity) {}

template <class T>
Stack<T>::~Stack() {}

template <class T>
inline T &Stack<T>::Top() const
{
    if (IsEmpty())
        throw "Stack empty";
    return array[top];
}

template <class T>
void Stack<T>::Pop()
{
    if (IsEmpty())
        throw "Stack is empty, cannot delete";
    array[top--].~T();
}

template <class T>
ostream &operator<<(ostream &os, Stack<T> &stack)
{
    os << "(" << stack.array[0];
    for (int i = 1; i < stack.Size(); i++)
        os << ", " << stack.array[i];
    os << ")" << endl;

    return os;
}

template <class T>
istream &operator>>(istream &is, Stack<T> &stack)
{
    int num;
    float temp;

    cout << "element num: ";
    is >> num;
    cout << "elements: ";
    for (int i = 0; i < num; i++)
    {
        is >> temp;
        stack.Push(temp);
    }
    return is;
}

// Queue
template <class T>
Queue<T>::Queue(int queueCapacity) : Bag<T>(queueCapacity)
{
    front = 0;
    rear = 0;
}

template <class T>
Queue<T>::~Queue() {}

template <class T>
void Queue<T>::Push(const T &item)
{
    if ((rear + 1) % capacity == front)
    {
        T *newQueue = new T[2 * capacity];
        int start = (front + 1) % capacity;
        if (start < 2)
            copy(array + start, array + start + capacity - 1, newQueue);
        else
        {
            copy(array + start, array + capacity, newQueue);
            copy(array, array + rear + 1, newQueue + capacity - start);
        }
        front = 2 * capacity - 1;
        rear = capacity - 2;
        delete[] array;
        array = newQueue;
        capacity *= 2;
    }
    rear = (rear + 1) % capacity;
    array[rear] = item;
}

template <class T>
void Queue<T>::Pop()
{
    if (IsEmpty())
        throw "Queue is empty, cannot delete";
    front = (front + 1) % capacity;
    array[front].~T(); // destructor for T
}

template <class T>
ostream &operator<<(ostream &os, Queue<T> &queue)
{
    os << "(" << queue.array[(queue.front + 1) % queue.capacity];
    for (int i = (queue.front + 2) % queue.capacity; i != (queue.rear + 1) % queue.capacity;)
    {
        os << ", " << queue.array[i];
        i = (i + 1) % queue.capacity;
    }
    os << ")" << endl;

    return os;
}

template <class T>
istream &operator>>(istream &is, Queue<T> &queue)
{
    int num;
    float temp;

    cout << "element num: ";
    is >> num;
    cout << "elements: ";
    for (int i = 0; i < num; i++)
    {
        is >> temp;
        queue.Push(temp);
    }
    return is;
}

template <class T>
inline int Queue<T>::Size() const
{
    int result = (rear - front);
    if (result < 0)
        return result + capacity;
    else
        return result;
}
