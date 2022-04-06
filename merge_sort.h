#pragma once
#include "global.h"

void merge(int *b, int *mid,  int *e, int (*func)(int, int)) {
    int temp_arr[e-b];
    int *p1=b, *p2=mid, *solved = temp_arr;
    while (p1<mid || p2<=e) {
        if (p1<mid && (p2>e || func(*p1, *p2))) {
            *solved = *p1++;
        }
        else if (p2<=e) {
            *solved = *p2++;
        }
        else break;
        solved++;
    }
    int i;
    for (i=0; i<=e-b; i++) {
        b[i] = temp_arr[i];
    }
}

void merge_sort(int *ar_s, int *ar_e, int (*func)(int, int)) {
    if (ar_e == ar_s ) return;
    int len_2 = (ar_e - ar_s) >> 1;
    merge_sort(ar_s,   ar_s + len_2, func);
    merge_sort(ar_s + len_2+1, ar_e, func);
    merge(ar_s, ar_s+len_2+1,  ar_e, func);
}