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
    double Polynomial::Evaluate(double x) const;

private:
    Chain<Term> poly;
};

Polynomial
Polynomial::operator+(const Polynomial &b) const
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