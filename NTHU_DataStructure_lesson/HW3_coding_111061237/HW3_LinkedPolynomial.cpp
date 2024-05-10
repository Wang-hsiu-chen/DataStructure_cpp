#include "HW3_LinkedPolynomial.h"

Polynomial::operator+(const Polynomial & b) const
{
    Term temp;
    Chain<Term>::ChainIterator ai = poly.begin(), bi = b.poly.begin();
    Polynomial c;
    while (ai && bi)
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
    while (ai)
    {
        c.poly.InsertBack(temp.Set(ai->coef, ai->exp));
        ai++;
    }
    while (bi)
    {
        c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
        bi++;
    }
    return c;
}