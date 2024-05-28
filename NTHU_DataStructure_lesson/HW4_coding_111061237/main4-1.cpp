#include "HW4_BinaryTree.cpp"

int main()
{
    Tree<char> Null;
    Tree<char> A(Null, 'A', Null);
    Tree<char> B(Null, 'B', Null);
    Tree<char> C(Null, 'C', Null);
    Tree<char> D(Null, 'D', Null);
    Tree<char> E(Null, 'E', Null);
    Tree<char> minus(A, '-', B);
    Tree<char> mult1(minus, '*', C);
    Tree<char> mult2(mult1, '*', D);
    Tree<char> Tree1(mult2, '+', E);

    cout << "Ex1 :" << endl;
    cout << "         +    " << endl;
    cout << "        / \\  " << endl;
    cout << "       *    E " << endl;
    cout << "      / \\    " << endl;
    cout << "     *   D    " << endl;
    cout << "    / \\      " << endl;
    cout << "   -   C      " << endl;
    cout << "  / \\        " << endl;
    cout << " A   B        " << endl
         << endl;

    if (Tree1.IsEmpty())
        cout << "The tree is empty" << endl;
    else
        cout << "The tree is not empty" << endl;
    cout << endl;
    cout << Tree1.RootData() << endl;
    Tree1.Preorder();
    cout << endl;
    Tree1.Inorder();
    cout << endl;
    Tree1.Postorder();
    cout << endl;
    Tree1.LeftSubtree().Inorder();
    cout << endl;
    Tree1.RightSubtree().Inorder();
    cout << endl;

    if (Tree1.LeftSubtree() == Tree1.RightSubtree())
        cout << "The left subtree is equal to the right subtree";
    else
        cout << "The left subtree is not equal to the right subtree";
    cout << endl
         << endl;

    Tree<char> H2(Null, 'H', Null);
    Tree<char> J2(Null, 'J', Null);
    Tree<char> E2(Null, 'E', Null);
    Tree<char> G2(Null, 'G', Null);
    Tree<char> F2(Null, 'F', Null);
    Tree<char> D2(H2, 'D', J2);
    Tree<char> B2(D2, 'B', E2);
    Tree<char> C2(F2, 'C', G2);
    Tree<char> Tree2(B2, 'A', C2);

    cout << "Ex2 : " << endl;
    cout << "          A       " << endl;
    cout << "         / \\     " << endl;
    cout << "        /   \\    " << endl;
    cout << "       B     C    " << endl;
    cout << "      / \\   / \\ " << endl;
    cout << "     D   E  F  G  " << endl;
    cout << "    / \\          " << endl;
    cout << "   H   J          " << endl
         << endl;

    if (Tree2.IsEmpty())
        cout << "The tree is empty" << endl;
    else
        cout << "The tree is not empty" << endl;
    cout << endl;
    cout << Tree2.RootData() << endl;
    Tree2.Preorder();
    cout << endl;
    Tree2.Inorder();
    cout << endl;
    Tree2.Postorder();
    cout << endl;
    Tree2.LeftSubtree().Inorder();
    cout << endl;
    Tree2.RightSubtree().Inorder();
    cout << endl;
    if (Tree2.LeftSubtree() == Tree2.RightSubtree())
        cout << "The left subtree is equal to the right subtree";
    else
        cout << "The left subtree is not equal to the right subtree";
    return 0;
}