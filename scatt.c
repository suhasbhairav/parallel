#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int matrix[8][8], inter[8][8],*result = NULL;
	result = malloc(size * sizeof(int));
	
	printf("\n\n");
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			matrix[i][j] = (i*i);
			inter[i][j] = -1;
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	
	MPI_Scatter(matrix, size, MPI_INT, result, size, MPI_INT, 0, MPI_COMM_WORLD);
	/*int temp;
	for(i=0;i<size;i++){
		temp = temp + result[i];
	}*/
	//MPI_Gather(&temp, size, MPI_INT, result, size, MPI_INT, 0, MPI_COMM_WORLD);
	printf("Temp:%d",temp);
	printf("\nProcess:%d\n", rank);
	for(i=0;i<size;i++){
		printf("%d\t", result[i]);
	}

	/*printf("Inter\n");
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			printf("%d\t", inter[i][j]);
		}
		printf("\n");
	}*/

	MPI_Finalize();
	return 0;
}
