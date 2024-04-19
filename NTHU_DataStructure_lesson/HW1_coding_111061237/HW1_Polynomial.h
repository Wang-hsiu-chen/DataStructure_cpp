#include <iostream>

using namespace std;

class Polynomial;
class Term
{
    friend Polynomial;

private:
    float coef;
    int exp;
};
class Polynomial
{
    // p(x) = a0 x^e0 + … + an x^en
    // where ai is nonzero float and ei is non-negative int
public:
    Polynomial();
    // construct the polynomial p(x) = 0
    ~Polynomial();
    // destructor
    Polynomial Add(Polynomial poly);
    // return the sum of *this and poly
    Polynomial Subt(Polynomial poly);
    // return the difference of *this and poly
    Polynomial Mult(Polynomial poly);
    // return the product of *this and poly
    void NewTerm(const float theCoeff, const int theExp);
    float Eval(float f);
    // Evaluate the polynomial *this at f and return the results
    int operator!();
    // if *this is the zero polynomial, return 1; else return 0;
    float Coef(int e);
    // return the coefficient of e in *this
    int LeadExp();
    // return the largest exponent in *this
    friend ostream &operator<<(ostream &os, Polynomial &p);
    friend istream &operator>>(istream &is, Polynomial &p);

private:
    Term *termArray;
    int capacity;
    int terms;
};