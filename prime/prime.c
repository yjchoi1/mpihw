/****************************************************************
 ****
 **** This program file is part of the book 
 **** `Parallel programming for Science and Engineering'
 **** by Victor Eijkhout, eijkhout@tacc.utexas.edu
 ****
 **** copyright Victor Eijkhout 2012-8
 ****
 **** MPI Exercise for prime number factorization. So to speak.
 ****
 ****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

int main(int argc,char **argv) {
  
  MPI_Init(&argc,&argv);
  MPI_Comm comm = MPI_COMM_WORLD;

  int nprocs, procno;
  MPI_Comm_size(comm,&nprocs);
  MPI_Comm_rank(comm,&procno);

  int bignum = 2000000111, maxfactor = 45200;
  // Exercise:
  // -- Parallelize the do loop so that each processor
  //    tries different candidate numbers.
  // -- If a processors finds a factor, print it to the screen.

  // 1. Set loop bounds
  int interval;
  interval = maxfactor/nprocs;
  int lower_bound_for_procno, upper_bound_for_procno;
  lower_bound_for_procno = (procno) * interval + 1;
  upper_bound_for_procno = (procno + 1) * interval;
  printf("Procno %d search primes of %d for range [%d, %d] \n", procno, bignum, lower_bound_for_procno, upper_bound_for_procno);
/**** your code here ****/
  // 2. Fill in loop header
  for ( int myfactor =
/**** your code here ****/
        lower_bound_for_procno; myfactor < upper_bound_for_procno; ++myfactor
       ) {
    if (bignum%myfactor==0) {
      printf("  Processor %d found factor %d\n",procno,myfactor);
    }
  }

  
  MPI_Finalize();
  return 0;
}
