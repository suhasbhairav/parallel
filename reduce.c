#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int i;
	int sendbuffer[10]; int recvbuffer[10];
	/*Every process will have a send & recv buffer*/
	printf("Send buffer:\n");
	for(i=0;i<10;i++){
		sendbuffer[i]=1;
		printf("%d:%d\n",i,sendbuffer[i]);
	}
	
	MPI_Reduce(&sendbuffer, recvbuffer, 10, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	printf("Receive buffer\n");
	
	if(rank == 0){
		for(i=0;i<10;i++){
			printf("%d:%d\n",i,recvbuffer[i]);
		}
	}




	MPI_Finalize();
	return 0;
}
