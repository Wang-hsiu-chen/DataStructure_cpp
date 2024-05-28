#include "HW4_ThreadsBinaryTree.cpp"

int main()
{
    ThreadsTree<char> tree;

    ThreadsTreeNode<char> *node1 = new ThreadsTreeNode<char>('A');
    ThreadsTreeNode<char> *node2 = new ThreadsTreeNode<char>('B');
    ThreadsTreeNode<char> *node3 = new ThreadsTreeNode<char>('C');
    ThreadsTreeNode<char> *node4 = new ThreadsTreeNode<char>('D');
    ThreadsTreeNode<char> *node5 = new ThreadsTreeNode<char>('E');
    ThreadsTreeNode<char> *node6 = new ThreadsTreeNode<char>('F');
    ThreadsTreeNode<char> *node7 = new ThreadsTreeNode<char>('G');
    ThreadsTreeNode<char> *node8 = new ThreadsTreeNode<char>('H');
    ThreadsTreeNode<char> *node9 = new ThreadsTreeNode<char>('J');

    tree.InsertLeft(tree.Root(), node1);
    tree.InsertLeft(node1, node2);
    tree.InsertRight(node1, node3);
    tree.InsertLeft(node2, node4);
    tree.InsertRight(node2, node5);
    tree.InsertLeft(node3, node6);
    tree.InsertRight(node3, node7);
    tree.InsertLeft(node4, node8);
    tree.InsertRight(node4, node9);
    tree.Preorder();
    cout << endl;
    tree.Inorder();
    cout << endl;
    tree.Postorder();
    cout << endl;
    tree.LeftSubtree().Inorder();
    cout << endl;
    tree.RightSubtree().Inorder();
    cout << endl;
    return 0;
}