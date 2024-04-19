#include <iostream>
#include <fstream>
#include "HW1_Polynomial.cpp"
#include "HW1_SparseMatrix.cpp"
#include "HW1_String.cpp"

using namespace std;

int main()
{

    cout << "\nPolynomial: \n";
    cout << "eg. 2x3 + 3x2 + 4x1 + 5x0\n    1x3 - 1x2 + 1x1 - 1x0 " << endl;
    Polynomial Pa, Pb, Pc;
    cin >> Pa;
    cin >> Pb;
    cout << "Pa: " << Pa << endl;
    cout << "Pb: " << Pb << endl;
    cout << "Pa leadexp: " << Pa.LeadExp() << endl;
    cout << "Pa eval(1): " << Pa.Eval(1) << endl;
    cout << "Pa eval(2): " << Pa.Eval(2) << endl;
    Pa.Add(Pb);
    cout << "Pa + Pb: " << Pa << endl;
    Pa.Subt(Pb);
    cout << "Pa - Pb: " << Pa << endl;
    Pa.Mult(Pb);
    cout << "Pa * Pb: " << Pa << endl;

    cout << "\nSparseMatrix: \n";
    SparseMatrix Ma(4, 3, 4), Mb(4, 3, 5), Mc(3, 4, 4), Md(0, 0, 0);
    ifstream fin2;
    fin2.open("input1_2.dat", ios::in);
    if (!fin2.good())
    {
        perror("input1_2.dat");
        exit(0);
    }
    fin2 >> Ma;
    fin2 >> Mb;
    fin2 >> Mc;
    fin2.close();
    Ma.Transpose();
    cout << "T: \n"
         << Ma;
    Ma.FastTranspose();
    cout << "FT: \n"
         << Ma;
    Md = Ma.Add(Mb);
    cout << "Ad: \n"
         << Md;
    Ma = Ma.Multiply(Mc);
    cout << "M: \n"
         << Ma;

    cout << "\nString: \n";
    char *a, *b, *c;
    String strTest(a, 8), strTest1(b, 4), strTest2(c, 0);
    cout << "input str0: ";
    cin >> strTest;
    cout << "input str1: ";
    cin >> strTest1;
    strTest2 = strTest.Substr(2, 4);
    cout << "Substr: " << strTest2 << endl;
    strTest.CharDelete('d');
    cout << "char delete: " << strTest << endl;
    strTest2 = strTest.Delete(2, 4);
    cout << "Delete: " << strTest << endl;
    strTest.Concat(strTest1);
    cout << "Concat: " << strTest << endl;
    cout << "Compare: " << strTest.Compare(strTest2) << endl;

    return 0;
}