#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	/*int world_rank, rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm dup_comm, world_comm;
	MPI_Group world_group;

	MPI_Comm_dup(MPI_COMM_WORLD, &dup_comm);
	
	MPI_Comm_group(dup_comm, &world_group);

	MPI_Comm_create(dup_comm, world_group, &world_comm);

	MPI_Comm_rank(world_comm, &rank);
	if(rank !=world_rank){
		printf("Incorrect rank\n");
	}else{
		printf("It worked\n");
	} */


	int world_rank, rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	MPI_Comm dup_comm, world_comm;
	MPI_Group world_group;


	MPI_Comm_dup(MPI_COMM_WORLD, &dup_comm);

	MPI_Comm_group(dup_comm, &world_group);
	MPI_Comm_create(dup_comm, world_group, &world_comm);

	MPI_Comm_rank(world_comm, &rank);
	if(rank == world_rank){
		printf("It worked!");
	}

	MPI_Finalize();
	return 0;
}
