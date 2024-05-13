#include <iostream>
using namespace std;

template <class T>
class TreeNode
{
    // friend class Dictionary<T>;
private:
    T data;
    TreeNode<T> *leftChild;
    TreeNode<T> *rightChild;
};
template <class K, class E>
class Dictionary
{
public:
    virtual bool IsEmptay() const = 0; // return true if dictionary is empty
    virtual pair<K, E> *Get(const K &) const = 0;
    // return pointer to the pair w. specified key
    virtual void Insert(const pair<K, E> &) = 0;
    // insert the given pair; if key ia a duplicate, update associate element
    virtual void Delete(const K &) = 0; // delete pair w. specified key
    struct pair
    {
        K first;
        E second;
    };
};
template <class K, class E>
class BST : public Dictionary<K, E>
{
public:
    virtual bool IsEmptay() const; // return true if dictionary is empty
    pair<K, E> *Get(const K &) const;
    // return pointer to the pair w. specified key
    void Insert(const pair<K, E> &);
    // insert the given pair; if key ia a duplicate, update associate element
    void Delete(const K &); // delete pair w. specified key
    pair<K, E> *RankGet(int r);
    void Split(const K &k, BST<K, E> &small, pair<K, E> *&mid, BST<K, E> &big);

private:
    TreeNode<pair<K, E>> *root;
};
