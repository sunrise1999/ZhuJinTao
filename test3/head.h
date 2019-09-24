#ifndef TEST3_HEAD_H
#define TEST3_HEAD_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>
#include <stdbool.h>
#include <unistd.h> 
int urand(int n);
int usum(int *a,int n);
void BubbleSort(int a[], int n);
void swap(int *a, int *b);
int Partition(int a[], int low, int high);
void QuickSort(int a[], int low, int high); 
int  getMyTime(int *a,int n);

struct thisArg {
    double ave;
    long int sum;
    int max;
    int min;
};

struct thisArg operator(int *a,int n);
#endif //TEST3_HEAD_H
