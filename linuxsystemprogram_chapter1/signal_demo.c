#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void signal_handle(int sig_no) { write(1, "Ctrl+C clicked\n", 17); }

int main() {
  signal(SIGINT, signal_handle);
  while (1) {
    sleep(1);
  }
  return 0;
}
