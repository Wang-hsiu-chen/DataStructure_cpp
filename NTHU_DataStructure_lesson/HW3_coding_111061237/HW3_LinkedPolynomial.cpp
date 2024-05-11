#include "HW3_LinkedPolynomial.h"

Polynomial::Polynomial(const Polynomial &a)
{
    this->poly.begin() = NULL;
};
Polynomial::~Polynomial()
{
    Chain<Term>::ChainIterator ai = poly.begin();
    while (ai != NULL)
    {
        Term *temp = ai->link;
        delete &ai;
        if (temp != NULL)
            ai = temp->link;
    }
}
Polynomial Polynomial::operator+(Polynomial &b)
{
    Term temp;
    Chain<Term>::ChainIterator ai = poly.begin(), bi = b.poly.begin();
    Polynomial c(*this);
    while (ai != NULL && bi != NULL)
    {
        if (ai->exp == bi->exp)
        {
            int sum = ai->coef + bi->coef;
            if (sum)
                c.poly.InsertBack(temp.Set(sum, ai->exp));
            ai++;
            bi++;
        }
        else if (ai->exp < bi->exp)
        {
            c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
            bi++;
        }
        else
        {
            c.poly.InsertBack(temp.Set(ai->coef, ai->exp));
            ai++;
        }
    }
    while (ai != NULL)
    {
        c.poly.InsertBack(temp.Set(ai->coef, ai->exp));
        ai++;
    }
    while (bi != NULL)
    {
        c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
        bi++;
    }
    return c;
}
Polynomial Polynomial::operator-(Polynomial &b)
{
    Term temp;
    Chain<Term>::ChainIterator ai = poly.begin(), bi = b.poly.begin();
    Polynomial c(*this);
    while (ai != NULL && bi != NULL)
    {
        if (ai->exp == bi->exp)
        {
            int sum = ai->coef - bi->coef;
            if (sum)
                c.poly.InsertBack(temp.Set(sum, ai->exp));
            ai++;
            bi++;
        }
        else if (ai->exp < bi->exp)
        {
            c.poly.InsertBack(temp.Set(-1 * bi->coef, bi->exp));
            bi++;
        }
        else
        {
            c.poly.InsertBack(temp.Set(ai->coef, ai->exp));
            ai++;
        }
    }
    while (ai != NULL)
    {
        c.poly.InsertBack(temp.Set(ai->coef, ai->exp));
        ai++;
    }
    while (bi != NULL)
    {
        c.poly.InsertBack(temp.Set(-1 * bi->coef, bi->exp));
        bi++;
    }
    return c;
}
Polynomial Polynomial::operator*(Polynomial &b)
{
    Term temp;
    b.poly.begin();
    Chain<Term>::ChainIterator ai = poly.begin(), bi = b.poly.begin();
    Polynomial d(*this);
    for (int i = 0; i < poly.Size(); i++)
    {
        Polynomial c(*this);
        for (int j = 0; j < b.poly.Size(); j++)
        {
            int t = ai->coef * bi->coef;
            if (t)
                c.poly.InsertBack(temp.Set(t, ai->exp + bi->exp));
        }
        d = d + c;
    }
    return *this;
}

int Polynomial::Coef(int e)
{
    Chain<Term>::ChainIterator ai = poly.begin();
    for (int i = 0; i < poly.Size(); i++)
    {
        if (ai->exp == e)
            return ai->coef;
        ai++;
    }
    return 0;
}
int Polynomial::LeadExp()
{
    Chain<Term>::ChainIterator ai = poly.begin();
    int leadExp = ai->exp;
    if (poly.Size() <= 1)
        return leadExp;
    for (int i = 1; i < poly.Size(); i++)
    {
        if (ai->exp > leadExp)
            leadExp = ai->exp;
        ai++;
    }
    return leadExp;
}
double Polynomial::Evaluate(double x)
{
    Chain<Term>::ChainIterator ai = poly.begin();
    int leadExp = LeadExp();
    int y = Coef(leadExp);
    for (int i = 1; i < leadExp; i++)
        y = x * y + Coef(leadExp - i);
    return y;
}
istream &operator>>(istream &ins, Polynomial &arg)
{
    Term temp;
    char oper, plus = '+', lastPlus;
    int coefficient = 0;
    int exponential = 0;
    while (plus == '+' || plus == '-')
    {
        lastPlus = plus;
        ins >> coefficient >> oper >> exponential;
        if (lastPlus == '-')
            arg.poly.InsertBack(temp.Set(-coefficient, exponential));
        else
            arg.poly.InsertBack(temp.Set(coefficient, exponential));
        do
        {
            cin.get(plus);
        } while (plus == ' ');
    }
    return ins;
}
ostream &operator<<(ostream &outs, Polynomial &arg)
{
    Chain<Term>::ChainIterator ai = arg.poly.begin();
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