#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void exch(int* arr, int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void quickSort(int* arr, int left, int right){
    if(left >= right) return;

    int i = left + 1;
    int pivot = arr[left];

    for(int j = left + 1; j <= right; j++){
        if(arr[j] < pivot){
            exch(arr, j, i++);            
        }
    }

    exch(arr, left, --i);

    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

long long runtime(int n){
    int* arr = (int *)malloc(n * sizeof(int));

    srand(time(NULL));
    for(int i = 0; i < n; i++) arr[i] = n - i; // we give an decreasingly sorted array as input(worst case)

    struct timeval start;
    gettimeofday(&start, NULL);
    long long init_mil = start.tv_sec*1000LL + start.tv_usec/1000;

    //func call
    quickSort(arr, 0, n - 1);

    struct timeval end;
    gettimeofday(&end, NULL);
    long long end_mil = end.tv_sec*1000LL + end.tv_usec/1000;

    free(arr);

    return end_mil - init_mil;
}
int main(){
    // int arr[] = {7, 6, 5, 4, 3, 2, 1};
    // quickSort(arr, 0, 6);
    // for(int i = 0; i < 7; i++) printf("%d ", arr[i]);

    int n1 = 3200;
    int n2 = 6400;

    long long time1 = runtime(n1);
    long long time2 = runtime(n2);

    printf("%lf", time2 * 1.0 / time1);

    /*
        based on the output we can conclude that worst case of quickSort gives o(n^2) runtime complexity
    */
    return 0;
}