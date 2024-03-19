#include <iostream>
using namespace std;
double a = 0.1, b = 0.2, c = 0.3, d = 0.5;
int main(){
    if (0.5 + 0.1 == 0.6) cout << "T\n";
    else cout << "F\n";
    if (a + b == 0.3) cout << "T\n";
    else cout << a << "+" << b << "!=" << 0.3 << "F\n";
}