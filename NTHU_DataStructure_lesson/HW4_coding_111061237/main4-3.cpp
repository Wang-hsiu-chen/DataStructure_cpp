#include "HW4_PiorityQueue.cpp"

int main()
{
    MaxHeap<int> a(14);
    int arr[13] = {50, 5, 30, 40, 80, 35, 2, 20, 15, 60, 70, 8, 10};
    for (int i = 0; i < 13; i++)
    {
        a.Push(arr[i]);
        a.OutputHeap();
    }
    return 0;
}