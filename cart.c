#include <mpi.h>
#include <stdio.h>
int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm comm_cart;
	/*int ndims = 2, dims[2], periods[2], reorder, coords[2];

	dims[0] = 4;
	dims[1] = 3;
	periods[0] = 1;
	periods[1] = 0;
	reorder = 1;
	
	int i,j;

	MPI_Cart_create(MPI_COMM_WORLD, ndims, dims, periods, reorder, &comm_cart);

	MPI_Cart_coords(comm_cart, rank, ndims,coords);
	printf("\n");
	printf("Rank %d coordinates are %d %d\n", rank, coords[0], coords[1]);

	if(rank  == 0){
		coords[0]=3;
		coords[1] = 1;
		MPI_Cart_rank(comm_cart, coords, &rank);
		//printf("The processor at position %d,%d has rank %d\n", coords[0], coords[1], rank);
	}

	*/


	int ndims = 2;
	int dims[2];
	int periods[2];
	int reorder;
	MPI_Comm comm;
	int coords[2];
	int maxdims;

	dims[0] = 3;
	dims[1] = 4;
	periods[0] = 1;
	periods[1] = 0;

	reorder = 1;
	MPI_Cart_create(MPI_COMM_WORLD, ndims, dims, periods, reorder, &comm);

	MPI_Cart_coords(comm, rank, ndims, coords);
	printf("Rank %d has coordinates %d,%d\n", rank, coords[0], coords[1]);
	if(rank == 0){
		coords[0] = 0; coords[1] = 0;
		MPI_Cart_rank(comm, coords, &rank);
	}	
	

	

	MPI_Finalize();
	return 0;
}
