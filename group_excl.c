#include<mpi.h>
#include<stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int ranks[100];
	MPI_Group world_group, worker_group;
	MPI_Comm workers;
	MPI_Comm_group(MPI_COMM_WORLD, &world_group);
	ranks[0] = size-1;
	MPI_Group_excl(world_group, 1, ranks, &worker_group);
	MPI_Comm_create(MPI_COMM_WORLD, worker_group, &workers);
	MPI_Group_free(&worker_group);
	MPI_Group_free(&world_group);
	
	MPI_Comm_free(&workers);




	MPI_Finalize();
	return 0;
}
