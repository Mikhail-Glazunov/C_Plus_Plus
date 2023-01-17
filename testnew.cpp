#include <iostream>
using namespace std;

int main () {
   double* pv  = NULL; // Pointer initialized with null
   pv  = new double;   // Request memory for the variable
   //double x;
   cin >> pv* ;
   //*pv = x;     // Store value at allocated address
   cout << "Value of pvalue : " << *pv << endl;

   delete pv;         // free up the memory.

   return 0;
}