#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <unistdio.h>
void handler(int sig_no) { write(1, "Ctrl + C\n", 9); }

int main() {
  struct sigaction sa;
  sa.sa_handler = handler;
  sa.sa_flags = 0;
  sigemptyset(&sa.sa_mask);
  sigaction(SIGINT, &sa, NULL);
  if (sleep(2000) == 0) {
    printf("Sleep sucessfully \n");
  } else {
    if (errno == EINTR) {
      printf("ErrorSleep interruped \n");
    }
  }
}
