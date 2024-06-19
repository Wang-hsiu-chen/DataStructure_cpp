#include "1_Sorting.cpp"
#include "2_Hashing.cpp"
#include <stdlib.h>
#include <time.h>

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
    for (int i = 0; i < numbers; i++)
        cout << intList[i] << " " << charList[i] << " " << floatList[i] << " " << stringList[i] << endl;

    A.InsertionSort(intList, numbers);
    B.InsertionSort(charList, numbers);
    C.InsertionSort(floatList, numbers);
}