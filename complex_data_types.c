#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv){

	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	

	int matrix[8][8], result[8][8];
	int localdata;
	int count;
	int blocklength;
	int stride;
	MPI_Datatype new_type;
	
	
	 int i,j;
        printf("\n\n");
        for(i=0;i<8;i++){
                for(j=0;j<8;j++){
                        matrix[i][j] = i*i;
                        result[i][j] = -1;
                        printf("%d\t", matrix[i][j]);
                }
                printf("\n");
        }

	/* Send First two columns*/

	/*	
	count = 8;
	blocklength = 2;
	stride = 8;
	
	
	MPI_Type_vector(count, blocklength, stride, MPI_INT, &new_type);
	MPI_Type_commit(&new_type);
	*/
	

	/*Send upper triangular matrix */

	
	count = 8;
	int block_arr[]={8,7,6,5,4,3,2,1};
	int disp_arr[]= {0,9,18,27,36,45,54,63};
	

	/*Send lower triangular matrix */
	
	/*	
	count = 8;
	int block_arr[] = {1,2,3,4,5,6,7,8};
	int disp_arr[] = {0,8,16,24,32,40,48,56};
	*/

	/*Send diagonal*/
	/*
	count = 8;
	int block_arr[]={1,1,1,1,1,1,1,1};
	int disp_arr[] = {0,9,18,27,36,45,54,63};	
	*/

	
	//MPI_Type_indexed(count, block_arr, disp_arr, MPI_INT, &new_type);
	//MPI_Type_commit(&new_type);
	
	/*
	if(rank == 0){
		MPI_Send(&matrix[0][0],1, new_type,1, 1, MPI_COMM_WORLD);

	}else{

		MPI_Recv(result, 1, new_type, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

	}*/
	/*
	 for(i=0;i<8;i++){
                for(j=0;j<8;j++){
                        //matrix[i][j] = i*i;
                        //result[i][j] = -1;
                        printf("%d\t", result[i][j]);
                }
                printf("\n");
        }
	*/
	//MPI_Scatter(matrix, 1, new_type, result, 1, new_type, 0, MPI_COMM_WORLD);
	int sendcount[] = {1,2,3,4,5,6,7,8};
	MPI_Scatterv(matrix,sendcount,disp_arr, MPI_INT, result, 8, MPI_INT, 0, MPI_COMM_WORLD);
	printf("\n");
	for(i=0;i<8;i++){
                for(j=0;j<8;j++){
                        //matrix[i][j] = i*i;
                        //result[i][j] = -1;
                        printf("%d\t", result[i][j]);
                }
                printf("\n");
        }



	MPI_Finalize();
	return 0;
}
