#include "HW3_SpareMatrix.h"

Matrix::~Matrix()
{
    // Return all nodes to the av list, which is a chain linked
    // via the right field.
    // av is a static variable pointing to the first of the av list.
    if (!headnode)
        return; // no nodes to delete
    MatrixNode *x = headnode->right;
    headnode->right = av;
    av = headnode; // return headnode
    while (x != headnode)
    { // return nodes by rows
        MatrixNode *y = x->right;
        x->right = av;
        av = y;
        x = x->next; // next row
    }
    headnode = 0; // empty linked sparse matrix
}

istream &operator>>(istream &is, Matrix &matrix)
{ // Read in a maxtix and set up its linked representation
    Triple s;
    is >> s.row >> s.col >> s.value; // matrix dimensions
    int p = max(s.row, s.col);
    // set up header node for list of header nodes
    matrix.headnode = new MatrixNode(false, &s);
    if (p == 0)
    { // empty matrix
        matrix.headnode->right = matrix.headnode;
        return is; // for supporting "cin >> mi >> mj;"
    }
    // at least one row or column
    MatrixNode **head = new MatrixNode *[p];
    for (int i = 0; i < p; i++)
        head[i] = new MatrixNode(true, 0);
    int currentRow = 0;               // start from row 0
    MatrixNode *last = head[0];       // last node in current row
    for (int i = 0; i < s.value; i++) // input triples
    {
        Triple t;
        is >> t.row >> t.col >> t.value;
        if (t.row > currentRow)
        {                                   // end of current row
            last->right = head[currentRow]; // close current row
            currentRow = t.row;
            last = head[currentRow];
        } // end of if
        last = last->right = new MatrixNode(false, &t);
        // link new node into row list, last point to new node
        head[t.col]->next = head[t.col]->next->down = last;
        // use head[]->next as col list last, link into column list
    } // end of for
    last->right = head[currentRow]; // close last row
    for (int i = 0; i < s.col; i++)
        head[i]->next->down = head[i]; // close all column lists
                                       // link the header nodes together
    for (int i = 0; i < p; i++)
        head[i]->next = head[i + 1];
    head[p - 1]->next = matrix.headnode;
    matrix.headnode->right = head[0];
    delete[] head;
    return is;
}
ostream &operator<<(ostream &is, Matrix &matrix)
{
    for (int i = 0; i < matrix.headnode->triple.col; i++)
        head[i]->next->down = head[i];
    for (int i = 0; i < p; i++)
        head[i]->next = head[i + 1];
}