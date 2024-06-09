#include "2_ShortestPaths.cpp"

int main()
{
    LinkedGraph g1(7), g2(7);
    g1.InitEdges();
    g1.Dijkstra(4);
    g2.InitEdges();
    g2.BellmanFord(0);
    g2.Floyd();
}
// test input for Dijkstra
// 1 28, 5 10.
// 0 28, 2 16, 6 14.
// 1 16, 3 12.
// 2 12, 4 22, 6 18.
// 3 22, 5 25, 6 24.
// 0 10, 4 15.
// 1 14, 3 18, 4 24.

// test input for Bellman-Ford & Floyd
// 1 6, 2 5, 3 5.
// 4 -1.
// 1 -2, 4 1.
// 2 -2, 5 -1.
// 6 3.
// 6 3.
//.