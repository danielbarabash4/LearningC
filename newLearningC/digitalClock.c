#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

// works for mac/linux

int main() {
  time_t rawtime = 0;
  struct tm* pTime = NULL;
  bool isRunning = true;
  int num = 0;

  printf("DIGITAL CLOCK\n");

  while (isRunning) {
    time(&rawtime);

    pTime = localtime(&rawtime);

    printf( "\r%02d:%02d:%02d" ,pTime->tm_hour, pTime->tm_min,pTime->tm_sec);
    fflush(stdout);

    sleep(1);
  }

  return 0;
}