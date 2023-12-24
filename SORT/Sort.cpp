#include <stdio.h>
#include <malloc.h>
void swap (int* pa, int* pb) {
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;     
}
void BubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = (n - 1); j > i; j--) 
        {
            if (arr[j - 1] > arr[j]) 
                swap(&arr[j - 1], &arr[j]);      
        }
    }
}
void SelectSort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        int MinIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[MinIndex] > arr[j])
                MinIndex = j;
        swap(&arr[MinIndex], &arr[i]);
    }
}
void InsertSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int key = arr[i + 1];
        for (int j = i; j >= 0; j--) {
            if (key < arr[j]) swap(&arr[j], &arr[j + 1]);
        }
    }
}
void Merge(int*arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* l = (int*)malloc(n1 * sizeof(int));
    int* m = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++)
        l[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        m[j] = arr[mid + 1 + j];
    int i, j, k;
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (l[i] <= m[j])
        {
            arr[k] = l[i];
            i++;
        }
        else
        {
            arr[k] = m[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = l[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = m[j];
        j++;
        k++;
    }
}
void MergeSort(int * arr, int left, int right) {
    if (left >= right) return;
    MergeSort(arr, left, (left+right)/2);
    MergeSort(arr, 1 + (left+right)/2, right);
    Merge(arr, left, (left+right)/2, right);
}
int partition(int* arr, int left, int right) {
    int pilot, i;
    pilot = arr[right];
    i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pilot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}
void QuickSort(int* arr, int left, int right) {
    while (left < right) {
       int q = partition(arr, left, right);
        if (q - left < right - q) {
            QuickSort(arr, left, q - 1);
            left = q++;
        }
        else {
            QuickSort(arr, q + 1, right);
            right = q - 1;
        }
    }
}
int MaxElement(int* arr, int n) {
    int MaxElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > MaxElement)
            MaxElement = arr[i];
    }
    return MaxElement;
}
void CountingSort(int* arr, int n, int max) {
    int* count = (int*)malloc((max + 1) * sizeof(*arr));
    for (int i = 0; i < max+1; ++i) {
        count[i]=0;
    }
    for (int i = 0; i < n; ++i) {
        ++count[arr[i]];
    }
    int b = 0;
    for (int i = 0; i < max + 1; ++i) {
        for (int j = 0; j < count[i]; ++j) {
            arr[b++] = i;
        }
    }

    free(count);
}
void RadixSort(int *arr, int n) { 
    for (int pos = 1; pos > 0; pos *= 10)
    {
        int* res = (int*)malloc((n + 1) * sizeof(int));
        int count[10] = { 0 };

        for (int i = 0; i < n; i++)
            count[(arr[i] / pos) % 10]++;
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--) {
            res[count[(arr[i] / pos) % 10] - 1] = arr[i];
            count[(arr[i] / pos) % 10]--;
        }
        for (int i = 0; i < n; i++)
            arr[i] = res[i];
    }
}



