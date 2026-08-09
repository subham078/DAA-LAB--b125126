#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge2(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // Using malloc instead of Variable Length Arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    
    free(L);
    free(R);
}

void mergeSort2(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort2(arr, l, m);
        mergeSort2(arr, m + 1, r);
        merge2(arr, l, m, r);
    }
}

void merge3(int arr[], int l, int m1, int m2, int r) {
    int n1 = m1 - l + 1;
    int n2 = m2 - m1;
    int n3 = r - m2;
    
    // Using malloc instead of Variable Length Arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *M = (int *)malloc(n2 * sizeof(int));
    int *R = (int *)malloc(n3 * sizeof(int));
    
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) M[i] = arr[m1 + 1 + i];
    for (int i = 0; i < n3; i++) R[i] = arr[m2 + 1 + i];
    
    int i = 0, j = 0, k = 0, p = l;
    while (i < n1 && j < n2 && k < n3) {
        if (L[i] <= M[j] && L[i] <= R[k]) arr[p++] = L[i++];
        else if (M[j] <= L[i] && M[j] <= R[k]) arr[p++] = M[j++];
        else arr[p++] = R[k++];
    }
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) arr[p++] = L[i++];
        else arr[p++] = M[j++];
    }
    while (j < n2 && k < n3) {
        if (M[j] <= R[k]) arr[p++] = M[j++];
        else arr[p++] = R[k++];
    }
    while (i < n1 && k < n3) {
        if (L[i] <= R[k]) arr[p++] = L[i++];
        else arr[p++] = R[k++];
    }
    while (i < n1) arr[p++] = L[i++];
    while (j < n2) arr[p++] = M[j++];
    while (k < n3) arr[p++] = R[k++];
    
    free(L);
    free(M);
    free(R);
}

void mergeSort3(int arr[], int l, int r) {
    if (l < r) {
        int m1 = l + (r - l) / 3;
        int m2 = l + 2 * (r - l) / 3;
        mergeSort3(arr, l, m1);
        mergeSort3(arr, m1 + 1, m2);
        mergeSort3(arr, m2 + 1, r);
        merge3(arr, l, m1, m2, r);
    }
}

int main() {
    FILE *fp = fopen("q2_data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    srand(time(NULL));
    
    for (int n = 10000; n <= 100000; n += 10000) {
        int *arr1 = (int *)malloc(n * sizeof(int));
        int *arr2 = (int *)malloc(n * sizeof(int));
        
        for (int i = 0; i < n; i++) {
            arr1[i] = arr2[i] = rand() % n;
        }
        
        clock_t start = clock();
        mergeSort2(arr1, 0, n - 1);
        clock_t end = clock();
        double time2 = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        start = clock();
        mergeSort3(arr2, 0, n - 1);
        end = clock();
        double time3 = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        fprintf(fp, "%d %f %f\n", n, time2, time3);
        free(arr1); 
        free(arr2);
    }
    fclose(fp);
    printf("Data generated successfully in q2_data.txt\n");
    return 0;
}