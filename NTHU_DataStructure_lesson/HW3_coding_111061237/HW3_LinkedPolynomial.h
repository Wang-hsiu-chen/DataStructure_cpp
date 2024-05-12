#include <iostream>
using namespace std;

template <class T>
class HeaderCircularList;

class Polynomial;
class Term
{
public:
    int coef;
    int exp;
    Term Set(int c, int e);
};

template <class T>
class ChainNode
{
    friend class Polynomial;
    friend class HeaderCircularList<T>;
    template <class U>
    friend ostream &operator<<(ostream &os, HeaderCircularList<U> &L);
    friend istream &operator>>(istream &is, Polynomial &polynomial);
    friend ostream &operator<<(ostream &os, Polynomial &polynomial);

private:
    T data;
    ChainNode<T> *link;
};

template <class T>
class HeaderCircularList
{
    friend class Polynomial;
    template <class U>
    friend ostream &operator<<(ostream &os, HeaderCircularList<U> &L);
    friend istream &operator>>(istream &is, Polynomial &polynomial);
    friend ostream &operator<<(ostream &os, Polynomial &polynomial);

public:
    HeaderCircularList();
    ~HeaderCircularList();
    int count();
    void insertFront(T e);
    void insertBack(T e);
    void deleteFirst();
    void deleteLast();
    ChainNode<T> *GetNode();
    void RetNode(ChainNode<T> *&x);

private:
    ChainNode<T> *header;
    ChainNode<T> *av;
};

class Polynomial
{
    friend istream &operator>>(istream &is, Polynomial &polynomial);
    friend ostream &operator<<(ostream &os, Polynomial &polynomial);

public:
    Polynomial(){};
    ~Polynomial();
    Polynomial(const Polynomial &a);
    const Polynomial &operator=(const Polynomial &a);
    Polynomial operator+(const Polynomial &b) const;
    Polynomial operator-(const Polynomial &b) const;
    Polynomial operator*(const Polynomial &b) const;
    void Set(Term);
    double Evaluate(double x) const;

private:
    HeaderCircularList<Term> poly;
};
