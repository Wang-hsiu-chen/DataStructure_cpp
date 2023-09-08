#include <iostream>

using namespace std;

void HN(int k, int p1, int p2, int p3){
    if (k == 1) {
        cout << p1 << "->" << p3;
    } else {
        HN(k - 1, p1, p3, p2);
        cout << p1 << "->" << p3;
        HN(k - 1, p2, p1, p3);
        if (p1 == 1) cout << endl;
    }
    return ;
}

int main(){
    int k;
    cin >> k;
    HN(k, 1, 2, 3);
    return 0;
}