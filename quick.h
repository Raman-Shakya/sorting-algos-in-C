#pragma once
#include "global.h"

void quick_sort(int *start, int* end, int (*func)(int, int)) {
    if (end-start<1) {
        return;
    }
    int *a=start+1, *b=end;
    int pivot=*start;
    while (a<b) {
        while (func(*a,pivot) && a<=end) a++;
        while (!func(*b,pivot) && b>start) b--;
        if (a>=b) break;
        swap(a,b);
    }
    if (func(*b,*start)) swap(start,b);
    quick_sort(start, b-1, func);
    quick_sort(b+1, end, func);
}

