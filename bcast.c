#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	/*
	int val = 0;
	if(rank == 0){
		val = 2000;
	}
	printf("Before broadcast: %d\n", val);
	MPI_Bcast(&val, 1, MPI_INT, 0, MPI_COMM_WORLD);

	printf("After broadcast:%d\n", val);
	*/

	int val = 200;

	if(rank == 0){
		val = 300;
	}
	printf("Before broadcast:%d\n", val);

	MPI_Bcast(&val, 1, MPI_INT, 0, MPI_COMM_WORLD);

	printf("After broadcast:%d\n", val);

	MPI_Finalize();
	return 0;
}
