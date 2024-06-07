#include "1_Graph.cpp"

int main()
{
    LinkedGraph g1(9);
    g1.InitEdges();
    g1.DFS(2);
    g1.BFS(2);
    g1.DFS(0);
}