#include <iostream>
#include <cmath>

using namespace std;
const int n=1000;
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
    y[1]=h*y[0]+y[0];
    cout << y[0] << "\t" << y[1] <<"\t";
    for (int i=1; i <=n-1; ++i) {
        y[i+1] = 2.0 * h * y[i] + y[i-1];
        cout << y[i+1] << "\t";
    }
    cout << endl;
    return 0;
}

