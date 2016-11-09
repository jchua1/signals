#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

static void sighandler(int signo) {
  if (signo == SIGINT) {
    int f = open("file", O_CREAT|O_WRONLY|O_APPEND, 0644);
    char b[] = "Program exited due to SIGINT";
    write(f, b, sizeof(b));
    close(f);
    exit(EXIT_SUCCESS);
  }
  if (signo == SIGUSR1) {
    printf("PPID: %d\n", getppid());
  }
}

int main() {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while (1) {
    kill(getpid(), SIGUSR1);
    printf("PID: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
