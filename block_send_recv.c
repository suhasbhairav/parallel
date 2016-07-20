#include <mpi.h>
#include<stdio.h>
int main(int argc, char *argv[])
{
    int myid, numprocs, left, right;
    int buffer_in = 100, buffer2;
    MPI_Request request;
    MPI_Status status;
 
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
 
    right = (myid + 1) % numprocs;
    left = myid - 1;
    if (left < 0)
        left = numprocs - 1;
 
    MPI_Sendrecv(&buffer_in, left, MPI_INT, 1, 123, &buffer2, right, MPI_INT, 0, 123, MPI_COMM_WORLD, &status);
     printf("%d\n", buffer2);
    MPI_Finalize();
    return 0;
}


