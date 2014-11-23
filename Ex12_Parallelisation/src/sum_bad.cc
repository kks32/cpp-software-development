#include <omp.h>

#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv[]) {
  int i, n, chunk;
  float a[100], b[100], sum;
  chunk = 10;
  /* Some initializations */
  n = 100;
  for (i = 0; i < n; i++)
    a[i] = b[i] = 1.0;
  sum = 0.0;

#pragma omp parallel for default(shared) private(i) schedule(dynamic, chunk)
  for (i = 0; i < n; i++) 
    sum += (a[i] * b[i]);

  printf("Sum = %f\n", sum);
}
