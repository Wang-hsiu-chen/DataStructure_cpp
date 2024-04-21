#include "HW2_BagStackQueue.cpp"

int main()
{
    Stack<int> S1(1);
    Stack<float> S2(1);
    Queue<int> Q1(1);
    Queue<float> Q2(1);
    int push;
    float pu;

    // int
    cout << "type in int" << endl;
    cin >> S1;
    cout << "S1: " << S1;
    cout << "S1 size: " << S1.Size() << endl;
    S1.Pop();
    cout << "S1 pop: " << S1;
    cout << "put in: ";
    cin >> push;
    S1.Push(push);
    cout << "S1 = " << S1 << endl;

    // float
    cout << "type in float" << endl;
    cin >> S2;
    cout << "S2: " << S2;
    cout << "S2 size: " << S2.Size() << endl;
    S2.Pop();
    cout << "S2 pop: " << S2;
    cout << "put in: ";
    cin >> pu;
    S2.Push(pu);
    cout << "S2 = " << S2 << endl;

    // int
    cout << "type in int" << endl;
    cin >> Q1;
    cout << "Q1: " << Q1;
    cout << "Q1 size: " << Q1.Size() << endl;
    Q1.Pop();
    cout << "Q1 pop: " << Q1;
    cout << "put in: ";
    cin >> push;
    Q1.Push(push);
    cout << "Q1 = " << Q1 << endl;

    // float
    cout << "type in float" << endl;
    cin >> Q2;
    cout << "Q2: " << Q2;
    cout << "Q2 size: " << Q2.Size() << endl;
    Q2.Pop();
    cout << "Q2 pop: " << Q2;
    cout << "put in: ";
    cin >> pu;
    Q2.Push(pu);
    cout << "Q2 = " << Q2 << endl;

    return 0;
}