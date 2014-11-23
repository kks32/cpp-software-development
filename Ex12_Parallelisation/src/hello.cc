#include <omp.h>
#include <iostream>

int main(int argc, char* argv[]) {
  int nthreads, tid;

// Fork a team of threads giving them their own copies of variables
  std::cout << std::endl;
#pragma omp parallel private(nthreads, tid)
  {
    // Obtain thread number
    tid = omp_get_thread_num();
    std::cout << "Hello World from thread = " << tid << std::endl;

    // Only master thread does this
    if (tid == 0) {
      nthreads = omp_get_num_threads();
      std::cout << "Number of threads = " << nthreads << std::endl;
    }

  }  // All threads join master thread and disband
}
