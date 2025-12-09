//
// Created by Chenx on 2025/12/9.
//
#include <stdio.h>
#include <unistd.h>
#include <sys/times.h>
#include <sys/resource.h>
// _SC_CLK_TCK

#ifdef _SC_CLK_TCK
#define HZ sysconf(_SC_CLK_TCK)
#else
#define HZ 100
#endif



void heavy_work() {
    long sum = 0;
    for (int i = 0; i < 500000000; ++i) {
        sum++;
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
    double time_used = (end_time.tms_utime - start_time.tms_utime)/(double)HZ + (end_time.tms_stime - start_time.tms_stime)/(double)HZ;
    printf("times:%fd\n",time_used);

    printf("getrusage:%ld\n",usage.ru_stime.tv_usec + usage.ru_utime.tv_usec);
}