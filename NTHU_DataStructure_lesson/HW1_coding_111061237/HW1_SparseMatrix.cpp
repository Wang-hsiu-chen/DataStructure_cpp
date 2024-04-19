#include "HW1_SparseMatrix.h"
SparseMatrix::SparseMatrix(int r, int c, int t)
{
    rows = r;
    cols = c;
    capacity = rows * cols;
    if (t > capacity)
        throw "too many terms";
    terms = t;
    smArray = new MatrixTerm[terms];
}
void SparseMatrix::setRowColValue(int i, int r, int c, int v)
{
    smArray[i].row = r;
    smArray[i].col = c;
    smArray[i].value = v;
    return;
}
int SparseMatrix::getRowColValue(int i, char item)
{
    switch (item)
    {
    case 'r':
        return smArray[i].row;
        break;
    case 'c':
        return smArray[i].col;
        break;
    case 'v':
        return smArray[i].value;
        break;
    default:
        break;
    }
    return 0;
}
void SparseMatrix::ChangeSize1D(const int newSize)
{ // change the array size to newSize
    if (newSize < terms)
        throw "New size must be >= number of terms";
    MatrixTerm *temp = new MatrixTerm[newSize];
    // new array
    copy(smArray, smArray + terms, temp);
    delete[] smArray;
    smArray = temp;
    // make smArray point to the newly created array
    terms = newSize;
}
void SparseMatrix::StoreSum(const int sum, const int r, const int c)
{
    if (sum != 0)
    {
        if (terms == capacity)
            ChangeSize1D(2 * capacity);
        smArray[terms].row = r;
        smArray[terms].col = c;
        smArray[terms++].value = sum;
    }
}
SparseMatrix SparseMatrix::Transpose()
{
    SparseMatrix b(cols, rows, terms);
    if (terms > 0)
    {
        int currentB = 0;
        for (int c = 0; c < cols; c++)
            for (int i = 0; i < terms; i++)
                if (smArray[i].col == c)
                {
                    b.smArray[currentB].row = smArray[i].col;
                    b.smArray[currentB].col = smArray[i].row;
                    b.smArray[currentB].value = smArray[i].value;
                    currentB++;
                }
    } // end of if(terms >0)
    *this = b;
    return *this;
}
SparseMatrix SparseMatrix::FastTranspose()
{
    SparseMatrix b(cols, rows, terms);
    if (terms > 0)
    {
        int *rowSize = new int[cols];
        int *rowStart = new int[cols];
        // calculate the row size of the new matrix
        fill(rowSize, rowSize + cols, 0);
        for (int i = 0; i < terms; i++)
            rowSize[smArray[i].col]++;
        // calculate the starting array index of each row
        // of the new matrix
        rowStart[0] = 0;
        for (int i = 1; i < cols; i++)
            rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
        for (int i = 0; i < terms; i++)
        {
            int j = rowStart[smArray[i].col];
            b.smArray[j].row = smArray[i].col;
            b.smArray[j].col = smArray[i].row;
            b.smArray[j].value = smArray[i].value;
            rowStart[smArray[i].col]++;
        } // end of for
        delete[] rowSize;
        delete[] rowStart;
    } // end of if
    *this = b;
    return *this;
}
SparseMatrix SparseMatrix::Multiply(SparseMatrix b)
{
    if (cols != b.rows) // error handling
        throw "Incompatible matrices";
    SparseMatrix bXpose = b.FastTranspose(); // transpose b
    SparseMatrix d(rows, b.cols, 0);         // create the output matrix d
    int currRowIndex = 0,
        currRowBegin = 0,
        currRowA = smArray[0].row;
    // introduce dummy terms for handling boundary condition
    if (terms == capacity)
        ChangeSize1D(terms + 1);
    // introduce dummy terms for handling boundary condition
    bXpose.ChangeSize1D(bXpose.terms + 1);
    smArray[terms].row = rows;
    bXpose.smArray[b.terms].row = b.cols;
    bXpose.smArray[b.terms].col = -1;
    int sum = 0;
    while (currRowIndex < terms)
    { // check currRowA is valid
        int currColB = bXpose.smArray[0].row;
        int currColIndex = 0;
        while (currColIndex <= b.terms)
        { // process B matrix term by term
            if (smArray[currRowIndex].row != currRowA)
            {                                        // row end
                d.StoreSum(sum, currRowA, currColB); // store the sum
                sum = 0;                             // reset the sum
                currRowIndex = currRowBegin;         // rewind the row
                while (bXpose.smArray[currColIndex].row == currColB)
                    currColIndex++;                          // skip terms in the curr col
                currColB = bXpose.smArray[currColIndex].row; // next col
            }
            else if (bXpose.smArray[currColIndex].row != currColB)
            {
                // col end
                d.StoreSum(sum, currRowA, currColB);         // output the sum
                sum = 0;                                     // reset the sum
                currRowIndex = currRowBegin;                 // rewind the row
                currColB = bXpose.smArray[currColIndex].row; // next col
            }
            else
            {
                if (smArray[currRowIndex].col <
                    bXpose.smArray[currColIndex].col)
                    currRowIndex++;
                else if (smArray[currRowIndex].col ==
                         bXpose.smArray[currColIndex].col)
                {
                    sum += smArray[currRowIndex].value *
                           bXpose.smArray[currColIndex].value;
                    currRowIndex++;
                    currColIndex++;
                }
                else
                    currColIndex++;
            } // end of if-elseif-else
        }     // end of the inner while (currColIndex <= b.terms)
        while (smArray[currRowIndex].row == currRowA)
            currRowIndex++;                   // skip terms in the curr row
        currRowBegin = currRowIndex;          // next row
        currRowA = smArray[currRowIndex].row; // next row
    }                                         // end of the outer while (currRowIndex < terms)
    return d;
}
SparseMatrix SparseMatrix::Add(SparseMatrix b)
{
    if (cols != b.cols || rows != b.rows)
        throw "Incompatible matrices";
    int count = 0;
    SparseMatrix c(rows, cols, terms);
    copy(smArray, smArray + terms, c.smArray);
    for (int i = 0; i < b.terms; i++)
    {
        for (int j = 0; j < terms; j++)
        {
            if (smArray[i].col != b.smArray[j].col || smArray[i].row != b.smArray[j].row)
                count++;
            else if (c.smArray[j].col == b.smArray[i].col && c.smArray[j].row == b.smArray[i].row && c.smArray[j].value + b.smArray[i].value != 0)
                c.smArray[j].value += b.smArray[i].value;
            else if (c.smArray[j].value + b.smArray[i].value == 0)
            {
                for (int k = j + 1; k < c.terms; k++)
                    c.smArray[k - 1] = c.smArray[k];
                c.terms--;
            }
        }
        if (count == terms)
        {
            c.ChangeSize1D(c.terms + 1);
            c.smArray[c.terms - 1].row = b.smArray[i].row;
            c.smArray[c.terms - 1].col = b.smArray[i].col;
            c.smArray[c.terms - 1].value = b.smArray[i].value;
        }
        count = 0;
    }
    return c;
}
istream &operator>>(istream &ins, SparseMatrix &arg)
{
    int row, col, value;
    for (int i = 0; i < arg.terms; i++)
    {
        ins >> row >> col >> value;
        if (row >= arg.rows || col >= arg.cols)
            throw "error";
        arg.setRowColValue(i, row, col, value);
    }
    return ins;
}
ostream &operator<<(ostream &outs, SparseMatrix &arg)
{
    int **arrayOut = new int *[arg.rows];
    for (int i = 0; i < arg.rows; ++i)
        arrayOut[i] = new int[arg.cols];
    for (int i = 0; i < arg.cols * arg.rows; i++)
        arrayOut[i / arg.cols][i % arg.cols] = 0;
    for (int i = 0; i < arg.terms; i++)
        arrayOut[arg.getRowColValue(i, 'r')][arg.getRowColValue(i, 'c')] = arg.getRowColValue(i, 'v');
    for (int i = 0; i < arg.rows; i++)
    {
        for (int j = 0; j < arg.cols; j++)
            outs << arrayOut[i][j] << ' ';
        outs << endl;
    }
    delete[] arrayOut;
    return outs;
}