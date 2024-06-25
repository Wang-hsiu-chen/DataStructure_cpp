#include "1_Graph.h"

template <class T>
Chain<T>::Chain() { first = last = pointer = NULL; }
template <class T>
Chain<T>::~Chain()
{
    if (!IsEmpty())
    {
        ChainNode<T> *temp = first;

        while (temp != nullptr)
        {
            ChainNode<T> *deleteNode = temp;
            temp = temp->link;
            delete deleteNode;
        }
    }
}
template <class T>
inline bool Chain<T>::IsEmpty() { return first == NULL; }
template <class T>
int Chain<T>::Size()
{
    int size = 0;
    ChainNode<T> *pointer = first;
    while (pointer != NULL)
    {
        size++;
        pointer = pointer->link;
    }
    return size;
}
template <class T>
void Chain<T>::InsertBack(const T &e)
{
    ChainNode<T> *newNode = new ChainNode<T>;
    newNode->data = e;
    newNode->link = NULL;
    if (first == NULL)
        first = last = pointer = newNode;
    else
        last->link = newNode;
    last = newNode;
}
template <class T>
void Chain<T>::DeleteBack() {}
template <class T>
inline const T &Chain<T>::Front() {}
template <class T>
inline const T &Chain<T>::Back() {}
template <class T>
T &Chain<T>::Get(int index) {}
template <class T>
T &Chain<T>::Set(int index, const T &e) {}
template <class T>
ChainNode<T> *Chain<T>::Next()
{
    // pointer = pointer->link;
    if (pointer->link != nullptr)
        return pointer->link;
    else
        return NULL;
}
template <class T>
void Chain<T>::ResetPointer()
{
    pointer = first;
}
void LinkedGraph::InitEdges()
{
    int ins;
    for (int i = 0; i < vertices; i++)
    {
        cout << "vertex " << i << endl;
        std::string input;
        int j = -1;
        do
        {
            j++;
            cin >> input[j];
        } while (input[j] != '.');
        for (int k = 0; k < j; k++)
        {
            if ((int)input[k] - 48 >= 0 && (int)input[k] - 48 < vertices)
                adjLists[i].InsertBack((int)input[k] - 48);
            cout << (int)input[k] - 48 << " ";
        }
    }
} // print out each vertice // input the vertices that it adjacents with
void LinkedGraph::BFS(int v)
{
    for (int i = 0; i < vertices; i++)
        adjLists[i].ResetPointer();
    // visited = new bool[n];
    fill(visited, visited + vertices, false);
    cout << v;
    visited[v] = true;
    Queue<int> q;
    q.Push(v);
    while (!q.IsEmpty())
    {
        v = q.Front();
        q.Pop();
        while (adjLists[v].pointer != NULL)
        {
            if (!visited[adjLists[v].pointer->data])
            {
                q.Push(adjLists[v].pointer->data);
                cout << ", " << adjLists[v].pointer->data;
                visited[adjLists[v].pointer->data] = true;
            }
            adjLists[v].pointer = adjLists[v].Next();
        }
    }
    cout << endl;
}
void LinkedGraph::DFS(int v)
{
    std::stack<int> mystack;
    for (int i = 0; i < vertices; i++)
        adjLists[i].ResetPointer();
    fill(visited, visited + vertices, false);
    visited[v] = true;
    cout << v;
    mystack.push(v);
    if (adjLists[v].IsEmpty())
        return;
    int nextV = adjLists[v].pointer->data;
    for (int i = 0; i < vertices; i++)
    {
        while (visited[nextV] && adjLists[v].pointer != nullptr)
        {
            nextV = adjLists[v].pointer->data;
            adjLists[v].pointer = adjLists[v].Next();
        }
        v = nextV;
        if (!visited[v])
        {
            cout << ", " << v;
            visited[v] = true;
            mystack.push(v);
        }
        else
        {
            mystack.pop();
            if (mystack.top() == 0)
                break;
            v = mystack.top();
        }
    }
    cout << endl;
}
void LinkedGraph::Components()
{
    // visited = new bool[n];
    fill(visited, visited + vertices, false);
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            DFS(i); // find the component containing i
            // OutputNewComponent(); // print current vertex
        }
    }
}
void LinkedGraph::DfnLow(const int v) // 從頂點x開始執行DFS
{
    num = 1; // num 是Graph的一個int資料成員
    fill(dfn, dfn + vertices, 0);
    fill(low, low + vertices, 0);
    DfnLow(vertices, -1); // 從頂點x開始
    delete[] dfn;
    delete[] low;
}

void LinkedGraph::DfnLow(const int u, const int v)
{
    // 由頂點u開始，一邊做深度優先搜尋一邊計算dfn及low。
    // 在製造出的生成樹中v是u的父節點（如果v存在的話）
    dfn[u] = low[u] = num++;
    while (adjLists[u].pointer != nullptr)
    { // 實際的程式碼使用疊代器
        int w = adjLists[u].pointer->data;
        adjLists[u].pointer = adjLists[u].Next();
        if (dfn[w] == 0)
        { // w是未拜訪過的頂點
            DfnLow(w, u);
            low[u] = min(low[u], low[w]);
        }
        else if (w != v)
            low[u] = min(low[u], dfn[w]); // back edge
    }
    for (int i = 0; i < vertices; i++)
        cout << "i: " << dfn[i] << " " << low[i] << endl;
} // Display the computed dfn[i] and low[i] of the graph and the articulation points found
void LinkedGraph::Setup1()
{
    adjLists[0].InsertBack(1);
    adjLists[0].InsertBack(2);
    adjLists[1].InsertBack(0);
    adjLists[1].InsertBack(3);
    adjLists[2].InsertBack(0);
    adjLists[2].InsertBack(3);
    adjLists[3].InsertBack(1);
    adjLists[3].InsertBack(2);
    adjLists[4].InsertBack(5);
    adjLists[5].InsertBack(4);
    adjLists[5].InsertBack(6);
    adjLists[6].InsertBack(5);
    adjLists[6].InsertBack(7);
    adjLists[7].InsertBack(6);
}
void LinkedGraph::Setup2()
{
    adjLists[0].InsertBack(1);
    adjLists[0].InsertBack(2);
    adjLists[1].InsertBack(0);
    adjLists[1].InsertBack(3);
    adjLists[1].InsertBack(4);
    adjLists[2].InsertBack(0);
    adjLists[2].InsertBack(5);
    adjLists[2].InsertBack(6);
    adjLists[3].InsertBack(1);
    adjLists[3].InsertBack(7);
    adjLists[4].InsertBack(1);
    adjLists[4].InsertBack(7);
    adjLists[5].InsertBack(2);
    adjLists[5].InsertBack(7);
    adjLists[6].InsertBack(2);
    adjLists[6].InsertBack(7);
    adjLists[7].InsertBack(3);
    adjLists[7].InsertBack(4);
    adjLists[7].InsertBack(5);
    adjLists[7].InsertBack(6);
}