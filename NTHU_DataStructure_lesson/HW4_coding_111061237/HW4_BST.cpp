#include "HW4_BST.h"

template <class K, class E>
pair<K, E> *BST<K, E>::Get(const K &k) const
{
    TreeNode<pair<K, E>> *currentNode = root;
    while (currentNode)
    {
        if (k < currentNode->data.first)
            currentNode = currentNode->leftChild;
        else if (k > currentNode->data.first)
            currentNode = currentNode->rightChild;
        else
            return &currentNode->data;
    }
    // no matching pair
    return 0;
}
template <class K, class E>
pair<K, E> *BST<K, E>::RankGet(int r) // search by rank
{                                     // search the BST for the rth smallest pair
    TreeNode<pair<K, E>> *currentNode = root;
    while (currentNode)
    {
        if (r < currentNode->leftSize)
            currentNode = currentNode->leftChild;
        else if (r > currentNode->leftSize)
        {
            r -= currentNode->leftSize;
            currentNode = currentNode->rightChild;
        }
        else
            return &currentNode->data;
    }
    return 0;
}
template <class K, class E>
void BST<K, E>::Insert(const pair<K, E> &thePair)
{ // insert thePair into the BST
    // search for thePair.first，pp parent of p
    TreeNode<pair<K, E>> *p = root, *pp = 0;
    while (p)
    {
        pp = p;
        if (thePair.first < p->data.first)
            p = p->leftChild;
        else if (thePair.first > p->data.first)
            p = p->rightChild;
        else // duplicate, update associated element
        {
            p->data.second = thePair.second;
            return;
        }
    }
    // perform insertion
    p = new TreeNode<pair<K, E>>;
    p->data = thePair;
    if (root) // tree is nonempty
        if (thePair.first < pp->data.first)
            pp->leftChild = p;
        else
            pp->rightChild = p;
    else
        root = p;
}
template <class K, class E>
void BST<K, E>::Split(const K &k, BST<K, E> &small, pair<K, E> *&mid,
                      BST<K, E> &big)
{ // Split the BST with respect to key k
    if (!root)
    {
        small.root = big.root = 0;
        return;
    } // empty tree
    // create temporary header nodes for small and big
    TreeNode<pair<K, E>> *sHead = new TreeNode<pair<K, E>>,
                         *s = sHead,
                         *bHead = new TreeNode<pair<K, E>>,
                         *b = bHead,
                         *currentNode = root;
    while (currentNode)
    {
        if (k < currentNode->data.first)
        { // case 1
            b->leftChild = currentNode;
            b = currentNode;
            currentNode = currentNode->leftChild;
        }
        else if (k > currentNode->data.first)
        { // case 2
            s->rightChild = currentNode;
            s = currentNode;
            currentNode = currentNode->rightChild;
        }
        else
        { // case 3
            s->rightChild = currentNode->leftChild;
            b->leftChild = currentNode->rightChild;
            small.root = sHead->rightChild;
            delete sHead;
            big.root = bHead->leftChild;
            delete bHead;
            mid = new pair<K, E>(currentNode->data.first,
                                 currentNode->data.second);
            delete currentNode;
            return;
        }
    } // no pair with key k
    s->rightChild = b->leftChild = 0;
    small.root = sHead->rightChild;
    delete sHead;
    big.root = bHead->leftChild;
    delete bHead;
    mid = 0;
    return;
}
