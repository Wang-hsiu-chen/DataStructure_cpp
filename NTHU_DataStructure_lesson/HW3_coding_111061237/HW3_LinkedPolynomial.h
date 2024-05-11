#include <iostream>
using namespace std;

class Polynomial; // 前向宣告
class Term
{
    friend class Polynomial;

private:
    int coef;
    int exp;
    Term *link;
    inline Term Set(int c, int e)
    {
        coef = c;
        exp = e;
        return *this;
    }
    inline Term GetCoef() { return coef; }
    inline Term GetExp() { return exp; }
};
template <class T>
class Chain
{
public:
    int Size()
    {
        int size = 0;
        if (head == NULL)
            return 0;
        Term *pointer = head;
        while (pointer->link != head)
        { // delete first
            size++;
            pointer = pointer->link;
        }
        return size + 1;
    }
    void InsertBack(const T &node)
    {
        if (head == NULL) // empty list
        {
            head = node;
            head->link = head;
        }
        else if (head != NULL)
        {
            Term *temp = head;
            while (temp->link != head)
                temp = temp->link;
            node->link = temp->link;
            temp->link = node;
        }
    }
    class ChainIterator
    {
    public: // typedefs required by C++ for a forward iterator
        // Constructor
        ChainIterator(Term *startNode = 0)
        {
            current = startNode;
        }
        // Dereferencing operators
        T &operator*() const { return current; }
        T *operator->() const { return &current; }
        // Increment
        ChainIterator &operator++() // preincrement
        {
            current = current->link;
            return *this;
        }
        ChainIterator &operator++(int) // postincrement
        {
            ChainIterator old = *this;
            current = current->link;
            return old;
        }
        // Equality test
        bool operator!=(const ChainIterator r)
        {
            return current != r.current;
        }
        bool operator==(const ChainIterator r)
        {
            return current == r.current;
        }

    private:
        Term *current;
    };
    ChainIterator begin() { return ChainIterator(first); }
    ChainIterator end() { return ChainIterator(0); }

private:
    Term *head;
};
class Polynomial
{
public:
    friend istream &operator>>(istream &is, Polynomial &x); // Read in an input polynomial and convert it to its circular list representation using a header node.
    friend ostream &operator<<(ostream &os, Polynomial &x); // Convert x from its linked list representation to its external representation and output it.
    Polynomial::Polynomial(const Polynomial &a);            // copy constructor
    Polynomial::~Polynomial();
    const Polynomila& Polynomial::operator=(const Polynomial& a) const[assignment operator]; // assign polynomial a to *this.
    Polynomial::~Polynomial();                                                               // desctructor, return all nodes to available-space list
    Polynomial operator+(const Polynomial &b) const;                                         //  Create and return the polynomial *this + b
    Polynomial operator-(const Polynomial &b) const;                                         //  Create and return the polynomial *this – b
    Polynomial operator*(const Polynomial &b) const;                                         //  Create and return the polynomial *this * b
    double Polynomial::Evaluate(double x) const;                                             // Evaluate the polynomial *this and return the result.
    int Polynomial::Coef(int e);
    int Polynomial::LeadExp();

private:
    Chain<Term> poly;
};