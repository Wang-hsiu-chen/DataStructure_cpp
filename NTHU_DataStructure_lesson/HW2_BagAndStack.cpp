#include <iostream>
using namespace std;
class Bag
{
public:
    Bag(int bagCapacity = 10); // constructor
    ~Bag();                    // destructor
    int Size() const;          // return number of elements in bag
    bool IsEmpty() const;
    int Element() const;  // return an element that is in the bag
    void Push(const int); // add an integer into the bag
    void Pop();           // delete an integer in the bag
    void ChangeSize1D(const int newSize);

private:
    int *array;   // dynamic array for Bag
    int capacity; // capacity of array
    int top;      // array position of top element
};
Bag::Bag(int bagCapacity)
    : capacity(bagCapacity)
{
    if (capacity < 1)
        throw "Capacity must be > 0";
    array = new int[capacity]; // use array to implement
    top = -1;                  // empty
}
Bag::~Bag()
{
    delete[] array;
}
inline int Bag::Size() const
{
    return top + 1;
}
bool Bag::IsEmpty() const
{
    return (Size() == 0);
}
inline int Bag::Element() const
{
    if (IsEmpty())
        throw "Bag is empty";
    return array[0]; // always return 0th element
}
void Bag::Push(const int x)
{
    if (capacity == top + 1) // array is full
    {
        ChangeSize1D(array, capacity, 2 * capacity);
        capacity *= 2;
    }
    array[++top] = x;
}
void Bag::Pop()
{
    if (IsEmpty())
        throw "Bag is empty, cannot delete";
    int deletePos = top / 2; // always delete (top/2)th element
    copy(array + deletePos + 1, array + top + 1,
         array + deletePos);
    top--;
}
void Bag::ChangeSize1D(const int newSize)
{ // change the array size to newSize
    if (newSize < capacity)
        throw "New size must be >= number of terms";
    Bag *temp = new Bag[newSize];
    // new array
    copy(array, array + capacity, temp);
    delete[] array;
    array = temp;
    // make smArray point to the newly created array
    capacity = newSize;
}