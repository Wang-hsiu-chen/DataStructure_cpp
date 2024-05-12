#include "HW3_CircularList.cpp"

int main()
{
    CircleList<int> a;
    CircleList<int> b;
    int e, index;
    cout << "add some element into a: " << endl;
    for (int i = 0; i < 4; i++)
        a.InsertBack(i + 1);
    cout << "Insert front: " << endl;
    a.InsertFront(1);
    for (int i = 0; i < a.Size(); i++)
        cout << a.Get(i) << " ";
    cout << "\nInsert back: " << endl;
    a.InsertBack(2);
    for (int i = 0; i < a.Size(); i++)
        cout << a.Get(i) << " ";
    cout << "\nSize: " << a.Size() << endl;
    cout << "Delete Odd: " << endl;
    a.DeleteOdd();
    for (int i = 0; i < a.Size(); i++)
        cout << a.Get(i) << " ";
    cout << "\nDelete first: " << endl;
    a.DeleteFirst();
    for (int i = 0; i < a.Size(); i++)
        cout << a.Get(i) << " ";
    cout << "\nDelete back: " << endl;
    a.DeleteBack();
    for (int i = 0; i < a.Size(); i++)
        cout << a.Get(i) << " ";

    cout << "\nAdd some elements into b: " << endl;
    for (int i = 0; i < 4; i++)
    {
        b.InsertBack(i + 1);
        cout << b.Get(i) << " ";
    }
    cout << "\na Merge b: ";
    a.Merge(b);
    for (int i = 0; i < a.Size(); i++)
        cout << a.Get(i) << " ";
    cout << "finish";
    return 0;
}