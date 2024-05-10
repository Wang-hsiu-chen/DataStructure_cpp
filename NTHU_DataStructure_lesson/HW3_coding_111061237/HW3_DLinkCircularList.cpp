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
}
void DblList::Pop()
{
}
void DblList::Inject(int x)
{
}
void DblList::Eject()
{
}