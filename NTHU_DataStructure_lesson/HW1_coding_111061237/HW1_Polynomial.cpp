#include "HW1_Polynomial.h"
Polynomial::Polynomial()
{
    capacity = 5;
    terms = 0;
    termArray = new Term[capacity];
    termArray[terms].coef = 0;
    termArray[terms].exp = 0;
};
Polynomial::~Polynomial()
{
    // delete[] termArray;
}
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
float Polynomial::Eval(float f)
{
    int leadExp = LeadExp();
    float y = Coef(leadExp);
    for (int i = 1; i < leadExp; i++)
        y = f * y + Coef(leadExp - i);
    return y;
}
Polynomial Polynomial::Add(Polynomial b)
{
    Polynomial c; // c.terms = 0
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
    delete[] termArray;
    termArray = c.termArray;
    return *this;
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
    delete[] termArray;
    termArray = c.termArray;
    return *this;
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
        d = d.Add(c);
    }
    delete[] termArray;
    termArray = d.termArray;
    return *this;
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
        if (arg.Coef(i) > 0)
            outs << " + " << arg.Coef(i) << 'x' << i;
        else if (arg.Coef(i) < 0)
            outs << " - " << abs(arg.Coef(i)) << 'x' << i;
    }
    return outs;
}
