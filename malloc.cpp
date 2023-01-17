#include<iostream>
#include <cmath>
using namespace std;

class dynamic_memeory_allocation
{
    private:
    double *a = new double;
    double *b = new double;
    public:
    void getdata()
    {
        cout << "enter the value of a: ";
        cin >> *a;
        *b = 5.2131*(pow(10,-11)*pow(*a,3))-2.8487*(pow(10,-7)*pow(*a,2))+5.1276*(pow(10,-4)* *a)+5.4394;
    }
    void displaydata()
    {
        cout << *a << endl;
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
    dynamic_memeory_allocation obj;
    obj.getdata();
    obj.displaydata();
    obj.addition();
    return 0;
}