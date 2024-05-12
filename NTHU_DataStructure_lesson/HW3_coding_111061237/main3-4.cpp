#include "HW3_SpareMatrix.cpp"

int main()
{
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

     return 0;
}