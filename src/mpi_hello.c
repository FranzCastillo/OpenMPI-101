#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    // Start up MPI
    MPI_Init(&argc, &argv);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Print
    printf("Hello World, I’m process %d of %d!\n", world_rank, world_size);

    // Shut down MPI
    MPI_Finalize();

    return 0;
}