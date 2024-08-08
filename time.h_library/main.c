// #include <stdio.h>
// #include <time.h>

// int main() {
//     clock_t start_time, end_time;
//     double cpu_time_used;

//     // Record the start time
//     start_time = clock();

//     // Place your code to measure execution time here 
//     // For example, let's simulate some computation
//     int sum = 0;
//     for (int i = 1; i <= 1000000; ++i) {
//         sum += i;
//     }

//     // Record the end time
//     end_time = clock();

//     // Calculate the CPU time used in seconds
//     cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

//     printf("Sum: %d\n", sum);
//     printf("CPU Time Used: %f seconds\n", cpu_time_used);

//     return 0;
// }

#include<stdio.h>
#include<sys/resource.h>
#include<stdlib.h>
int main() {
// Record the start memory usage
struct rusage usage_start;
getrusage(RUSAGE_SELF, &usage_start);


// Place your code to measure memory usage here
// For example, let's allocate some memory
int array[1000000];

// Record the end memory usage
struct rusage usage_end;
getrusage(RUSAGE_SELF, &usage_end);


// Calculate memory usage in kilobytes
long memory_used = usage_end.ru_maxrss - usage_start.ru_maxrss;


printf("Memory Used: %ld KB\n", memory_used);


// Free the allocated memory

return 0;
}

