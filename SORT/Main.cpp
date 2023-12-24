#include <stdio.h>
#include <malloc.h>
#include "Sort.h"
#include "Test.h"
#include <omp.h>
int main() {
  int sort, test, num;
    printf(" Menu: \n1. Bubble sort \n2. Select sort\n3. Insert sort\n4. Merge sort\n5. Quick sort\n6. Counting sort\n7. Radix sort\n");
    scanf_s("%d", &sort);
   printf("Choose a testing option: \n 1. An array of random numbers \n 2. Partially sorted array \n 3. Sorted array with permutations of two random elements \n 4. The array is sorted in reverse order \n");
    scanf_s("%d", &test);
    printf("Select the number of items:");
    scanf_s("%d", &num);
    int* arr = (int*)malloc(num * sizeof(int));
    switch (test) {
    case 1:
        arr = RandomArr(num, arr);
        break;
    case 2:
        arr = PartiallySorted(num, arr);
        break;
    case 3:
        arr = SwapArr(num, arr);
        break;
    case 4:
       arr = ReverseArr(num, arr);
       break;
    }
     double start;
     double end;
    switch (sort)
    {
    case 1:      
        start = omp_get_wtime();
        BubbleSort(arr, num);
        end = omp_get_wtime();
        printf("Work took %f seconds\n", end - start);
        break;
    case 2:
        start = omp_get_wtime();
        SelectSort(arr, num);
        end = omp_get_wtime();
        printf("Work took %f seconds\n", end - start);
        break;
    case 3:
        start = omp_get_wtime();
        InsertSort(arr, num);
        end = omp_get_wtime();
        printf("Work took %f seconds\n", end - start);
        break;
    case 4:
        start = omp_get_wtime();
        MergeSort(arr, 0, num - 1);
        end = omp_get_wtime();
        printf("Work took %f seconds\n", end - start);
        break;
    case 5:
        start = omp_get_wtime();
        QuickSort(arr, 0, num - 1);
        end = omp_get_wtime();
        printf("Work took %f seconds\n", end - start);
        break;
    case 6:
        int max;
        start = omp_get_wtime();
        max = MaxElement(arr, num);
        CountingSort(arr, num, max);
        end = omp_get_wtime();
        printf("Work took %f seconds\n", end - start);
        break;
   case 7:
       start = omp_get_wtime();
        RadixSort(arr, num);
        end = omp_get_wtime();
        printf("Work took %f seconds\n", end - start);
        break;
    }
}

      

