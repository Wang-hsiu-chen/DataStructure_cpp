#include <iostream>

using namespace std;

template <class T>
class Sorting
{
public:
    Sorting(){};
    void InsertionSort(T *a, const int n);
    void QuickSort(T *a, const int left, const int right);
    void MergeSort(T *a, const int n);
    void RecursiveMergeSort(T *a, const int n);
    void HeapSort(T *a, const int n);
    void RadixSort();

private:
};