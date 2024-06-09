#include "2_ShortestPaths.h"

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
void Chain<T>::InsertBack(const T &v, const T &e)
{
    ChainNode<T> *newNode = new ChainNode<T>;
    newNode->data = v;
    newNode->weight = e;
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
T &Chain<T>::GetWeight(int index)
{
    ChainNode<T> *desiredNode;
    int currentIndex = 0;
    desiredNode = first; // gets you to first node
    while (currentIndex < index)
    {
        if (desiredNode == NULL)
            throw "index doesn't exist";
        desiredNode = desiredNode->link;
        currentIndex++;
    }
    return desiredNode->weight;
}
template <class T>
int Chain<T>::IndexOf(const T &e) const
{
    // search the chain for e
    ChainNode<T> *currentNode = first;
    int index = 0; // index of currentNode
    while (currentNode != NULL && currentNode->data != e)
    { // move to next node
        currentNode = currentNode->link;
        index++;
    }
    // make sure we found matching element
    if (currentNode == NULL)
        return -1;
    else
        return index;
}
template <class T>
bool Chain<T>::FindElement(T &e)
{
    ChainNode<T> *pointer = first;
    for (int i = 0; i < Size(); i++)
    {
        if (pointer->data == e)
            return true;
        pointer = pointer->link;
    }
    return false;
}
template <class T>
T &Chain<T>::Set(int index, const T &e) {}
template <class T>
ChainNode<T> *Chain<T>::Next()
{
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
        cout << "\nvertex " << i << endl;
        int inputV, inputE;
        char temp;
        int j = -1;
        do
        {
            j++;
            cin >> inputV >> inputE >> temp;
            adjLists[i].InsertBack(inputV, inputE);
        } while (temp != '.');
    }
} // print out each vertice // input the vertices that it adjacents with

void LinkedGraph::Dijkstra(int v)
{
    int *dijkstraTree = new int[vertices + 1];
    dijkstraTree[0] = 0;
    pair<int, int> path[vertices];
    for (int i = 0; i < vertices; i++)
        path[i].first = path[i].second = -1;
    fill(visited, visited + vertices, false);

    visited[v] = true;
    dijkstraTree[0]++;
    dijkstraTree[dijkstraTree[0]] = v;
    path[v].first = 0;
    path[v].second = -1;

    while (dijkstraTree[0] < vertices)
    {
        int newPathPoint = -1;
        for (int i = 0; i < vertices; i++)
        {
            if (!visited[i])
            {
                for (int j = 1; j <= dijkstraTree[0]; j++)
                {
                    int k = dijkstraTree[j];
                    adjLists[k].ResetPointer();
                    while (adjLists[k].pointer != nullptr)
                    {
                        if (adjLists[k].pointer->data == i && (adjLists[k].pointer->weight + path[k].first < path[i].first || path[i].first == -1))
                        {
                            path[i].first = adjLists[k].pointer->weight + path[k].first;
                            path[i].second = k;
                            break;
                        }
                        adjLists[k].pointer = adjLists[k].Next();
                    }
                    // find if there is i in the adjlist of k
                    // if yes, compare edge(k,i)+path[k] with path[i].first
                    // if edge(k,i)+path[k] is shorter, update path[i].first with edge(k,i)+path[k] and path[i].second with k
                }
                if ((path[newPathPoint].first > path[i].first || path[newPathPoint].first == -1) && path[i].first != -1)
                    newPathPoint = i;
            }
        }
        if (newPathPoint != -1)
        {
            visited[newPathPoint] = true;
            cout << newPathPoint << " ";
            dijkstraTree[0]++;
            dijkstraTree[dijkstraTree[0]] = newPathPoint;
        }
    }
}
void LinkedGraph::BellmanFord(int v)
{
    int **matrix = new int *[vertices];
    for (int i = 0; i < vertices; i++)
    {
        matrix[i] = new int[vertices];
        for (int j = 0; j < vertices; j++)
        {
            matrix[i][j] = 100000;
        }
    }
    for (int i = 0; i < vertices; i++)
    {
        matrix[i][i] = 0;
        adjLists[i].ResetPointer();
        while (adjLists[i].pointer != nullptr)
        {
            matrix[i][adjLists[i].pointer->data] = adjLists[i].pointer->weight;
            adjLists[i].pointer = adjLists[i].Next();
        }
    }
    // n is the number of vertices
    // in-place update for dist[] is used
    int *dist = new int[vertices];
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = matrix[v][i];
    }
    for (int k = 2; k <= vertices - 1; k++) // dist2 ~ dist(n-1)
        for (int u = 0; u < vertices; u++)
            if (u != v)
                for (int i = 0; i < vertices; i++)
                    if (dist[u] > dist[i] + matrix[i][u])
                        dist[u] = dist[i] + matrix[i][u];
    for (int i = 0; i < vertices; i++)
        cout << dist[i] << " ";
}
void LinkedGraph::Floyd()
{
    int *dist = new int[vertices * vertices];
    int **matrix = new int *[vertices];
    for (int i = 0; i < vertices; i++)
    {
        matrix[i] = new int[vertices];
        for (int j = 0; j < vertices; j++)
        {
            matrix[i][j] = 100000;
        }
    }
    for (int i = 0; i < vertices; i++)
    {
        matrix[i][i] = 0;
        adjLists[i].ResetPointer();
        while (adjLists[i].pointer != nullptr)
        {
            matrix[i][adjLists[i].pointer->data] = adjLists[i].pointer->weight;
            adjLists[i].pointer = adjLists[i].Next();
        }
    }
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            dist[i * vertices + j] = matrix[i][j];
    for (int k = 0; k < vertices; k++)
        for (int i = 0; i < vertices; i++)
            for (int j = 0; j < vertices; j++)
                if (dist[i * vertices + j] > (dist[i * vertices + k] + dist[k * vertices + j]))
                    dist[i * vertices + j] = dist[i * vertices + k] + dist[k * vertices + j];
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
            cout << dist[i * vertices + j] << " ";
        cout << endl;
    }
}
