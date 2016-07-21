#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int *globaldata = NULL;
	int localdata;
	int i;
	if(rank == 0){
		globaldata = malloc( size * sizeof(int));
		for(i=0;i<size;i++){
			globaldata[i] = 2 *i+1;
			printf("%d\n", globaldata[i]);

		}

	}
	MPI_Scatter(globaldata, 1, MPI_INT, &localdata, 1, MPI_INT, 0, MPI_COMM_WORLD);


	localdata = localdata * 2;
	MPI_Gather(&localdata, 1, MPI_INT, globaldata, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if(rank ==0){
	for(i=0; i<size;i++){
		printf("%d\n", globaldata[i]);

	}}

	
	


	MPI_Finalize();
	return 0;
}	
