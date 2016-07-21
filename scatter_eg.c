#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int matrix[8][8], *result = NULL;
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			matrix[i][j] = i*i;
//			result[i][j] = -1;
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");

	}
	result  = malloc(size * sizeof(int));
	MPI_Scatter(matrix, size, MPI_INT, result, size, MPI_INT, 0, MPI_COMM_WORLD);
	printf("ID:%d\n", rank);
	for(i=0;i<size;i++){
               { 
                       // matrix[i][j] = i*i;
                       // result[i][j] = -1;
                        printf("%d\t", result[i]);
                }
                printf("\n");

        }
	

	MPI_Finalize();
	return 0;
}
