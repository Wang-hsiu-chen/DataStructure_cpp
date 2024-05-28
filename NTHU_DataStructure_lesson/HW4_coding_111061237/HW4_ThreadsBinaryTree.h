#include <iostream>
using namespace std;

// all functions need to be checked again
// some functions haven't be implement.
template <class T>
class InorderIterator;
template <class T>
class ThreadsTree;
template <class T>
class ThreadsTreeNode
{
    friend class ThreadsTree<T>;
    friend class InorderIterator<T>; // inorder iterator
public:
    ThreadsTreeNode(const T &value);

private:
    T data;
    ThreadsTreeNode<T> *leftChild;
    ThreadsTreeNode<T> *rightChild;
    bool leftThread;
    bool rightThread;
};
template <class T>
ThreadsTreeNode<T>::ThreadsTreeNode(const T &value)
{
    data = value;
    leftThread = true;
    leftChild = NULL;
    rightThread = true;
    rightChild = NULL;
}

template <class T>
class ThreadsTree
{
    friend class InorderIterator<T>; // inorder iterator
public:
    ThreadsTree(); // constructor for an empty binary tree
    ThreadsTree(ThreadsTree<T> &bt1, T item, ThreadsTree<T> &bt2);
    ThreadsTree(const ThreadsTree<T> &); // copy constructor
    // constructor given the root item and left subtrees bt1 and right subtree bt2
    bool IsEmpty();                // return true iff the binary tree is empty
    ThreadsTree<T> LeftSubtree();  // return the left subtree
    ThreadsTree<T> RightSubtree(); // return the right subtree
    ThreadsTreeNode<T> *Root();
    T RootData(); // return the data in the root node of *this
    void InsertRight(ThreadsTreeNode<T> *s, ThreadsTreeNode<T> *r);
    void InsertLeft(ThreadsTreeNode<T> *s, ThreadsTreeNode<T> *r);
    void Inorder();
    void Preorder();
    void Postorder();
    void LevelOrder();
    void NonrecInorder();
    void NoStackInorder();
    bool operator==(const ThreadsTree &t);
    ThreadsTreeNode<T> *InorderSucc(ThreadsTreeNode<T> *node);
    bool Equal(const ThreadsTree<T> &t);
    bool Equal(ThreadsTreeNode<T> *a, ThreadsTreeNode<T> *b);
    void setup1();
    void setup2();
    void output();

private:
    ThreadsTreeNode<T> *root;
};
template <class T>
class InorderIterator
{
public:
    InorderIterator() { currentNode = t.root; } // Constructor
    InorderIterator(ThreadsTree<T> tree) : t(tree) { currentNode = t.root; }
    T *Next()
    {
        ThreadsTreeNode<T> *temp = currentNode->rightChild;
        if (currentNode->rightThread)
        {
            currentNode = temp;
        }
        else
        {
            while (!temp->leftThread)
                temp = temp->leftChild;
            currentNode = temp;
        }
        if (currentNode == t.head)
            return 0;
        else
            return &currentNode->data;
    }
    T &operator*();
    bool operator!=(const InorderIterator r);

private:
    ThreadsTree<T> t;
    Stack<ThreadsTreeNode<T> *> s;
    ThreadsTreeNode<T> *currentNode;
};
