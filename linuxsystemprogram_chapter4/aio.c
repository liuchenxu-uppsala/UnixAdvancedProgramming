//
// Created by Chenx on 2026/1/25.
//
#include <stdio.h>
#include <aio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>


void function_handle(sigval_t v) {
    struct aiocb* value = (struct aiocb*)v.sival_ptr;
    if (aio_error(value) == 0) {
        ssize_t ret = aio_return(value);
        printf("aio:%s\n",(char *)value->aio_buf);
        fflush(stdout);
    }
}

char buff[1024];
struct aiocb aio;

int main() {
    int fid = open("test_mmap.txt",O_RDWR);
    aio.aio_fildes = fid;
    aio.aio_offset = 0;
    aio.aio_buf = buff;
    aio.aio_nbytes = sizeof(buff);
    aio.aio_sigevent.sigev_notify = SIGEV_THREAD;
    aio.aio_sigevent.sigev_value.sival_ptr = &aio;
    // aio.aio_sigevent.sigev_value.sigev_notify_function = function_handle;
    aio.aio_sigevent.sigev_notify_function = function_handle;
    aio_read(&aio);
    sleep(3);
    close(fid);
    return 0;
}