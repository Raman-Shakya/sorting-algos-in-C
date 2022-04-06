#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

int arr[MAX];

void print() {
    int i=0;
    for (i=0; i<MAX; i++) printf("%d ", arr[i]);
    printf("\n");
}
void printa(int*a, int*b) {
    int *i;
    for (i=a; i<=b; i++) printf("%d ", *i);
    printf("\n");
}
int compare_func(int a, int b) {
    return a<b;
}

void randomize(int* begin, int* end) {
    int* i;
    // srand(time(NULL));
    for(i=begin; i<=end; i++) {
        *i = rand()%MAX;
    }
}

int swap(int* a, int* b) {
    int temp=*a;
    *a = *b;
    *b = temp;
}

int check_sorted(int* a, int* b) {
    int *i;
    for (i=a; i<b; i++) {
        if (!compare_func(*i, *(i+1)) && *i!=*(i+1)) return 0;
    }
    return 1;
}