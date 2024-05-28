#include "HW2_BagStackQueue.cpp"
#include "HW4_ThreadsBinaryTree.h"

template <class T>
ThreadsTree<T>::ThreadsTree() // Copy constructor
{
    root = new ThreadsTreeNode<T>(T());
    root->leftChild = NULL;
    root->leftThread = true;
    root->rightChild = root;
    root->rightThread = false;
}
template <class T>
ThreadsTree<T>::ThreadsTree(const ThreadsTree<T> &s) // Copy constructor
{
    root = s.root;
}
template <class T>
ThreadsTree<T>::ThreadsTree(ThreadsTree<T> &bt1, T item, ThreadsTree<T> &bt2)
{
    root = new ThreadsTreeNode<T>;
    root->data = item;
    root->leftChild = bt1.root;
    root->rightChild = bt2.root;
}
template <class T>
ThreadsTreeNode<T> *ThreadsTree<T>::Root()
{
    return root;
}
template <class T>
bool ThreadsTree<T>::IsEmpty()
{
    return (this->root == NULL) ? true : false;
}
template <class T>
T ThreadsTree<T>::RootData()
{
    return this->root->data;
}
template <class T>
ThreadsTreeNode<T> *ThreadsTree<T>::InorderSucc(ThreadsTreeNode<T> *node)
{
    ThreadsTreeNode<T> *temp = node->rightChild;
    if (node->rightThread)
        return temp;
    else
    {
        while (!temp->leftThread)
            temp = temp->leftChild;
        return temp;
    }
}
template <class T>
ThreadsTree<T> ThreadsTree<T>::RightSubtree()
{
    ThreadsTree<T> rightTree(*this);
    rightTree.root = rightTree.root->rightChild;
    return rightTree;
}
template <class T>
ThreadsTree<T> ThreadsTree<T>::LeftSubtree()
{
    ThreadsTree<T> leftTree(*this);
    leftTree.root = leftTree.root->leftChild;
    return leftTree;
}
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
        ThreadsTreeNode<T> *temp = InorderSucc(r);
        temp->leftChild = r;
    }
}
template <class T>
void ThreadsTree<T>::InsertLeft(ThreadsTreeNode<T> *s, ThreadsTreeNode<T> *l)
{ // insert r as the right child of s
    l->leftChild = s->leftChild;
    l->leftThread = s->leftThread;
    l->rightChild = s;
    l->rightThread = true; // leftChild is a thread
    s->leftChild = l;
    s->leftThread = false;
    if (!l->leftThread)
    {
        ThreadsTreeNode<T> *temp = InorderSucc(l);
        temp->rightChild = l;
    }
}
template <class T>
void ThreadsTree<T>::Inorder()
{
    ThreadsTreeNode<T> *current = InorderSucc(root);
    while (current != root)
    {
        cout << current->data << " ";
        current = InorderSucc(current);
    }
    cout << endl;
}
template <class T>
void ThreadsTree<T>::Preorder()
{
    ThreadsTreeNode<T> *current = root->leftChild;
    while (current != root)
    {
        cout << current->data << " ";
        if (!current->leftThread)
            current = current->leftChild;
        else if (!current->rightThread)
            current = current->rightChild;
        else
        {
            while (current != root && current->rightThread)
                current = current->rightChild;
            current = current->rightChild;
        }
    }
    cout << endl;
}
template <class T>
void ThreadsTree<T>::Postorder()
{
    ThreadsTreeNode<T> *current = root->leftChild;
    ThreadsTreeNode<T> *lastVisited = NULL;
    ThreadsTreeNode<T> *prev = root;

    while (current != root)
    {
        if (!current->leftThread && lastVisited != current->leftChild && lastVisited != current->rightChild)
        {
            prev = current;
            current = current->leftChild;
        }
        else if (!current->rightThread && lastVisited != current->rightChild)
        {
            prev = current;
            current = current->rightChild;
        }
        else
        {
            if (current != root->leftChild)
                cout << current->data << " ";
            if (current == prev)
            {
                current = lastVisited->rightChild;
                lastVisited = prev;
            }
            else
            {
                lastVisited = current;
                current = prev;
            }
        }
    }
    cout << root->leftChild->data << endl;
}
template <class T>
void ThreadsTree<T>::LevelOrder()
{
    Queue<ThreadsTreeNode<T> *> q;
    ThreadsTreeNode<T> *currentNode = root;
    while (currentNode)
    {
        Visit(currentNode);
        if (currentNode->leftChild)
            q.Push(currentNode->leftChild);
        if (currentNode->rightChild)
            q.Push(currentNode->rightChild);
        if (q.IsEmpty())
            return;
        currentNode = q.Front();
        q.Pop();
    }
}
template <class T>
void ThreadsTree<T>::NonrecInorder()
{
    Stack<ThreadsTreeNode<T> *> s;
    ThreadsTreeNode<T> *currentNode = root;
    while (1)
    {
        while (currentNode)
        {
            s.Push(currentNode);
            currentNode = currentNode->leftChild;
        }
        if (s.IsEmpty())
            return;
        currentNode = s.Top();
        s.Pop();
        Visit(currentNode);
        currentNode = currentNode->rightChild;
    }
}
template <class T>
void ThreadsTree<T>::NoStackInorder()
{ // 使用固定量額外空間的二元樹中序走訪
    if (!root)
        return; // 空的二元樹
    ThreadsTreeNode<T> *top = 0, *lastRight = 0, *p, *q, *r, *r1;
    p = q = root;
    while (1)
    {
        while (1)
        {
            if ((!p->leftChild) && (!p->rightChild))
            { // 樹葉節點
                Visit(p);
                break;
            }
            if (!p->leftChild)
            { // 拜訪p並移至p→rightChild
                Visit(p);
                r = p->rightChild;
                p->rightChild = q;
                q = p;
                p = r;
            }
            else
            { // 移至p→leftChild
                r = p->leftChild;
                p->leftChild = q;
                q = p;
                p = r;
            }
        } // 內圈while結束
        // p是一個葉節點，向上移至右子樹還沒被檢查的節點
        ThreadsTreeNode<T> *av = p;
        while (1)
        {
            if (p == root)
                return;
            if (!q->leftChild)
            { // q是透過rightChild鏈結的
                r = q->rightChild;
                q->rightChild = p;
                p = q;
                q = r;
            }
            else if (!q->rightChild)
            { // q是透過leftChild鏈結的
                r = q->leftChild;
                q->leftChild = p;
                p = q;
                q = r;
                Visit(p);
            }
            else // 檢查p是否為q的rightChild
            {
                if (q == lastRight)
                {
                    r = top;
                    lastRight = r->leftChild;
                    top = r->rightChild; // 彈出堆疊
                    r->leftChild = r->rightChild = 0;
                    r = q->rightChild;
                    q->rightChild = p;
                    p = q;
                    q = r;
                }
                else
                { // p是q的leftChild
                    Visit(q);
                    av->leftChild = lastRight;
                    av->rightChild = top;
                    top = av;
                    lastRight = q;
                    r = q->leftChild;
                    q->leftChild = p;
                    r1 = q->rightChild;
                    q->rightChild = r;
                    p = r1;
                    break;
                }
            }
        } // 內圈while結束
    } // 外圈while結束
}
template <class T>
bool ThreadsTree<T>::operator==(const ThreadsTree &t)
{
    return Equal(root, t.root);
}
// template <class T>
// ThreadsTreeNode<T> *ThreadsTree<T>::Copy(ThreadsTreeNode<T> *p)
// { // Return a pointer to an exact copy of the tree rooted at p
//     if (!p)
//         return 0; // a null pointer empty BT
//     ThreadsTreeNode<T> *newroot;
//     newroot->data = p->data;
//     newroot->leftChild = p->leftChild;
//     newroot->rightChild = p->rightChild;

//     return newroot;
// }
template <class T>
bool ThreadsTree<T>::Equal(const ThreadsTree<T> &t)
{
    if ((t.root == NULL) && (this->root == NULL)) // two empty trees
        return true;
    return ((t.root && this->root) && (t.root->data == this->root->data) && Equal(t.root->leftChild, this->root->leftChild) && Equal(t.root->rightChild, this->root->rightChild));
}
template <class T>
bool ThreadsTree<T>::Equal(ThreadsTreeNode<T> *a, ThreadsTreeNode<T> *b)
{
    if ((a == NULL) && (b == NULL)) // two empty trees
        return true;
    return ((a && b) && (a->data == b->data) && Equal(a->leftChild, b->leftChild) && Equal(a->rightChild, b->rightChild));
    // both a and b are non-zero, data is the same
}
template <class T>
void ThreadsTree<T>::setup1()
{
    this->root->data = '+';
}
template <class T>
void ThreadsTree<T>::setup2()
{
}
template <class T>
void ThreadsTree<T>::output()
{
}