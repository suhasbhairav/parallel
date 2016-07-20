#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Request request[2];
	int in_val = 100, out_val;
	MPI_Status status[2];

	int left, right;
	right = (rank + 1)%size;
	left =  rank -1;
	if(left <0){
		left = size-1;
	}
	MPI_Isend(&in_val, 1, MPI_INT, left, 123, MPI_COMM_WORLD, &request[0]);
	MPI_Irecv(&out_val, 1, MPI_INT, right, 123, MPI_COMM_WORLD, &request[1] );
	

	MPI_Waitall(2, request, status);
	printf("Received:%d\n", out_val);

	MPI_Finalize();
	return 0;
}
