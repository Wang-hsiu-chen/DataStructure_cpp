#include <iostream>

using namespace std;

class SparseMatrix;
class MatrixTerm
{
    friend SparseMatrix;

private:
    int row, col, value; // a triple representing a term
};
class SparseMatrix
{ // 三元組，<列，行，值>，的集合，其中列與行為非負整數，
  // 並且它的組合是唯一的；值也是個整數。
public:
    SparseMatrix(int r, int c, int t);
    // constructor.
    // r is #row, c is #col, t is #non-zero terms
    void setRowColValue(int, int, int, int);
    void ChangeSize1D(int);
    void StoreSum(int, int, int);
    SparseMatrix Transpose();
    SparseMatrix FastTranspose();
    // 回傳將 *this中每個三元組的行與列交換後的SparseMatrix
    SparseMatrix Add(SparseMatrix b);
    // 如果 *this和b的維度一樣，那麼就把相對應的項給相加，
    // 亦即，具有相同列和行的值會被回傳；否則的話丟出例外。
    SparseMatrix Multiply(SparseMatrix b);
    // 如果*this中的行數和b中的列數一樣多的話，那麼回傳的矩陣d= *this和b
    // （依據d[i][j]=Σ(a[i][k]．b[k][j]，其中d[i][j]是第 (i, j) 個元素）相乘的結果。
    // k的範圍從0到*this的行數減1；如果不一樣多的話，那麼就丟出例外。
    // other needed functions
    friend ostream &operator<<(ostream &os, SparseMatrix &p);
    friend istream &operator>>(istream &is, SparseMatrix &p);

private:
    int rows, cols, terms, capacity;
    MatrixTerm *smArray;
};
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
    capacity = newSize;
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
                    b.smArray[currentB].row = c;
                    b.smArray[currentB].col = smArray[i].row;
                    b.smArray[currentB].value =
                        smArray[i].value;
                    currentB++;
                }
    } // end of if(terms >0)
    return b;
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
    return b;
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

istream &operator>>(istream &ins, SparseMatrix &arg)
{
    int row, col, value;
    for (int i = 0; i < arg.terms; i++)
    {
        ins >> row >> col >> value;
        arg.setRowColValue(i, row, col, value);
    }
    return ins;
}
int main()
{
    SparseMatrix a(4, 3, 4), b(4, 3, 5), c(3, 3, 4);
    cin >> a >> b >> c;
    /*
    use >> to build sm object a(4x3, 4 terms), b(4x3, 5 terms), c(3x3, 4 terms)
    demo  <<
    demo  << results of Transpose, Fast Transpose, Add, Mul
    */
    return 0;
}