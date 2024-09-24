# OpenMPI 101
 
## How to run?

1. Run the Docker Container
```bash
docker-compose run --build --rm -it development
```

2. Compile the MPI Program
```bash
mpicc -o hello_<i> mpi_hello_<i>.c
```

3. Run the MPI Program
```bash
mpirun --allow-run-as-root -np 4 ./hello_1
```
We allow the program to run as root because we are running the program inside a Docker container.


