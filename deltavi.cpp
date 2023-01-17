#include <iostream>
#include <cmath>
#include <fstream> 

using namespace std;

int main(){
    double v [8] = {159.5,151.7,143.7,133.8,128.9,123.0,116.2,113.1};
    double dp [8] = {-0.091,-0.079,-0.077,-0.071,-0.067,-0.062,-0.061,-0.061};
    double h [8] = {4838.0,4797.0,4800.0,4831.0,4815.0,4827.0,4801.0,4805.0};
    double oat [8] = {3.0,3.0,2.0,2.0,2.0,2.0,3.0,2.0};
    double ms;
    double m;
    double kdp;
    double vb;
    int n = 8;
    double po = 101325;
    double ro = 1.225;
    double go = 9.807;
    double pminus;
    double ps;
    double rvc;
    double vsquared;
    double ppinf;
    double pinf;
    double vc;
    double dvi;
    double hdash;
    double dhp;
    double hp;

    ofstream fout;
    ofstream fout2;
    fout.open("vc.txt");
    fout2.open("vasir.txt");

    cout << "Delta Vi" << endl;
    
    for (int i=0;i<=n-1;++i){
        ms = v[i] * 0.514;
        kdp = (1000) * dp[i];
        vsquared = pow(ms,2);
        pminus = po*((pow(((ro*vsquared)/(7*po)+1),3.5))-1);
        ppinf = pminus - kdp;
        vc = (7*(po/ro))*(pow(1+(ppinf/po),0.2857)-1);
        rvc = sqrt(vc);
        dvi = rvc-ms;
        fout << vc << endl;
        fout2 << v[i] << endl;
        cout << dvi << endl;
    } 

    cout << "Pressure Altitude" << endl;

    for (int i=0;i<=n-1;++i){
        hdash = h[i]+35;
        dhp = -((dp[i])/(po*go));
        hp = hdash - dhp;
        ps = 101325*(pow(1-(6.8756*pow(10,-6)*hp),5.2559));
        pinf = (ps + dp[i])/1000;
        cout << dhp << endl;
    }
    fout.close();
    fout2.close();
    return 0;
}

