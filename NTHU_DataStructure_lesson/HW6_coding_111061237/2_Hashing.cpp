#include "2_Hashing.h"

template <class T>
LinearProbing<T>::LinearProbing()
{
    for (int i = 0; i < 26; i++)
        ht[i] = "";
}
template <class T>
void LinearProbing<T>::Insert(const T key)
{
    int index = hash(key[0]);
    int j = index;
    while (ht[j] != "")
    {
        j = (j + 1) % 26;
        if (j == index)
        {
            cout << "Symbol table is full." << endl;
            return;
        }
    }
    ht[j] = key;
    cout << "Put \"" << key << "\" into d1" << endl;
}
template <class T>
T LinearProbing<T>::Get(const T key)
{ // search the linear probing hash table ht（each bucket has exactly one slot）for k.
    // If a pair with this key is found, return a pointer to this pair;
    //  otherwise, return 0
    int index = hash(key[0]); // home bucket
    int j;
    for (j = index; ht[j] != "" && ht[j] != key;)
    {
        j = (j + 1) % 26; // treat the table as circular
        if (j == index)
            return "no this key"; // back to the start point
    }
    if (ht[j] == key)
        return ht[j];
    return "no this key";
}

template <class T>
Chaining<T>::Chaining()
{
    for (int i = 0; i < 26; i++)
        ht[i] = NULL;
}
template <class T>
void Chaining<T>::Insert(const T key)
{
    int index = hash(key[0]);

    Node *newNode = new Node;
    newNode->key = key;
    newNode->next = NULL;

    if (ht[index] == NULL)
        ht[index] = newNode;
    else
    {
        Node *current = ht[index];
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
    cout << "Put \"" << key << "\" into d2" << endl;
}
template <class T>
T Chaining<T>::Get(const T key)
{ // 在鏈雜湊表ht中搜尋k，如果找到具有這個鍵值的字典對，
    // 那麼回傳這個字典對的指標；否則回傳0
    int index = hash(key[0]);
    for (Node *current = ht[index]; current != NULL; current = current->next)
        if (current->key == key)
            return current->key;
    return "no this key";
}
