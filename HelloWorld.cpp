#include <iostream>

using namespace std;
const int n=10;
double x[n+1];
double y[n+1];
double h=1.0/n;
int main() {
    for (int i = 0; i <= n; ++i) {
        x[i] = (double) i/n;
        cout << x[i] << "\t";
    }
    cout << endl;
    y[0]=1;
    for (int i=0; i <=n; ++i) {
        y[i+1]=h*y[i]+y[i];
        cout << y[i+1] << "\t";
    }
    cout << endl;
    return 0;
}
