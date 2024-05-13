#include <iostream>
using namespace std;

template <class T>
class ThreadsTree;
template <class T>
class ThreadsTreeNode
{
    friend class ThreadsTree<T>;
    friend class InorderIterator<T>; // inorder iterator
private:
    T data;
    ThreadsTreeNode<T> *leftChild;
    ThreadsTreeNode<T> *rightChild;
};

template <class T>
class ThreadsTree
{
    friend class InorderIterator<T>; // inorder iterator
public:
    ThreadsTree(); // constructor for an empty binary tree
    ThreadsTree(ThreadsTree<T> &bt1, T &item, ThreadsTree<T> &bt2);
    ThreadsTree(const ThreadsTree<T> &); // copy constructor
    // constructor given the root item and left subtrees bt1 and right subtree bt2
    bool IsEmpty();                // return true iff the binary tree is empty
    ThreadsTree<T> LeftSubtree();  // return the left subtree
    ThreadsTree<T> RightSubtree(); // return the right subtree
    T RootData();                  // return the data in the root node of *this
    void InsertRight(ThreadsTreeNode<T> *s, ThreadsTreeNode<T> *r);
    void Inorder();
    void Preorder();
    void Postorder();
    void LevelOrder();
    void NonrecInorder();
    void NoStackInorder();
    bool operator==(const ThreadsTree &t);
    ThreadsTreeNode<T> *Copy(ThreadsTreeNode<T> *p); // Workhorse
    bool Equal(const ThreadsTree<T> &t);
    bool Equal(ThreadsTreeNode<T> *a, ThreadsTreeNode<T> *b);
    void setup1();
    void setup2();
    void output();

private:
    TreeNode<T> *root;
    void Visit(ThreadsTreeNode<T> *p) { cout << p->data << "  "; }
};
template <class T>
class InorderIterator
{
public:
    InorderIterator() { currentNode = root; } // Constructor
    InorderIterator(ThreadsTree<T> tree) : t(tree) { currentNode = t.root; }
    T *Next()
    {
        ThreadedNode<T> *temp = currentNode->rightChild;
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
        if (currentNode == head)
            return 0;
        else
            return &currentNode->data;
    }
    T &operator*();
    bool operator!=(const InorderIterator r) private : Tree<T> t;
    Stack<TreeNode<T> *> s;
    TreeNode<T> *currentNode;
};
template <class T>
void ThreadsTree<T>::InsertRight(ThreadsTreeNode<T> *s, ThreadsTreeNode<T> *r)
{ // insert r as the right child of s
    r->rightChild = s->rightChild;
    r->rightThread = s->rightThread;
    r->leftChild = s;
    r->leftThread = true; // leftChild is a thread
    s->rightChild = r;
    s->rightThread = false;
    if (!r->rightThread)
    {
        ThreadedNode<T> *temp = InorderSucc(r);
        temp->leftChild = r;
    }
}
