#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	/*
	int in_val = 100, out_val;
	MPI_Request request1, request2;
	MPI_Status status;

	int left, right;
	right = (rank+1) %size;
	left = rank-1;
	if(left < 0){
		left = size-1;
	}

		MPI_Isend(&in_val, 1, MPI_INT, left, 1, MPI_COMM_WORLD, &request1);
		printf("Send:%d\n", in_val);

		MPI_Irecv(&out_val, 1, MPI_INT, right, 1, MPI_COMM_WORLD, &request2);	
		//printf("Receive:%d\n", out_val);


	MPI_Wait(&request1, &status);
	MPI_Wait(&request2, &status);
	printf("Receive:%d\n", out_val);
	*/
	int in_val = 100, out_val;
	MPI_Request request1, request2;
	MPI_Status status;
	
	int left, right;
	right = (rank + 1) % size;
	left = rank -1;
	if(left < 0){
		left = size -1;
	}

	
	MPI_Isend(&in_val,1, MPI_INT, left,123, MPI_COMM_WORLD, &request1);
	MPI_Irecv(&out_val,1, MPI_INT, right, 123, MPI_COMM_WORLD, &request2); 
	
	MPI_Wait(&request1, &status);
	MPI_Wait(&request2, &status);
	
	printf("Recv:%d\n", out_val);
	MPI_Finalize();




	return 0;
}
