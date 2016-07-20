#include <stdio.h>
#include <mpi.h>

int main(int ragc, char *argv){
	MPI_Init(NULL, NULL);
	/*int rank, size, color;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	color = rank/4;
	MPI_Comm row_comm;
	MPI_Comm_split(MPI_COMM_WORLD, color, rank, &row_comm );

	int row_rank, row_size;
	MPI_Comm_rank(row_comm, &row_rank);
	MPI_Comm_size(row_comm, &row_size);

	printf("w_r:%d w_s:%d r_r:%d r_s:%d\n", rank, size, row_rank, row_size);
	
	MPI_Comm_free(&row_comm);
	*/

	int rank, color, size, row_rank, row_size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm new_comm;

	color = rank/6;
	MPI_Comm_split(MPI_COMM_WORLD, color, rank, &new_comm);

	MPI_Comm_rank(new_comm, &row_rank);
	MPI_Comm_size(new_comm, &row_size);

	printf("r:%d s:%d r_r:%d r_s:%d\n", rank, size, row_rank, row_size);

	MPI_Comm_free(&new_comm);



	MPI_Finalize();
	return 0;
}
