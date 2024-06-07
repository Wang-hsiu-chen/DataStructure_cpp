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
        // while ()
        // {
        //     cin >> ins;
        //     adjLists[i].InsertBack(ins);
        // }
    }

} // print out each vertice // input the vertices that it adjacents with
void LinkedGraph::BFS(int v)
{
    adjLists[v].ResetPointer();
    // visited = new bool[n];
    fill(visited, visited + vertices, false);
    cout << v << ", ";
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
                cout << adjLists[v].pointer->data << ", ";
                visited[adjLists[v].pointer->data] = true;
            }
            adjLists[v].pointer = adjLists[v].Next();
        }
    }
}
void LinkedGraph::DFS(int v)
{
    adjLists[v].ResetPointer();
    visited[v] = true;
    cout << v << ", ";
    if (adjLists[v].IsEmpty())
        return;
    int w = adjLists[v].pointer->data;
    ChainNode<int> *temp = adjLists[v].pointer;
    // while (1)
    // {
    //     if (!visited[w])
    //         DFS(w);
    //     if (adjLists[v].Next() != NULL)
    //     {
    //         adjLists[v].pointer = adjLists[v].Next();
    //         w = adjLists[v].pointer->data;
    //     }
    //     else
    //         return;
    // }
    for (int i = 0; i < vertices; i++)
    {
        while (visited[w] && adjLists[v].Next() != nullptr)
        {
            adjLists[v].pointer = adjLists[v].Next();
            w = adjLists[v].pointer->data;
        }
        v = w;
        if (!visited[v])
            cout << v << ", ";
        visited[v] = true;
        w = adjLists[v].pointer->data;
    }
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
    delete[] visited;
}
void LinkedGraph::DfnLow()
{
} // Display the computed dfn[i] and low[i] of the graph and the articulation points found
