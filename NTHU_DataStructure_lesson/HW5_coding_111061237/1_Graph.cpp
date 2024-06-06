#include "1_Graph.h"

template <class T>
Chain<T>::Chain() { first = NULL; }
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
void Chain<T>::InsertBack(const T &e) {}
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

void LinkedGraph::InitEdges()
{
    for (int i = 0; i < vertices; i++)
    {
        cout << "vertex " << i << endl;
        // while ()
    }

} // print out each vertice // input the vertices that it adjacents with
void LinkedGraph::BFS(int v)
{
    // visited = new bool[n];
    fill(visited, visited + vertices, false);
    visited[v] = true;
    Queue<int> q;
    q.Push(v);
    while (!q.IsEmpty())
    {
        v = q.Front();
        q.Pop();
        // ChainNode *temp = adjLists[v].first;
        // while (temp != NULL)
        // {
        //     if (!visited[temp.data])
        //     {
        //         q.Push(temp.data);
        //         visited[temp.data] = true;
        //     }
        //     temp = temp->link;
        // }
    } // end of while loop
    // delete[] visited;
}
void LinkedGraph::DFS(int v)
{

    visited[v] = true;
    cout << v << ", ";
    ChainIterator<int> li(adjLists[v]);
    if (adjLists[v].IsEmpty())
        return;
    // int w = adjLists[v].first->data;
    int w = *li.Begin();
    // ChainNode<T> *temp = adjLists[v].first;
    while (1)
    {
        if (!visited[w])
            DFS(w);
        // if (temp->link != NULL)
        // {
        //     temp = temp->link;
        //     w = temp->data;
        // }
        if (li->link != NULL)
            w = *li++;
        else
            return;
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
