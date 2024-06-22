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
        int i = left;
        int j = right + 1;
        do
        {
            do
                j--;
            while (a[j] > a[left]); // find a key ≤pivot
            do
                i++;
            while (a[i] <= a[left]); // find a key >pivot
            if (i < j)
                swap(a[i], a[j]);
        } while (i < j);
        swap(a[left], a[j]);        // place the pivot between 2 lists
        QuickSort(a, left, j - 1);  // recursion
        QuickSort(a, j + 1, right); // recursion
    }
}
template <class T>
void Sorting<T>::MergeSort(T *a, int n)
{ // sort a[1:n] into non-decreasing order
    n = n + 1;
    T *A = new T[n];
    for (int i = 1; i < n; i++)
        A[i] = a[i - 1];
    T *tempList = new T[n + 1];
    // s is the length of the currently merged sublist
    for (int s = 1; s < n; s *= 2)
    {
        MergePass(A, tempList, n, s);
        s *= 2;
        MergePass(tempList, A, n, s);
    }
    for (int i = 2; i < n + 1; i++)
        cout << A[i] << ", ";
    cout << endl;
}
template <class T>
void Sorting<T>::MergePass(T *a, T *b, const int n, const int s)
{ // adjacent pairs of sublist of size s are merged from a to b. n = # records in a
    int i = 1;
    for (i = 1;                // i the first position in first of the sublists merged
         i <= n - (2 * s) + 1; // enough elements for 2 sublists of length s?
         i += 2 * s)
    {
        Merge(a, b, i, i + s - 1, i + (2 * s) - 1);
    }
    // merge remaining lists of size < 2*s
    if ((i + s - 1) < n) // one full and one partial lists
        Merge(a, b, i, i + s - 1, n);
    else // only one partial lists remained

        copy(a + i, a + n + 1, b + i);
}

template <class T>
void Sorting<T>::Merge(T *a, T *b, const int k, const int m, const int n)
{ // a[k:m], a[m+1:n] are sorted, merged to b[k:n]
    int i1 = k, i2 = m + 1, i3 = k;
    for (i1 = k, i2 = m + 1, i3 = k; i1 <= m && i2 <= n; i3++)
    {
        if (a[i1] <= a[i2])
        {
            b[i3] = a[i1];
            i1++;
        }
        else
        {
            b[i3] = a[i2];
            i2++;
        }
    }
    // copy remaining records, if any, of 1st sublist
    if (i2 > n)
        copy(a + i1, a + m + 1, b + i3);
    // copy remaining records, if any, of 2nd sublist
    if (i1 > m)
        copy(a + i2, a + n + 1, b + i3);
}
template <class T>
void Sorting<T>::RecursiveMergeSort(T *a, const int left, const int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        RecursiveMergeSort(a, left, mid);
        RecursiveMergeSort(a, mid + 1, right);
        MergeNoReturn(a, left, mid, right);
    }
}
template <class T>
void Sorting<T>::MergeNoReturn(T *a, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    if (n1 == 0 || n2 == 0)
        return;
    // T *tempList = new T(100);
    // int *temp = new int(100);
    // T *leftList = new T[10];
    // T *rightList = new T[10];
    T leftList[n1];
    T rightList[n2];

    for (int i = 0; i < n1; ++i)
        leftList[i] = a[left + i];
    for (int j = 0; j < n2; ++j)
        rightList[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftList[i] <= rightList[j])
        {
            a[k] = leftList[i];
            ++i;
        }
        else
        {
            a[k] = rightList[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        a[k] = leftList[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        a[k] = rightList[j];
        ++j;
        ++k;
    }
}
template <class T>
void Sorting<T>::Adjust(T *a, const int root, const int n)
{
    int largest = n;
    int left = 2 * n + 1;
    int right = 2 * n + 2;

    if (left < root && a[left] > a[largest])
        largest = left;

    if (right < root && a[right] > a[largest])
        largest = right;

    if (largest != n)
    {
        swap(a[n], a[largest]);
        Adjust(a, root, largest);
    }
}
template <class T>
void Sorting<T>::HeapSort(T *a, const int n)
{ // sort a[1..n] into non-decreasing order
    // a[n/2] is the parent of the last node, a[n]
    for (int i = n / 2 - 1; i >= 0; --i) // buttom-up heapification
        Adjust(a, n, i);                 // make the tree rooted at i be a max heap
    for (int i = n - 1; i >= 0; --i)
    {
        swap(a[0], a[i]); // move one record from heap to list
        Adjust(a, i, 0);  // heapify
    }
}

template <class T>
int Sorting<T>::CompareString(string x, string y)
{
    int i = 0;
    int xlength = x.length();
    int yLength = y.length();
    int minLength = (xlength < yLength) ? xlength : yLength;
    while (x[i] == y[i] && i < minLength)
        i++;
    if (i == minLength)
    {
        if (yLength > xlength)
            return -1;
        else if (yLength == xlength)
            return 0;
        else if (yLength < xlength)
            return 1;
    }
    else if (i < minLength)
    {
        if (x[i] < y[i])
            return -1;
        else if (x[i] > y[i])
            return 1;
    }
    return 0;
}