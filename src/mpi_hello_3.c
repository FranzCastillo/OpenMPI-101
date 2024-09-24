#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    // Start up MPI
    MPI_Init(&argc, &argv);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int recv_rank = 0;  // Process that will receive the message

    if (world_rank == recv_rank) {
        printf("Hi, I'm process %d of %d and I'm receiving messages!\n", world_rank, world_size);
        // Process 0 receives messages from all other processes
        for (int i = 1; i < world_size; i++) {
            char message[100];
            MPI_Recv(message, 100, MPI_CHAR, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("\tProcess %d received from %d: %s\n", world_rank, i, message);

            // Prepare the message
            char response[100];
            sprintf(response, "Acknowledged, process %d!", i);
            MPI_Send(response, strlen(response) + 1, MPI_CHAR, i, 0, MPI_COMM_WORLD);
        }
    } else {
        printf("Hi, I'm process %d of %d and I'm sending a message to %d!\n", world_rank, world_size, recv_rank);

        // Prepare the message
        char message[100];
        sprintf(message, "Greetings process %d, I'm process %d of %d!", recv_rank, world_rank, world_size);

        // Send the message
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, recv_rank, 0, MPI_COMM_WORLD);

        // Receive the response
        char response[100];
        MPI_Recv(response, 100, MPI_CHAR, recv_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("\tProcess %d received response from process %d: %s\n", world_rank, recv_rank, response);
    }

    // Finalizar el entorno MPI
    MPI_Finalize();

    return 0;
}