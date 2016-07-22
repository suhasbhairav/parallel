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
	
	int coords[2];

	int maxdims;

	dims[0] = 4;
	dims[1] = 3;

	periods[0] = 1;
	periods[1] = 1;

	maxdims = 2;

	MPI_Cart_create(MPI_COMM_WORLD, ndims, dims, periods, reorder, &comm);
	MPI_Cart_coords(comm, rank, maxdims, coords);

	printf("Rank %d has coordinates %d,%d\n", rank, coords[0], coords[1]);
	if(rank == 0){
		coords[0] = 0; coords[1] = 1;
		MPI_Cart_rank(comm, coords, &rank);
	}
	


	MPI_Finalize();
	return 0;
}
