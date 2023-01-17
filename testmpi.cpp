#include <iostream>
#include <cmath>
#include <mpi.h>

using namespace std;
int main(int argc,char ** argv) {
    float x;
    float xfl;
    int size;
    int rank;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    

    

    cout << "Number of processes: " << size << " " << "My number is: " << rank << endl;
    MPI_Finalize();
    return 0;
}
