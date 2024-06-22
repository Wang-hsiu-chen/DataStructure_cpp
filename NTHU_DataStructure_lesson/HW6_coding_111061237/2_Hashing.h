#include <iostream>

using namespace std;

template <class T>
class LinearProbing
{
public:
    LinearProbing();
    T Get(const T k);
    void Insert(const T k);

private:
    int hash(char key) { return key - 'a'; }
    T ht[26];
};

template <class T>
class Chaining
{
public:
    Chaining();
    T Get(const T k);
    void Insert(const T k);

private:
    int hash(char key) { return key - 'a'; }
    struct Node
    {
        T key;
        Node *next;
    };
    Node *ht[26];
};
