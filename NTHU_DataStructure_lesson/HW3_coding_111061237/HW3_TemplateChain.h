#include <iostream>
using namespace std;

template <class T>
class Chain; // 前向宣告
template <class T>
class ChainNode
{
    friend class Chain<T>;

private:
    T data;
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
    const T &Front();
    const T &Back();
    void InsertBack(const T &e);
    void DeleteBack();
    T &Get(int index);
    T &Set(int index, const T &e);
    int IndexOf(const T &e) const;
    void Delete(int index);
    void DeleteOdd();
    void Insert(int index, const T &e);
    void DivideMid(Chain<T> &b);
    void Concatenate(Chain<T> &b);
    Chain Deconcatenate(ChainNode<T> *p);
    void Merge(Chain<T> &b);
    void Reverse();
    void Delete(Position p);
    void Insert(Position p, const T &e); // Position means ChainNode*)
    class ChainIterator
    {
    public: // typedefs required by C++ for a forward iterator
        // Constructor
        ChainIterator(ChainNode<T> *startNode = 0)
        {
            current = startNode;
        }
        // Dereferencing operators
        T &operator*() const { return current->data; }
        T *operator->() const { return &current->data; }
        // Increment
        ChainIterator &operator++() // preincrement
        {
            current = current->link;
            return *this;
        }
        ChainIterator &operator++(int) // postincrement
        {
            ChainIterator old = *this;
            current = current->link;
            return old;
        }
        // Equality test
        bool operator!=(const ChainIterator r)
        {
            return current != r.current;
        }
        bool operator==(const ChainIterator r)
        {
            return current == r.current;
        }

    private:
        ChainNode<T> *current;
    };
    ChainIterator begin() { return ChainIterator(first); }
    ChainIterator end() { return ChainIterator(0); }

private:
    ChainNode<T> *first, *last;
};

template <class T>
class LinkedStack : TemplateChain
{
public:
    LinkedStack() { top = 0; }; // constructor
    void Push(const T &);
    T &Top() const;
    void Pop();
    bool IsEmpty();

private:
    ChainNode<T> *top;
};

template <class T>
class LinkedQueue : TemplateChain
{
public:
    LinkedQueue() { front = rear = 0; }; // constructor
    void Push(const T &);
    T &Front() const;
    T &Rear() const;
    void Pop();
    bool IsEmpty();

private:
    ChainNode<T> *front, *rear;
};