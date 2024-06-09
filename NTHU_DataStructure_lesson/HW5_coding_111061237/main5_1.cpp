#include "1_Graph.cpp"

int main()
{
    LinkedGraph g1(9);
    g1.InitEdges();
    // g1.DFS(0);
    // g1.BFS(0);
    // g1.DFS(0);
    // BFS
    g1.BFS(0);
    g1.BFS(3);
    g1.BFS(7);
    // DFS
    g1.DFS(0);
    g1.DFS(3);
    g1.DFS(7);
    // Components & DfnLow
    g1.Components();
    g1.DfnLow(3);
}