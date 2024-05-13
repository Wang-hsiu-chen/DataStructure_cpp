#include "HW2_BagStackQueue.h"
#include "HW4_BinaryTree.h"

template <class T>
Tree<T>::Tree(const Tree<T> &s) // Copy constructor
{
    root = Copy(s.root);
}
template <class T>
void Tree<T>::Inorder()
{
    Inorder(root);
}
template <class T>
void Tree<T>::Inorder(TreeNode<T> *t)
{
    if (t != NULL)
    {
        Inorder(t->leftChild); // L
        Visit(t);
        Inorder(t->rightChild); // R
    }
}
template <class T>
void Tree<T>::Preorder()
{
    Preorder(root);
}
template <class T>
void Tree<T>::Preorder(TreeNode<T> *t)
{
    if (t != NULL)
    {
        Visit(t);
        Preorder(t->leftChild);  // L
        Preorder(t->rightChild); // R
    }
}
template <class T>
void Tree<T>::Postorder()
{
    Postorder(root);
}
template <class T>
void Tree<T>::Postorder(TreeNode<T> *t)
{
    if (t != NULL)
    {
        Postorder(t->leftChild);  // L
        Postorder(t->rightChild); // R
        Visit(t);
    }
}
template <class T>
void Tree<T>::LevelOrder()
{
    Queue<TreeNode<T> *> q;
    TreeNode<T> *currentNode = root;
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
void Tree<T>::NonrecInorder()
{
    Stack<TreeNode<T> *> s;
    TreeNode<T> *currentNode = root;
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
void Tree<T>::NoStackInorder()
{ // 使用固定量額外空間的二元樹中序走訪
    if (!root)
        return; // 空的二元樹
    TreeNode<T> *top = 0, *lastRight = 0, *p, *q, *r, *r1;
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
        TreeNode<T> *av = p;
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
                    r = q->leftchild;
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
bool Tree<T>::operator==(const Tree &t) const
{
    return Equal(root, t.root);
}
template <class T>
TreeNode<T> *Tree<T>::Copy(TreeNode<T> *p)
{ // Return a pointer to an exact copy of the tree rooted at p
    if (p == NULL)
        return 0;
    return new TreeNode<T>(p->data, Copy(p->leftChild), Copy(p->rightChild));
}
template <class T>
bool Tree<T>::Equal(TreeNode<T> *a, TreeNode<T> *b)
{
    if ((a == NULL) && (b == NULL)) // two empty trees
        return true;
    return ((a && b) && (a->data == b->data) && Equal(a->leftChild, b->leftChild) && Equal(a->rightChild, b->rightChild));
    // both a and b are non-zero, data is the same
}
