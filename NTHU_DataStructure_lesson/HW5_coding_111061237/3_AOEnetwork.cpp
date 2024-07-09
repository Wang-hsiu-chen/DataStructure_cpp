#include "3_AOEnetwork.h"
#define MAX 100000
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
void LinkedGraph::ChangeToMetrix()
{
    for (int i = 0; i < vertices; i++)
    {
        matrix[i] = new int[vertices];
        for (int j = 0; j < vertices; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < vertices; i++)
    {
        adjLists[i].ResetPointer();
        while (adjLists[i].pointer != nullptr)
        {
            matrix[i][adjLists[i].pointer->data] = adjLists[i].pointer->weight;
            adjLists[i].pointer = adjLists[i].Next();
        }
    }
}
void LinkedGraph::TopologicalOrder()
{
    std::stack<int> mystack;
    int *indegreeNum = new int[vertices];
    // A stack holds 0-indegree vertices
    // Any container is good for this algorithm
    for (int i = 0; i < vertices; i++)
    {
        bool noInDegree = true;
        for (int j = 0; j < vertices; j++)
            if (matrix[j][i] != 0)
            {
                noInDegree = false;
                indegreeNum[i]++;
            }
        if (noInDegree)
            mystack.push(i);
    }
    for (int i = 0; i < vertices; i++)
    {
        if (mystack.empty())
            throw "Network has a cycle.";
        topoSort[i] = mystack.top();
        mystack.pop();
        cout << topoSort[i] << endl;
        while (adjLists[topoSort[i]].pointer != nullptr)
        {
            indegreeNum[adjLists[topoSort[i]].pointer->data]--;
            if (indegreeNum[adjLists[topoSort[i]].pointer->data] == 0)
                mystack.push(adjLists[topoSort[i]].pointer->data);
            adjLists[topoSort[i]].pointer = adjLists[topoSort[i]].Next();
        }
    }
}
void LinkedGraph::LongestPath()
{
    for (int i = 0; i < vertices; i++)
        dist[i] = matrix[0][i];
    for (int k = 2; k <= vertices - 1; k++) // dist2 ~ dist(n-1)
        for (int u = 0; u < vertices; u++)
            if (u != 0)
                for (int i = 0; i < vertices; i++)
                    if (dist[u] < dist[i] + matrix[i][u])
                        dist[u] = dist[i] + matrix[i][u];
}
void LinkedGraph::TimeOfEvents()
{
    LongestPath();
    TopologicalOrder();
    int *earliestE = new int[vertices];
    int *latestE = new int[vertices];
    for (int i = 0; i < vertices; i++)
    {
        earliestE[i] = dist[i];
        latestE[i] = MAX;
    }
    latestE[vertices - 1] = earliestE[vertices - 1];
    for (int i = vertices - 1; i >= 0; i--)
    {
        int u = topoSort[i];
        while (adjLists[u].pointer != nullptr)
        {
            int v = adjLists[u].pointer->data;
            int weight = adjLists[u].pointer->weight;
            latestE[u] = std::min(latestE[u], latestE[v] - weight);
            adjLists[u].pointer = adjLists[u].Next();
        }
    }
    cout << "\neet: ";
    for (int i = 0; i < vertices; i++)
        cout << earliestE[i] << " ";
    cout << "\nlet: ";
    for (int i = 0; i < vertices; i++)
        cout << latestE[i] << " ";
}
void LinkedGraph::CountEdges()
{
    for (int i = 0; i < vertices; i++)
        while (adjLists[i].pointer != nullptr)
        {
            edges++;
            adjLists[i].pointer = adjLists[i].Next();
        }
}
void LinkedGraph::TimeOfActivies()
{
    LongestPath();
    CountEdges();
    int *earliestA = new int[edges];
    int *latestA = new int[edges];
    int j = 0;
    for (int i = 0; i < vertices; i++)
        while (adjLists[i].pointer != nullptr)
        {
            earliestA[j] = dist[i];
            latestA[j] = latestE[adjLists[i].pointer->data] - adjLists[i].pointer->weight;
            adjLists[i].pointer = adjLists[i].Next();
            j++;
        }
    cout << "\neat: ";
    for (int i = 0; i < edges; i++)
        cout << earliestA[i] << " ";
    cout << "\nlat: ";
    for (int i = 0; i < edges; i++)
        cout << latestA[i] << " ";
}
void LinkedGraph::ActivityTimeMatrix()
{
}
void LinkedGraph::CriticalNetwork()
{
}
void LinkedGraph::Setup1()
{
    adjLists[0].InsertBack(1, 6);
    adjLists[0].InsertBack(2, 4);
    adjLists[0].InsertBack(3, 5);
    adjLists[1].InsertBack(4, 1);
    adjLists[2].InsertBack(4, 1);
    adjLists[3].InsertBack(5, 2);
    adjLists[4].InsertBack(6, 9);
    adjLists[4].InsertBack(7, 7);
    adjLists[5].InsertBack(7, 4);
    adjLists[6].InsertBack(8, 2);
    adjLists[7].InsertBack(8, 4);
    adjLists[8].InsertBack(8, 0);
}