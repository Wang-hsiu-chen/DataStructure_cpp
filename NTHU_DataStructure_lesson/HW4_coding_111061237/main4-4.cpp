#include "HW4_BST.cpp"

int main()
{
    int key, del;
    BST<int, char> T, left, right;
    pair<int, char> pair[13], *A, *mid;
    pair[0].first = 50;
    pair[0].second = 'I';
    pair[1].first = 5;
    pair[1].second = 'W';
    pair[2].first = 30;
    pair[2].second = 'I';
    pair[3].first = 40;
    pair[3].second = 'L';
    pair[4].first = 80;
    pair[4].second = 'L';
    pair[5].first = 35;
    pair[5].second = 'G';
    pair[6].first = 2;
    pair[6].second = 'E';
    pair[7].first = 20;
    pair[7].second = 'T';
    pair[8].first = 15;
    pair[8].second = 'A';
    pair[9].first = 60;
    pair[9].second = '+';
    pair[10].first = 70;
    pair[10].second = 'Y';
    pair[11].first = 8;
    pair[11].second = 'N';
    pair[12].first = 10;
    pair[12].second = 'M';

    for (int i = 0; i < 13; i++)
    {
        cout << "Inserts (" << pair[i].first << ", " << pair[i].second << ") to Dictionary and BST" << endl;
        T.Insert(pair[i]);
    }
    cout << endl;
    cout << "Get element with key " << 3 << " : ";
    A = T.Get(3);
    if (A)
        cout << A->first << endl;
    else
        cout << "Can't find" << endl;

    cout << "Delete element with key " << 5 << " : " << endl;
    T.Delete(5);
    A = T.RankGet(2);
    cout << "Get element by rank " << 2 << " : " << A->first << endl;

    cout << "Split the element with key " << 5 << " : " << endl;
    T.Split(5, left, mid, right);

    return 0;
}