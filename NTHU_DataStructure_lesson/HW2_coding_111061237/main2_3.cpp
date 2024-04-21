#include "HW2_DoubleEndedQueue.cpp"

int main()
{
    Queue<int> Q1(1), Q2(1), Q3(1);
    int push;

    cin >> Q1;
    cin >> Q2;
    cout << "Q1 = " << Q1;
    cout << "Q2 = " << Q2;
    cout << "Q1 capacity: " << Q1.Capacity() << endl;
    cout << "is Q2 empty: " << Q2.IsEmpty();
    cout << "Q2 size: " << Q2.Size() << endl;
    cout << "Q1 push: ";
    cin >> push;
    Q1.Push(push);
    cout << "Q1: " << Q1;
    cout << "Q1 push in front: ";
    cin >> push;
    Q1.PushFront(push);
    cout << "Q1: " << Q1;
    cout << "Q1 rear: " << Q1.Rear() << endl;
    cout << "Q2 front: " << Q2.Front() << endl;
    Q2.Pop();
    cout << "Q2 after pop: " << Q2;
    Q2.PopRear();
    cout << "Q2 after pop in rear: " << Q2;
    Q3 = Q1.Merge(Q2);
    cout << "Q1 merge Q2: " << Q3;
}
