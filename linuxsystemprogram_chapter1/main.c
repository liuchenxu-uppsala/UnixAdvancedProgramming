
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int main(void) {
  char *fifo_path = "/tmp/test_fifo";
  mkfifo(fifo_path, 0666);
  int fd = open(fifo_path, O_WRONLY);
  write(fd, "Hello-fifo", 10);
  close(fd);
  getchar();
  return 0;
}
