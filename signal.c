/*
Queenie Xiang
Systems PD4
HW10 -- Fire up the batSIGNAL
2017-11-08
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

static void sighandler(int signo) {
  int fd; 
  char * buffer = "Received SIGINT!"; 
  //If the signal received is SIGINT
  if (signo == SIGINT) {
    fd = open("input_file", O_CREAT | O_WRONLY | O_EXCL | O_APPEND, 0644);
    write(fd, buffer, sizeof(buffer) * 10);
    close(fd);
    printf("\nProgram has exited due to SIGINT\n");
    exit(1); 
  }

  //If the signal received is SIGUSR1
  if (signo == SIGUSR1) {
    printf("\nSIGUSR1 received! Parent PID:");
    printf("%d\n\n", getppid()); 
  }
    
}
  

int main() {
  while(1) {
    int PID = getpid();
    printf("PID: %d\n", PID);
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    sleep(1);
  }
}
  
    
