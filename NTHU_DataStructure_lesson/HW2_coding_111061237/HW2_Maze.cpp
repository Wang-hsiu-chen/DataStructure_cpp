#include "HW2_Maze.h"

template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity)
{
    if (capacity < 1)
        throw "Stack capacity must be > 0";
    stack = new T[capacity];
    top = -1;
}

template <class T>
inline bool Stack<T>::IsEmpty() const { return top == -1; }

template <class T>
inline T &Stack<T>::Top() const
{
    if (IsEmpty())
        throw "Stack is empty";
    return stack[top];
}

template <class T>
void Stack<T>::Push(const T &item)
{
    if (top == capacity - 1)
    {
        ChangeSize1D(stack, capacity, 2 * capacity);
        capacity *= 2;
    }
    stack[++top] = item;
}

template <class T>
void Stack<T>::Pop()
{
    if (IsEmpty())
        throw "Stack is empty. Cannot delete.";
    stack[top--].~T();
}

template <class T>
void Stack<T>::ChangeSize1D(T *&a, const int oldSize, const int newSize)
{
    if (newSize < 0)
        throw "New length must be >= 0";

    T *temp = new T[newSize];
    int number = min(oldSize, newSize); // choose the smallest Size to store
    copy(a, a + number, temp);          // copy the old array into new
    delete[] a;                         // delete old array
    a = temp;
}

template <class T>
ostream &operator<<(ostream &os, Stack<T> &stack)
{
    int i;

    os << "total steps = " << stack.top + 2 << endl
       << endl;
    for (i = 0; i < stack.top + 1; i++)
    {
        os << "Step" << i + 1 << " : " << stack.stack[i] << endl;
    }
    os << "Step" << i + 1 << " : ";

    return os;
}

ostream &operator<<(ostream &os, Items &item)
{
    os << item.x << " " << item.y << " ";

    switch (item.direction)
    {
    case N:
        os << "N";
        break;
    case NE:
        os << "NE";
        break;
    case E:
        os << "E";
        break;
    case SE:
        os << "SE";
        break;
    case S:
        os << "S";
        break;
    case SW:
        os << "SW";
        break;
    case W:
        os << "W";
        break;
    case NW:
        os << "NW";
        break;
    default:
        break;
    };

    return os;
}

void Path(const int m, const int p)
{
    visited[1][1] = 1;
    Stack<Items> stack(m * p);
    Items temp = {1, 1, E};
    stack.Push(temp);

    while (!stack.IsEmpty())
    {
        temp = stack.Top();
        stack.Pop();
        int i = temp.x;
        int j = temp.y;
        int d = temp.direction;
        while (d < 8)
        {
            int g = i + moveDirection[d].di;
            int h = j + moveDirection[d].dj;
            if ((g == m) && (h == p))
            {
                cout << stack;
                cout << i << " " << j << " ";
                switch (d)
                {
                case N:
                    cout << "N";
                    break;
                case NE:
                    cout << "NE";
                    break;
                case E:
                    cout << "E";
                    break;
                case SE:
                    cout << "SE";
                    break;
                case S:
                    cout << "S";
                    break;
                case SW:
                    cout << "SW";
                    break;
                case W:
                    cout << "W";
                    break;
                case NW:
                    cout << "NW";
                    break;
                default:
                    break;
                };
                return;
            }
            if ((!map[g][h]) && (!visited[g][h]))
            {
                visited[g][h] = 1;
                temp.x = i;
                temp.y = j;
                temp.direction = d; // try new direction
                stack.Push(temp);
                i = g;
                j = h;
                d = N;
            }
            else
                d++;
        }
    }
    cout << "No path" << endl;
}
