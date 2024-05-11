#include "HW3_DLinkCircularList.h"

DblList::DblList()
{
    head = NULL;
}
DblList::~DblList()
{
    while (head != NULL)
    {
        CNode<T> *temp = head->right;
        delete head;
        if (temp != NULL)
            head = temp->right;
    }
}
void DblList::Insert(DblListNode *p, DblListNode *x)
{
    p->left = x;
    p->right = x->right;
    x->right->left = p;
    x->right = p;
}
void DblList::Delete(DblListNode *x)
{
    if (x == head)
        throw "Deletion of header node not permitted";
    else
    {
        x->left->right = x->right;
        x->right->left = x->left;
        delete x;
    }
}
void DblList::Concatenate(DblList m)
{
    DblListNode *last = head->left;
    last->right = m.head;
    m.head->left->right = head;
    head->left = m.head->left;
    m.head->left = last;
}
void DblList::Push(int x)
{
    DblListNode *newNode;
    newNode->data = x;
    newNode->right = head;
    newNode->left = head->left;
    head->left->right = newNode;
    head->left = newNode;
}
void DblList::Pop()
{
    DblListNode *deleteNode = head;
    head->left->right = head->right;
    head->right->left = head->left;
    head = head->right;
    delete deleteNode;
}
void DblList::Inject(int x)
{
    DblListNode *newNode;
    newNode->data = x;
    newNode->right = head;
    newNode->left = head->left;
    head->left->right = newNode;
    head->left = newNode;
    head = newNode;
}
void DblList::Eject()
{
    DblListNode *deleteNode = head->left;
    deleteNode->left->right = head;
    head->left = deleteNode->left;
    delete deleteNode;
}