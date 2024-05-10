#include <iostream>
using namespace std;

struct Term
{
    int coef;
    int exp;
    Term Set(int c, int e)
    {
        coef = c;
        exp = e;
        return *this;
    }
};
class Polynomial
{
public:
    Istream &operator>>(istream &is, Polynomial &x);                    // Read in an input polynomial and convert it to its circular list representation using a header node.
    Ostream &operator<<(ostream &os, Polynomial &x);                    // Convert x from its linked list representation to its external representation and output it.
    Polynomila::Polynomial(const Polynomial &a);                        // copy constructor
    Const Polynomila &Polynomial::operator=(const Polynomial &a) const; // assign polynomial a to *this.
    Polynomial::~Polynomial();                                          // desctructor, return all nodes to available-space list
    Polynomial operator+(const Polynomial &b) const;                    //  Create and return the polynomial *this + b
    Polynomial operator-(const Polynomial &b) const;                    //  Create and return the polynomial *this – b
    Polynomial operator*(const Polynomial &b) const;                    //  Create and return the polynomial *this * b
    double Polynomial::Evaluate(double x) const;                        // Evaluate the polynomial *this and return the result.

private:
    Chain<Term> poly;
};