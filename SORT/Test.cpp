#include <stdio.h>
#include <stdlib.h> 
#include "Test.h"
#include "Sort.h"
int* RandomArr(int num, int*arr) {
    for (int i = 0; i < num; i++) {
        arr[i] = rand();
       
    }
    return arr;
}
int* ReverseArr(int num, int*arr) {
    arr[num-1] = rand();
    for (int i = num-2; i >=0; i--) {
        arr[i] = arr[i+1]+rand();
    }
    return arr;
}
int* PartiallySorted(int num, int* arr) {
    arr[0] = rand();
    for (int i = 1; i <= (num - 1) / 4; i++)   arr[i] = arr[i - 1] + rand();
     arr[1 + (num - 1) / 4] = rand();
    for (int i = 2 + (num - 1) / 4; i <= (num - 1) / 2; i++)  arr[i] = arr[i - 1] + rand();
    arr[1 + (num - 1) / 2] = rand();
    for (int i = 2 + (num - 1) / 2; i <= 3 * (num - 1) / 4; i++)  arr[i] = arr[i - 1] + rand();
    arr[1 + 3 * (num - 1) / 4] = rand();
    for (int i = 2 + 3 * (num - 1) / 4; i < num; i++) arr[i] = arr[i - 1] + rand();
    return arr;
}
int* SwapArr(int num, int* arr) {
    arr[0] = rand();
    for (int i = 1; i < num; i++) arr[i] = arr[i - 1] + rand();
    if (num>=10) {
        int permutation = rand() % (num / 10);
        int q1, q2;
        for (int i = 1; i <= permutation; i++) {
            q1 = rand() % (num - 1);
            q2 = rand() % (num - 1);
            swap(&arr[q1], &arr[q2]);
        }
    }  
    return arr;
}