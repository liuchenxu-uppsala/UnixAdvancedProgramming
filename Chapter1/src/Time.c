//
// Created by Chenx on 2025/12/5.
#include <stdio.h>
#include <unistd.h>
#include <sys/times.h>
#include <sys/resource.h>
#include <time.h>

#ifdef _SC_CLK_TCK
#define HZ sysconf(_SC_CLK_TCK)
#else
#define HZ 100
#endif

void heavy_work() {
    volatile long result = 0;
    for (long i = 0; i < 500000000; i++) {
        result++;
    }
}

int main() {
    struct tms start_time;
    struct tms end_time;
    struct rusage usage;
    times(&start_time);
    heavy_work();
    times(&end_time);
    getrusage(RUSAGE_SELF,&usage);
    long clk_tck = HZ;
    double time_used = (end_time.tms_utime-start_time.tms_utime) / (double)clk_tck + (end_time.tms_stime-start_time.tms_stime) / (double)clk_tck;
    printf("time_used:%fd\n",time_used);

    long time_used2 = usage.ru_utime.tv_usec + usage.ru_stime.tv_usec;
    printf("time_used:%ld\n",time_used2 / 1000);
}
