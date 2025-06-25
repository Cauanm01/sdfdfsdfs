#include "kernel/types.h"
#include "user/user.h"

#define N 4

int child[N];
  int tickets[] = {1, 2, 4, 1000};

void waste_time(){
  volatile unsigned long long i;
  for (i = 0; i < 10000000000ULL; ++i);
}

int main(int argc, char *argv[])
{
  int n, pid;
  int start_time, end_time;

  for(n = 0; n < N; n++){
    pid = fork();
    if(pid == 0) {
      start_time = uptime();

      settickets(getpid(), 3-n);
      

      waste_time(); 

      end_time = uptime();
      
      printf("Processo filho PID %d executou por %d ticks\n", getpid(), end_time - start_time);

      exit(0);
    } else {
      child[n] = pid;
    }
  }

  for(n = 0; n < N; n++){
    pid = wait(0);
    printf("Processo filho PID %d finalizado\n", pid);
  }

  return 0;
}
