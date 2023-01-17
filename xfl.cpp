#include<iostream>
#include <cmath>
using namespace std;

class mallocs
{
    private:
    double *a = new double;
    double *b = new double;
    public:
    void getdata()
    {
        cout << "Enter Fuel Mass: ";
        cin >> *a;
        *b = 5.2131*(pow(10,-11)*pow(*a,3))-2.8487*(pow(10,-7)*pow(*a,2))+5.1276*(pow(10,-4)* *a)+5.4394;
    }
    void addition()
    {
        cout << "Fuel arm length is: " << *b;
        delete a;
        delete b;
    }
};

int main()
{
    mallocs obj;
    obj.getdata();
    obj.addition();
    return 0;
}