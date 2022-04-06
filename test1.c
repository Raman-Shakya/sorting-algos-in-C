#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "global.h"
#include "selection.h"
#include "merge_sort.h"
#include "quick.h"


int main() {
    struct timespec start, end;
    int i;
    randomize(arr, &arr[MAX]);
    print();
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    // main work starts here
        quick_sort(arr,&arr[MAX-1], compare_func);
    // main work ends here

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    int64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

    // printing arr and time
    for (i=0; i<MAX; i++) printf("%d ", arr[i]);
    printf("\n %ldms \n", delta_us);
    printf(" %d\n", check_sorted(arr,&arr[MAX-1]));
    return 0;
}

