#include "1_Sorting.h"

template <class T>
void Sorting<T>::InsertionSort(T *a, const int n)
{ // sort a[1:n] into nondecreasing order
    for (int j = 1; j < n; j++)
    {
        T temp = a[j];
        int i;
        for (i = j; i > 0 && a[i - 1] > temp; i--)
        {
            a[i] = a[i - 1];
        }
        a[i] = temp;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << ", ";
    cout << endl;
}

template <class T>
void Sorting<T>::QuickSort(T *a, const int left, const int right)
{ // sort a[left:right] into nondecreasing, a[left] as pivot
    if (left < right)
    {
        T &pivot = a[left];
        int i = left;
        int j = right + 1;
        do
        {
            do
                j--;
            while (a[j] > pivot); // find a key ≤pivot
            do
                i++;
            while (a[i] <= pivot); // find a key >pivot
            if (i < j)
                swap(a[i], a[j]);
        } while (i < j);
        swap(pivot, a[j]);          // place the pivot between 2 lists
        QuickSort(a, left, j - 1);  // recursion
        QuickSort(a, j + 1, right); // recursion
    }
}