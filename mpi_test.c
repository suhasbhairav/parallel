#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	/*
	int left, right, val = 100, result;
	right = ( rank + 1) %size;
	left = rank -1;
	if(left < 0){
		left = size - 1;
	
	}
	
	MPI_Request request;
	MPI_Irecv(&result,1, MPI_INT, left,1, MPI_COMM_WORLD, &request );

	MPI_Send(&val, 1, MPI_INT, right, 1, MPI_COMM_WORLD);
	MPI_Status status;
	int flag = 0;
	MPI_Test(&request, &flag, &status);

	while(!flag){

		printf("Not yet set...");
		MPI_Test(&request, &flag, &status);
	}

	*/


	int left, right, flag = 0;
	MPI_Request request;
	MPI_Status status;
	int val = 200, result;
	right = ( rank + 1) %size;
	left = rank -1;
	if(left < 0) rank = size -1;

	MPI_Irecv(&result, 1, MPI_INT, left, 1, MPI_COMM_WORLD, &request);

	MPI_Send(&val, 1, MPI_INT, right,1, MPI_COMM_WORLD);

	MPI_Test(&request, &flag, &status);
	while(!flag){
		printf("\tResult:%d",result);
		MPI_Test(&request, &flag, &status);
	}
	MPI_Finalize();
	return 0;
}
