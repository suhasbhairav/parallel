#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	/*int num_amount;
	const int MAX_NUM = 100;
	int nums[MAX_NUM];
	if(rank == 0){
		srand(time(NULL));
		num_amount = ( rand() / (float) RAND_MAX)* MAX_NUM;

		MPI_Send(nums, num_amount, MPI_INT, 1,1, MPI_COMM_WORLD );
		printf("Sent number_amount%d\n", num_amount);
	}else{
		MPI_Status status;
		MPI_Recv(nums, MAX_NUM, MPI_INT, 0,1, MPI_COMM_WORLD, &status);
		MPI_Get_count(&status, MPI_INT, &num_amount);
		printf("Num_amount:%d, status_source:%d, tag:%d\n", num_amount, status.MPI_SOURCE, status.MPI_TAG);

	}*/



	int num_amount;
	int arr_num[100];
	if(rank == 0){
		num_amount = 200;
		MPI_Send(arr_num, num_amount, MPI_INT, 1, 1, MPI_COMM_WORLD );
		printf("Sent:%d\n", num_amount);
	}else{
		MPI_Status status;
		MPI_Recv(arr_num, 400, MPI_INT, 0,1, MPI_COMM_WORLD, &status);
		MPI_Get_count(&status, MPI_INT, &num_amount);
		printf("Source:%d\n, num_amount:%d\n", status.MPI_SOURCE, num_amount);

	}


	MPI_Finalize();
	return 0;

}
