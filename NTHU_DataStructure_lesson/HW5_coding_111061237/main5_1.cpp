#include "1_Graph.cpp"

int main()
{
    LinkedGraph g1(11), g2(8), g3(8);
    // g1.InitEdges();
    g2.Setup1();
    g3.Setup2();
    // BFS
    // g2.BFS(0);
    // g1.BFS(3);
    // g1.BFS(7);
    // DFS
    g2.DFS(0);
    // g1.DFS(3);
    // g1.DFS(7);
    // Components & DfnLow
    // g1.Components();
    // g1.DfnLow(3);
}
// input sample for g1
// 1 3.
// 0 2 4 5.
// 1 4.
// 0 5.
// 1 2 6 8.
// 1 3 6 8.
// 4 5.
// 8.
// 4 5 7.
// 10.
// 9.