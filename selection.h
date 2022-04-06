#pragma once
#include "global.h"


void selection_sort(int* begin, int* end, int (*func)(int, int)) {
    int *a, *b;
    for (a=begin; a<=end; a++) {
        for (b=a+1; b<=end; b++) {
            if (!func(*a,*b)) swap(a,b);
        }
    }
}