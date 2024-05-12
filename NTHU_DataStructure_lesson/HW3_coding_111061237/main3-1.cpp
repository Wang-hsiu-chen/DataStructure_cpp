#include "HW3_TemplateChain.cpp"

int main()
{
    Chain<int> a;
    Chain<int> b;
    Chain<int> c;
    int e, index;
    cout << "Is empty: " << a.IsEmpty() << endl;
    cout << "Insert head: ";
    a.InsertHead(1);
    cout << "\nInsert back: ";
    a.InsertBack(2);
    cout << "\nSize: " << a.Size() << endl;
    cout << "Front: " << a.Front() << endl;
    cout << "Back: " << a.Back() << endl;
    cout << "Get: ";
    cout << a.Get(1) << endl;
    cout << "Set: ";
    cout << a.Set(1, 3) << endl;
    cout << "Insert: ";
    a.Insert(1, 4);
    cout << "Index of " << 4 << ": " << a.IndexOf(4) << endl;
    cout << "\nDelete Odd: " << endl;
    a.DeleteOdd();
    for (int i = 0; i < a.Size(); i++)
        cout << a.Get(i) << " ";
    cout << "\nDelete 0" << endl;
    a.Delete(0);
    cout << "Construct b: " << endl;
    for (int i = 0; i < 4; i++)
    {
        b.InsertBack(i + 1);
        cout << b.Get(i) << " ";
    }
    cout << "Construct c: " << endl;
    for (int i = 0; i < 4; i++)
    {
        c.InsertBack(0);
        cout << c.Get(i) << " ";
    }
    cout << "\na Concatenate b: ";
    a.Concatenate(b);
    for (int i = 0; i < a.Size(); i++)
        cout << a.Get(i) << " ";
    cout << "\na Merge c: ";
    a.Merge(c);
    for (int i = 0; i < a.Size(); i++)
        cout << a.Get(i) << " ";
    cout << "\na Divide middle: " << endl;
    a.DivideMid(c);
    for (int i = 0; i < a.Size(); i++)
        cout << a.Get(i) << " ";
    cout << endl;
    for (int i = 0; i < c.Size(); i++)
        cout << c.Get(i) << " ";
    cout << "\na Reverse: ";
    a.Reverse();
    for (int i = 0; i < a.Size(); i++)
        cout << a.Get(i) << " ";
    cout << "finish";
    return 0;
    // LinkedStack<int> S;
    // for (int i = 0; i < 4; i++)
    // {
    //     S.Push(i);
    //     cout << S.Get(i) << " ";
    // }
    // cout << "\nS top: " << S.Top() << endl;
}