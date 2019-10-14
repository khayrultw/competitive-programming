#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
 
int main (int argc, char * argv[])
{
    int rank; // my rank
    int numProcessors; // total processors running
    int myNum; // processor's assigned number
    int evenRank; // even nodes
    int oddRank; // odd nodes
    int localNum; // number your process is assigned
     
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
    MPI_Comm_size(MPI_COMM_WORLD, &numProcessors);
     
    int myArray[numProcessors]; // holds the final sorted answer
     
    if(rank > 0)
    {
        MPI_Recv(&myNum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
     
    if(rank == 0) // if root node (it has the responsibility of reading the file and delegating work)
    {
        std::ifstream myInf;
        myInf.open(argv[argc-1]); // get the file name from command line and open it
 
        std::cout << "The Unsorted Array Is: \n" << std::endl;
        myInf >> myNum;
        std::cout << myNum << std::endl;
         
        for (int i = 1; i < numProcessors; i++) // for all the numbers in the file
        {
            myInf >> localNum; // read a num from the file
            std::cout << localNum << std::endl;
            MPI_Send(&localNum, 1, MPI_INT, i, 0, MPI_COMM_WORLD); // broadcast the number to its assigned processor i
        }
         
        localNum = NULL;    
    }
     
    if (rank %2 == 0)
    {
        oddRank = rank + 1;
        evenRank = rank - 1;
    }
    else
    {
        oddRank = rank - 1;
        evenRank = rank + 1;
    }
     
    if ((oddRank == -1) || (oddRank==numProcessors))
        oddRank = rank;
    if ((evenRank == -1) || (evenRank == numProcessors))
        evenRank = rank;    
         
    // begin the main sorting loop          
    for (int i = 0; i<numProcessors; i++)
    {
        if (i %2 == 0)
        {
            MPI_Sendrecv(&myNum, 1, MPI_INT, evenRank, 8, &localNum, 1, MPI_INT , evenRank, 8, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        else
        {
            MPI_Sendrecv(&myNum, 1, MPI_INT, oddRank, 9, &localNum, 1, MPI_INT, oddRank, 9, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
         
        if (i %2 == 0) // even
        {
            if (rank %2 == 0 && localNum > myNum) // check if swap is needed
                myNum = localNum; // do the swap
            if (rank %2 == 1 && localNum < myNum) // check if swap is needed
                myNum=localNum; // do the swap
                 
            MPI_Barrier(MPI_Comm MPI_COMM_WORLD); // wait for evens to all finish
        }
         
        else // odd
        {
            if (rank %2 == 0 && localNum < myNum) // check if swap is needed
                myNum = localNum; // do the swap
            if (rank %2 == 1 && localNum > myNum) // check if swap is needed
                myNum=localNum; // do the swap
                 
            MPI_Barrier(MPI_Comm MPI_COMM_WORLD); // wait for odds to finish    
        }
         
        MPI_Barrier(MPI_Comm MPI_COMM_WORLD); // wait for the nodes to finish processing before gathering   
    }
     
    if (rank > 0)
        MPI_Send(&myNum, 1, MPI_INT, 0, 5, MPI_COMM_WORLD);
     
    // have rank 0 gather the results       
    else if(rank == 0)
    {
        myArray[0] = myNum;
        for (int i = 1; i < numProcessors; i++) // start at 1 because [0] set above
        {
            MPI_Recv(&myArray[i], 1, MPI_INT, i, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE); // get all the node's numbers
        }
         
        // output the results
        std::cout << "The Sorted Array Is: \n" << std::endl;
        for (int i = 0; i < numProcessors; i++)
                std::cout << myArray[i] << std::endl;
    }   
     
    MPI_Finalize();
     
    return 0;
}