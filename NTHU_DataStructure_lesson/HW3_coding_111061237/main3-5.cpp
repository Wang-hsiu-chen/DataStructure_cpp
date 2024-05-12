#include "HW3_DLinkCircularList.cpp"

int main()
{
    DblList a;
    DblListNode *node;
    DblList b;
    int e, index;
    cout << "Push: " << endl;
    a.Push(1);
    for (int i = 0; i < a.Size(); i++)
        cout << a.Get(i)->data << " ";
    cout << "Inject: " << endl;
    a.Inject(3);
    for (int i = 1; i < a.Size(); i++)
        cout << a.Get(i)->data << " ";
    // cout << "Insert front: " << endl;
    // a.Insert(node, a.Get(1));
    cout << "Pop: " << endl;
    a.Pop();
    for (int i = 0; i < a.Size(); i++)
        cout << a.Get(i)->data << " ";
    cout << "Eject: " << endl;
    a.Eject();
    for (int i = 0; i < a.Size(); i++)
        cout << a.Get(i)->data << " ";
    cout << "Delete: " << endl;
    // a.Delete(a.Get(1));

    for (int i = 0; i < a.Size(); i++)
        cout << a.Get(i)->data << " ";

    cout << "\nAdd some elements into b: " << endl;
    for (int i = 0; i < 4; i++)
    {
        b.Push(i + 1);
        cout << b.Get(i)->data << " ";
    }
    cout << "finish";
    return 0;
}