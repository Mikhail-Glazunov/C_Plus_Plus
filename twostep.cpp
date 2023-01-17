#include <iostream>
#include <fstream>
#include <mpi.h>

using namespace std;
//const int n=100, nt=20000;
int n;
int nt;
double* x;
double** y;
double* y_1;
double* y_0;
double y_n;
int main(int argc,char ** argv) {
    int size;
    int rank;
    int N;
    MPI_Status st;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    string s1("Output"+to_string(rank)+".dat");
    string s2("stat"+to_string(rank)+".dat");
    if (argc < 2){
        cout << "too few parameters";
        return 0;
    }
    N = atoi(argv[1]);
    n = N/size;
    nt = atoi(argv[2]);
    double h=1.0/n/size;
    double tau=1.0/nt;
    if(rank == 0){
        cout << "2*tau/h/h = " << 2*tau/h/h << endl;    
    }
    x=(double*)malloc(sizeof(double)*(n+1));
    //y=(double**)malloc(sizeof(double*)*(nt+1));
    //for (int i=0; i<=nt+1;i++){
       //y[i]=(double*)malloc(sizeof(double)*(n+1)); 
    //}
    y_1=(double*)malloc(sizeof(double)*(n+1));
    y_0=(double*)malloc(sizeof(double)*(n+1));
   

    ofstream fout;
    ofstream fout2;
    fout.open(s1.c_str());
    fout2.open(s2.c_str());
    for (int i = 0; i <= n; ++i) {
        x[i] = (double) i/n;
        fout << setw(10) << x[i];
    }
    fout << endl;
    for (int i=0; i<=n;i++){
        y_0[i] = 0;
    }    
    y_0[n/3] = 1;
    fout2 << 1 << endl;


    for (int t=0; t<=nt-1;++t){
        if(rank!=0){
            MPI_Recv(&y_1[0],1,MPI_DOUBLE,rank-1,0,MPI_COMM_WORLD,&st);
            //cout << "Number: " << rank << "Recieved: " << y_1[0] << endl;
            MPI_Send(&y_0[1],1,MPI_DOUBLE,rank-1,0,MPI_COMM_WORLD);
        }
        else{
            y_1[0]=0;
        }
        if(rank!=size-1){
            //cout << "Number: " << rank << "Sent: " << y_0[n-1] << endl;        
            MPI_Send(&y_0[n-1],1,MPI_DOUBLE,rank+1,0,MPI_COMM_WORLD);
            MPI_Recv(&y_1[n],1,MPI_DOUBLE,rank+1,0,MPI_COMM_WORLD,&st);
            //cout << "Number: " << rank << "Recieved: " << y_1[n] << endl;    
        }
        
        else{
            y_1[n]=0; 
        }
        fout << setw(10) << 0;
        for (int i=1; i <=n-1; ++i) {
            y_1[i]=tau*((y_0[i+1]-2*y_0[i]+y_0[i-1])/(h*h))+y_0[i];
            fout << setw(10) << setprecision(5) << y_0[i];
        }
        y_n=0;
        for (int i=1; i<=n-1; ++i){
            y_0[i]=y_1[i];
            y_n += y_0[i];

        }
        fout2 << y_n << endl;
        fout << setw(10) << 0;
        fout << endl;

    }
    fout << setw(10) << 0;
    for (int i=1; i <=n-1; ++i) {
        fout << setw(12) << setprecision(5) << y_1[i]; 
    }
    fout << setw(10) << 0;
    fout << endl;
    fout.close();
    fout2.close();
    MPI_Finalize();
    return 0;
}