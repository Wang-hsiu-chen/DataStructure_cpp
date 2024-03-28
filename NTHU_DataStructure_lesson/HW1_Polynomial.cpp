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
    Polynomial Add(Polynomial *poly);
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
Polynomial::Polynomial()
{
    capacity = 5;
    terms = 0;
    termArray = new Term[capacity];
    termArray[terms].coef = 0;
    termArray[terms].exp = 0;
};
Polynomial::~Polynomial(){
    // delete[] termArray;
};
void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
    // Add a new term to the end of termArray
    if (theCoeff == 0)
        return;
    if (terms == capacity) // termArray (of c) is full
    {                      // double the capacity of termArray
        capacity *= 2;
        Term *temp = new Term[capacity];
        copy(termArray, termArray + terms, temp);
        delete[] termArray; // delete allocated old memory
        termArray = temp;
    }
    termArray[terms].coef = theCoeff;
    termArray[terms++].exp = theExp;
}
int Polynomial::operator!()
{
    return (terms == 0) ? 1 : 0;
}
float Polynomial::Coef(int e)
{
    for (int i = 0; i < terms; i++)
    {
        if (termArray[i].exp == e)
            return termArray[i].coef;
    }
    return 0;
}
int Polynomial::LeadExp()
{
    int leadExp = termArray[0].exp;
    if (terms <= 1)
        return leadExp;
    for (int i = 1; i < terms; i++)
    {
        if (termArray[i].exp > leadExp)
            leadExp = termArray[i].exp;
    }
    return leadExp;
}
Polynomial Polynomial::Add(Polynomial *p)
{
    Polynomial c; // c.terms = 0
    Polynomial b = *p;
    int aPos = 0, bPos = 0;
    while ((aPos < terms) && (bPos < b.terms))
    {
        if (termArray[aPos].exp == b.termArray[bPos].exp)
        {
            float t = termArray[aPos].coef + b.termArray[bPos].coef;
            if (t)
                c.NewTerm(t, termArray[aPos].exp);
            aPos++;
            bPos++;
        }
        else if (termArray[aPos].exp < b.termArray[bPos].exp)
        {
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
            bPos++;
        }
        else
        {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
    }
    // add in remaining terms of *this
    for (; aPos < terms; aPos++) // output the remaining terms
        c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
    // add in remaining terms of b
    for (; bPos < b.terms; bPos++) // output remaining terms
        c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
    return c;
}
Polynomial Polynomial::Subt(Polynomial b)
{
    Polynomial c; // c.terms = 0
    int aPos = 0, bPos = 0;
    while ((aPos < terms) && (bPos < b.terms))
    {
        if (termArray[aPos].exp == b.termArray[bPos].exp)
        {
            float t = termArray[aPos].coef - b.termArray[bPos].coef;
            if (t)
                c.NewTerm(t, termArray[aPos].exp);
            aPos++;
            bPos++;
        }
        else if (termArray[aPos].exp < b.termArray[bPos].exp)
        {
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
            bPos++;
        }
        else
        {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
    }
    // add in remaining terms of *this
    for (; aPos < terms; aPos++) // output the remaining terms
        c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
    // add in remaining terms of b
    for (; bPos < b.terms; bPos++) // output remaining terms
        c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
    return c;
}
Polynomial Polynomial::Mult(Polynomial b)
{
    Polynomial d;
    int aPos = 0, bPos = 0;
    for (int i = 0; i < terms; i++)
    {
        Polynomial c;
        for (int j = 0; j < b.terms; j++)
        {
            float t = termArray[i].coef * b.termArray[j].coef;
            if (t)
                c.NewTerm(t, termArray[i].exp + b.termArray[j].exp);
        }
        d = d.Add(&c);
    }
    return d;
}
istream &operator>>(istream &ins, Polynomial &arg)
{
    char oper, plus = '+', lastPlus;
    double coefficient = 0;
    int exponential = 0;
    while (plus == '+' || plus == '-')
    {
        lastPlus = plus;
        ins >> coefficient >> oper >> exponential;
        if (lastPlus == '-')
            arg.NewTerm(-coefficient, exponential);
        else
            arg.NewTerm(coefficient, exponential);
        // cin.ignore(1024, '+');
        do
        {
            cin.get(plus);
        } while (plus == ' ');
    }
    return ins;
}
ostream &operator<<(ostream &outs, Polynomial &arg)
{
    outs << arg.Coef(arg.LeadExp()) << 'x' << arg.LeadExp();
    if (arg.LeadExp() == 0)
        return outs;
    for (int i = arg.LeadExp() - 1; i >= 0; i--)
    {
        if (arg.Coef(i) != 0)
            outs << " + " << arg.Coef(i) << 'x' << i;
    }
    return outs;
}

int main()
{
    Polynomial a, b, c;
    cin >> a;
    cin >> b;
    cout << a << endl;
    cout << b << endl;
    cout << a.LeadExp() << endl;
    c = a.Add(&b);
    cout << c << endl;
    c = a.Subt(b);
    cout << c << endl;
    c = a.Mult(b);
    cout << c << endl;

    /*
    construct polynomial objects a, b
    use >> to build polynomial object a = 2x3 + 3x2 + 4x + 5, b = x3 – x2 + x – 1
    demo  <<
    demo  << results of Add, Subt, Mul
    demo results of a.Exal(1), b.Eval(2), a.Coef(5), b.LeadExp
    */
}