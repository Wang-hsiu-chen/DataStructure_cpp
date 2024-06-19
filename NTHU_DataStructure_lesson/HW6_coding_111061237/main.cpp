#include "1_Sorting.cpp"
#include "2_Hashing.cpp"
#include <stdlib.h>
#include <time.h>

void RamdomInput(int *intList, char *charList, float *floatList, string *stringList, int numbers)
{
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
}
int main()
{
    Sorting<int> A;
    Sorting<char> B;
    Sorting<float> C;
    Sorting<string> D;
    int numbers = 5;
    int *intList = new int[numbers];
    char *charList = new char[numbers];
    float *floatList = new float[numbers];
    string *stringList = new string[numbers];

    srand(time(NULL));
    RamdomInput(intList, charList, floatList, stringList, numbers);
    for (int i = 0; i < numbers; i++)
        cout << intList[i] << " " << charList[i] << " " << floatList[i] << " " << stringList[i] << endl;

    A.InsertionSort(intList, numbers);
    B.InsertionSort(charList, numbers);
    C.InsertionSort(floatList, numbers);

    RamdomInput(intList, charList, floatList, stringList, numbers);
    A.QuickSort(intList, 0, numbers - 1);
    for (int i = 0; i < numbers; i++)
        cout << intList[i] << ", ";
    cout << endl;
    B.QuickSort(charList, 0, numbers - 1);
    for (int i = 0; i < numbers; i++)
        cout << charList[i] << ", ";
    cout << endl;
    C.QuickSort(floatList, 0, numbers - 1);
    for (int i = 0; i < numbers; i++)
        cout << floatList[i] << ", ";
    cout << endl;
}