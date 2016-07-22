#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);

	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int ndims = 2;
	int dims[2];
	int periods[2];
	int reorder;
	MPI_Comm comm;

	//int direction;
	//int disp;
	int rank_source, rank_dest;


	dims[0] = 4;
	dims[1]=3;

	periods[0] = 1;
	periods[1] = 1;

	MPI_Cart_create(MPI_COMM_WORLD, ndims, dims, periods, reorder, &comm);
	
	printf("\nBefore Shifting: Source:%d, Destination:%d", rank_source, rank_dest);
	MPI_Cart_shift(comm, 0, 1, &rank_source, &rank_dest);

	printf("\nRound : 1 =>  Source:%d, Destination:%d", rank_source, rank_dest);
	
	MPI_Cart_shift(comm, 1, 1, &rank_source, &rank_dest);
	
	printf("\n Round : 2 => Source:%d, Destination:%d", rank_source, rank_dest);


	MPI_Comm_free(&comm);
	MPI_Finalize();

	return 0;
}
