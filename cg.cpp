#include <iostream>

using namespace std;

int main() {
    float mx;
    float m;
    float cg;
    cout << "Enter mx: ";
    cin >> mx;
    cout << "Enter m: ";
    cin >> m;
    cg = (((mx/m)-5.149)/1.717)*100;
    cout << cg;

    return 0;
}