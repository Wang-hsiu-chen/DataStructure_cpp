#include "HW3_LinkedPolynomial.cpp"

int main()
{
     cout << "\nPolynomial: \n";
     cout << "eg. 2x3 + 3x2 + 4x1 + 5x0\n    1x3 - 1x2 + 1x1 - 1x0 " << endl;
     Polynomial Pa(Pa), Pb(Pb), Pc(Pc);
     cin >> Pa;
     cin >> Pb;
     cout << "Pa: " << Pa << endl;
     cout << "Pb: " << Pb << endl;
     cout << "Pa eval(1): " << Pa.Evaluate(1) << endl;
     cout << "Pa eval(2): " << Pa.Evaluate(2) << endl;
     Pa + Pb;
     cout << "Pa + Pb: " << Pa << endl;
     Pa - Pb;
     cout << "Pa - Pb: " << Pa << endl;
     Pa *Pb;
     cout << "Pa * Pb: " << Pa << endl;
     return 0;
}