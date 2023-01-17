#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
const int n=10, nt=200;
double x[n+1];
double y[nt+1][n+1];
double h=1.0/n;
double tau=1.0/nt;
int main() {
    ofstream fout;
    fout.open("Output.dat");
    for (int i = 0; i <= n; ++i) {
        x[i] = (double) i/n;
        fout << setw(10) << x[i];
    }
    fout << endl;
    for (int i=0; i<=n;i++){
        y[0][i] = 0;
    }    
    y[0][n/3] = 1;
    for (int t=0; t<=nt-1;++t){
        y[t+1][0]=0;
        y[t+1][n]=0;
        fout << setw(10) << 0;
        for (int i=1; i <=n-1; ++i) {
            y[t+1][i]=tau*((y[t][i+1]-2*y[t][i]+y[t][i-1])/(h*h))+y[t][i];
            fout << setw(10) << setprecision(5) << y[t+1][i];
        }
        fout << setw(10) << 0;
        fout << endl;
    }    
    fout << endl;
    fout.close();
    return 0;
}