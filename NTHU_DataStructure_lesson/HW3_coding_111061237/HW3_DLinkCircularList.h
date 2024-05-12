#include <iostream>
using namespace std;

class DblList; // forward declaration
class DblListNode
{
    friend class DblList;

public:
    int data;

private:
    DblListNode *left, *right;
};
class DblList
{
public:
    // List manipuation operations
    DblList();
    ~DblList();
    int Size();
    void Insert(DblListNode *p, DblListNode *x);
    void Delete(DblListNode *x);
    DblListNode *Get(int index);
    void Concatenate(DblList m); // the resulting list should be stored in *this and the list m should contain the empty list. Your function must run in O(1) time.
    void Push(int x);            // insert at tail
    void Pop();                  // delete at head
    void Inject(int x);          // insert at head
    void Eject();                // delete at tail

private:
    DblListNode *head; // points to header node
};
