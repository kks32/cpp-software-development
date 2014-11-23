#include <omp.h>

#include <cstdio>
#include <cstdlib>

#include <iostream>

int main(int argc, char** argv) {

  int N;
  if (argc != 2) {
    std::cerr << "Incorrect arguments: usage ./array ARRAY_SIZE" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  else {
    N = atoi (argv[1]);
  }

  int nthreads, tid, i, chunk;
  chunk = 10;

  float a[N], b[N], c[N];

  /* Some initializations */
  for (i = 0; i < N; i++) a[i] = b[i] = i * 1.0;

#pragma omp parallel shared(a, b, c, nthreads, chunk) private(i, tid)
  {
    tid = omp_get_thread_num();
    if (tid == 0) {
      nthreads = omp_get_num_threads();
      printf("Number of threads = %d\n", nthreads);
    }
    printf("Thread %d starting...\n", tid);

#pragma omp for schedule(dynamic, chunk) // change to static and see what happens
    for (i = 0; i < N; i++) {
      c[i] = a[i] + b[i];
      printf("Thread %d: c[%d]= %f\n", tid, i, c[i]);
    }

  } /* end of parallel section */
}
