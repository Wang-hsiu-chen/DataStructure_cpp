#include <iostream>
using namespace std;

class DblList; // forward declaration
class DblListNode
{
    friend class DblList;

private:
    int data;
    DblListNode *left, *right;
};
class DblList
{
public:
    // List manipuation operations
    DblList();
    ~DblList();
    void Insert(DblListNode *p, DblListNode *x);
    void Delete(DblListNode *x);
    void Concatenate(DblList m); // the resulting list should be stored in *this and the list m should contain the empty list. Your function must run in O(1) time.
    void Push(int x);            // insert at tail
    void Pop;                    // delete at head
    void Inject(int x);          // insert at head
    void Eject();                // delete at tail

private:
    DblListNode *head; // points to header node
};
