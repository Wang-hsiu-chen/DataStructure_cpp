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