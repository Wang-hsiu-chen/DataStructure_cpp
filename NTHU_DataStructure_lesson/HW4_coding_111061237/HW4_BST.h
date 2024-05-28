#include <iostream>
using namespace std;

template <class K, class E>
class BST;
template <class K, class E>
class TreeNode
{
    friend class BST<K, E>;

public:
    TreeNode(){};
    TreeNode(pair<K, E> thePair) { data = thePair; };
    pair<K, E> data;
    TreeNode<K, E> *leftChild;
    TreeNode<K, E> *rightChild;
    int leftSize = 1;
};
template <class K, class E>
class Dictionary
{
public:
    Dictionary(int DCapacity = 10);
    virtual bool IsEmptay() const = 0; // return true if dictionary is empty
    virtual pair<K, E> *Get(const K &) const = 0;
    // return pointer to the pair w. specified key
    virtual void Insert(const pair<K, E> &) = 0;
    // insert the given pair; if key ia a duplicate, update associate element
    virtual void Delete(const K &) = 0; // delete pair w. specified key
    // struct pair
    // {
    //     K first;
    //     E second;
    // };
private:
    pair<K, E> *pages;
    int capacity;
    int Size;
};
template <class K, class E>
Dictionary<K, E>::Dictionary(int DCapacity)
{
    capacity = DCapacity;
    pages = new pair<K, E>[capacity];
    Size = 0;
}
template <class K, class E>
class BST : public Dictionary<K, E>
{
public:
    BST();
    bool IsEmptay() const; // return true if dictionary is empty
    pair<K, E> *Get(const K &) const;
    // return pointer to the pair w. specified key
    void Insert(const pair<K, E> &);
    // insert the given pair; if key ia a duplicate, update associate element
    void Delete(const K &); // delete pair w. specified key
    pair<K, E> *RankGet(int r);
    void Split(const K &k, BST<K, E> &small, pair<K, E> *&mid, BST<K, E> &big);

private:
    TreeNode<K, E> *root;
};
