#include "HW4_PiorityQueue.cpp"

int main()
{
    MaxHeap<int> pq(13);
    int arr[13] = {50, 5, 30, 40, 80, 35, 2, 20, 15, 60, 70, 8, 10};
    for (int i = 0; i < 13; i++)
    {
        pq.Push(arr[i]);
        pq.OutputHeap();
    }

    if (pq.IsEmpty())
        cout << "The Heap is empty";
    else
        cout << "The Heap is not empty" << endl;
    cout << "Max element: " << pq.Top() << endl;
    cout << "Pop: ";
    pq.Pop();
    pq.OutputHeap();

    cout << "Initialize using bottom up : " << endl;
    MaxHeap<int> pq1(13, arr);
    pq1.OutputHeap();
    return 0;
}