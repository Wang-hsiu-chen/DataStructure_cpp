#include <iostream>
using namespace std;

typedef struct
{
    int di, dj;
} offsets;

offsets moveDirection[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
struct Items
{
    int x, y, direction;
};

enum directions
{
    N,
    NE,
    E,
    SE,
    S,
    SW,
    W,
    NW
};

typedef struct
{
    int x;
    int y;
    int direction;
} Item;

int map[14][17];     // for the whole map
int visited[14][17]; // to visited where it have been

template <class T>
class Stack
{
    template <class U>
    friend ostream &operator<<(ostream &os, Stack<U> &stack);

public:
    Stack(int stackCapacity = 10);
    bool IsEmpty() const;
    T &Top() const;
    void Push(const T &item);
    void Pop();
    void ChangeSize1D(T *&a, const int oldSize, const int newSize);

private:
    T *stack;
    int top;
    int capacity;
};