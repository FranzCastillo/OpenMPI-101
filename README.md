# OpenMPI 101
 
## How to run?
1. Build the Docker Container
```bash
docker-compose up --build
```

2. Run the Docker Container
```bash
docker-compose run development /bin/bash
```

3. Compile the MPI Program
```bash
mpirun --allow-run-as-root -np 4 ./hello_1
```
We allow the program to run as root because we are running the program inside a Docker container.

4. Run the MPI Program
```bash
mpirun -np 4 ./hello_1
```

