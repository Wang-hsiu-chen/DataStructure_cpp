#include <iostream>
#include <fstream>

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
    // SparseMatrix(int r = 1, int c = 1, int t = 1) : rows(r), cols(c), terms(t), capacity(rows * cols), smArray(new MatrixTerm[terms]){};
    SparseMatrix(int r, int c, int t);
    // constructor.
    // r is #row, c is #col, t is #non-zero terms
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
    void setRowColValue(int, int, int, int);
    int getRowColValue(int, char);
    int rows, cols, terms, capacity;
    MatrixTerm *smArray;
};