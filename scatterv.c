#include <mpi.h>
#include <stdlib.h>
#include<stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);

	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int matrix[8][8], result[100];

	int i,j;
	printf("\n");
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			matrix[i][j] = i;
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	
//	result = malloc(size * sizeof(int));
	int sendcounts[] = {1,2,3,4,5,6,7,8};
	int disp[]={0,8,16,24,32,40,48,56};
	MPI_Scatterv(matrix, sendcounts, disp, MPI_INT, result, 100,MPI_INT, 0, MPI_COMM_WORLD);
	printf("Process:%d\n",rank);
	for(i=0;i<sendcounts[rank];i++){
		printf("%d\t", result[i]);

	}


	MPI_Finalize();
	return 0;
}
