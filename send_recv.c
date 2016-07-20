#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	MPI_Status status;
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int in_val = 100, out_val;
	
	MPI_Sendrecv(&in_val, 1, MPI_INT, 0,1, &out_val, 1, MPI_INT, 0, 10, MPI_COMM_WORLD, &status);
	printf("Receiver:%d\n", out_val);



	MPI_Finalize();
	return 0;
}
