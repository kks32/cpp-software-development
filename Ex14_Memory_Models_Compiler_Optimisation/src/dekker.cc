// Dekker's algorithm, implemented on pthreads
// http://jakob.engbloms.se/wp-content/uploads/2008/01/dekker.c

#include <assert.h>
#include <pthread.h>
#include <cstdio>
#include <cstdlib>

#define PRINT_PROGRESS

static volatile int flag1 = 0;
static volatile int flag2 = 0;
static volatile int turn = 1;
static volatile int gSharedCounter = 0;
int gLoopCount;
int gOnePercent;

void dekker1() {
  flag1 = 1;
  turn = 2;
  while ((flag2 == 1) && (turn == 2));
  // Critical section
  gSharedCounter++;
  // Let the other task run
  flag1 = 0;
}

void dekker2(void) {
  flag2 = 1;
  turn = 1;
  while ((flag1 == 1) && (turn == 1));
  // critical section
  gSharedCounter++;
  // leave critical section
  flag2 = 0;
}

//
// Tasks, as a level of indirection
//
void* task1(void* arg) {
  int i, j;
  printf("Starting task1\n");
// Do the dekker very many times
#ifdef PRINT_PROGRESS
  for (i = 0; i < 100; i++) {
    printf("[One] at %d%%\n", i);
    for (j = gOnePercent; j > 0; j--) {
      dekker1();
    }
  }
#else
  // Simple basic loop
  for (i = gLoopCount; i > 0; i--) {
    dekker1();
  }
#endif
}

void* task2(void* arg) {
  int i, j;
  printf("Starting task2\n");
#ifdef PRINT_PROGRESS
  for (i = 0; i < 100; i++) {
    printf("[Two] at %d%%\n", i);
    for (j = gOnePercent; j > 0; j--) {
      dekker2();
    }
  }
#else
  for (i = gLoopCount; i > 0; i--) {
    dekker2();
  }
#endif
}

int main(int argc, char** argv) {
  int loopCount = 0;
  pthread_t dekker_thread_1;
  pthread_t dekker_thread_2;
  void* returnCode;
  int result;
  int expected_sum;

  /* Check arguments to program*/
  if (argc != 2) {
    fprintf(stderr, "USAGE: %s <loopcount>\n", argv[0]);
    exit(1);
  }

  /* Parse argument */
  loopCount = atoi(argv[1]); /* Don't bother with format checking */
  gLoopCount = loopCount;
  gOnePercent = loopCount / 100;
  expected_sum = 2 * loopCount;

  /* Start the threads */
  result = pthread_create(&dekker_thread_1, NULL, task1, NULL);
  result = pthread_create(&dekker_thread_2, NULL, task2, NULL);

  /* Wait for the threads to end */
  result = pthread_join(dekker_thread_1, &returnCode);
  result = pthread_join(dekker_thread_2, &returnCode);
  printf("Both threads terminated\n");

  /* Check result */
  if (gSharedCounter != expected_sum) {
    printf("[-] Dekker did not work, sum %d rather than %d.\n", gSharedCounter,
           expected_sum);
    printf(" %d missed updates due to memory consistency races.\n",
           (expected_sum - gSharedCounter));
    return 1;
  } else {
    printf("[+] Dekker worked.\n");
    return 0;
  }
}
