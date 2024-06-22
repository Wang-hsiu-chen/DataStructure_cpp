#include <iostream>

using namespace std;

template <class T>
class Sorting
{
public:
    Sorting(){};
    void InsertionSort(T *a, const int n);
    void QuickSort(T *a, const int left, const int right);
    void MergeSort(T *a, int n);
    void RecursiveMergeSort(T *a, const int left, const int right);
    void HeapSort(T *a, const int n);
    void RadixSort();

private:
    void MergePass(T *a, T *b, const int n, const int s);
    void Merge(T *a, T *b, const int k, const int m, const int n);
    void MergeNoReturn(T *a, int left, int mid, int right);
    void Adjust(T *a, const int root, const int n);
    int CompareString(string x, string y);
};