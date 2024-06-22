#include "1_Sorting.cpp"
#include "2_Hashing.cpp"
#include <stdlib.h>
#include <time.h>

void RamdomInput(int *intList, char *charList, float *floatList, string *stringList, int numbers)
{
    for (int i = 0; i < numbers; i++)
        stringList[i] = "";
    for (int i = 0; i < numbers; i++)
    {
        intList[i] = rand() % 100;
        char correspondingChar = 'a' + (rand() % 26);
        charList[i] = correspondingChar;
        floatList[i] = rand() % 100 + (rand() % 100) / 100.0;
        for (int j = 0; j < 4; j++)
        {
            char correspondingChar = 'a' + (rand() % 26);
            stringList[i] += correspondingChar;
        }
    }
    cout << "<<unsort lists>>" << endl;
    for (int i = 0; i < numbers; i++)
        cout << intList[i] << ", ";
    cout << endl;
    for (int i = 0; i < numbers; i++)
        cout << charList[i] << ", ";
    cout << endl;
    for (int i = 0; i < numbers; i++)
        cout << floatList[i] << ", ";
    cout << endl;
    for (int i = 0; i < numbers; i++)
        cout << stringList[i] << ", ";
    cout << endl;
}
int main()
{
    Sorting<int> A;
    Sorting<char> B;
    Sorting<float> C;
    Sorting<string> D;
    int numbers = 20;
    int *intList = new int[numbers];
    char *charList = new char[numbers];
    float *floatList = new float[numbers];
    string *stringList = new string[numbers];
    srand(time(NULL));

    cout << "    Sorting" << endl;
    RamdomInput(intList, charList, floatList, stringList, numbers);
    cout << "  <<Insertion Sort>>" << endl;
    A.InsertionSort(intList, numbers);
    B.InsertionSort(charList, numbers);
    C.InsertionSort(floatList, numbers);
    D.InsertionSort(stringList, numbers);

    cout << endl;
    RamdomInput(intList, charList, floatList, stringList, numbers);
    cout << "  <<Quick Sort>>" << endl;
    A.QuickSort(intList, 0, numbers - 1);
    B.QuickSort(charList, 0, numbers - 1);
    C.QuickSort(floatList, 0, numbers - 1);
    D.QuickSort(stringList, 0, numbers - 1);
    for (int i = 0; i < numbers; i++)
        cout << intList[i] << ", ";
    cout << endl;
    for (int i = 0; i < numbers; i++)
        cout << charList[i] << ", ";
    cout << endl;
    for (int i = 0; i < numbers; i++)
        cout << floatList[i] << ", ";
    cout << endl;
    for (int i = 0; i < numbers; i++)
        cout << stringList[i] << ", ";

    cout << endl;
    cout << endl;
    RamdomInput(intList, charList, floatList, stringList, numbers);
    cout << "  <<Merge Sort>>" << endl;
    A.MergeSort(intList, numbers);
    B.MergeSort(charList, numbers);
    C.MergeSort(floatList, numbers);

    cout << endl;
    RamdomInput(intList, charList, floatList, stringList, numbers);
    cout << "  <<Recursive Merge Sort>>" << endl;
    A.RecursiveMergeSort(intList, 0, numbers - 1);
    B.RecursiveMergeSort(charList, 0, numbers - 1);
    C.RecursiveMergeSort(floatList, 0, numbers - 1);
    D.RecursiveMergeSort(stringList, 0, numbers - 1);
    for (int i = 0; i < numbers; i++)
        cout << intList[i] << ", ";
    cout << endl;
    for (int i = 0; i < numbers; i++)
        cout << charList[i] << ", ";
    cout << endl;
    for (int i = 0; i < numbers; i++)
        cout << floatList[i] << ", ";
    cout << endl;
    for (int i = 0; i < numbers; i++)
        cout << stringList[i] << ", ";

    cout << endl;
    cout << endl;
    RamdomInput(intList, charList, floatList, stringList, numbers);
    cout << "  <<Heap Sort>>" << endl;
    A.HeapSort(intList, numbers);
    B.HeapSort(charList, numbers);
    C.HeapSort(floatList, numbers);
    D.HeapSort(stringList, numbers);
    for (int i = 0; i < numbers; i++)
        cout << intList[i] << ", ";
    cout << endl;
    for (int i = 0; i < numbers; i++)
        cout << charList[i] << ", ";
    cout << endl;
    for (int i = 0; i < numbers; i++)
        cout << floatList[i] << ", ";
    cout << endl;
    for (int i = 0; i < numbers; i++)
        cout << stringList[i] << ", ";
    cout << endl;

    LinearProbing<string> d1;
    Chaining<string> d2;
    const string keys[] = {"abc", "abcde", "b", "bye", "cool", "dit", "fox", "vivy", "yes", "hello"};

    cout << endl
         << "    Hashing" << endl
         << "  <<Insert keys>>" << endl;
    for (int i = 0; i < 10; i++)
    {
        d1.Insert(keys[i]);
        d2.Insert(keys[i]);
    }

    cout << "  <<get d1>>" << endl;
    for (int i = 0; i < 10; i++)
        cout << d1.Get(keys[i]) << ", ";
    cout << endl;
    cout << "find a key \"something\" not in d1: " << endl;
    cout << d1.Get("something") << endl;

    cout << "  <<get d2>>" << endl;
    for (int i = 0; i < 10; i++)
        cout << d2.Get(keys[i]) << ", ";
    cout << endl;
    cout << "find a key \"something\" not in d2" << endl;
    cout << d2.Get("something") << endl;

    return 0;
}