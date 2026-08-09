#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Helper function to merge two sorted arrays into a new array
int* merge_two_arrays(int* arr1, int size1, int* arr2, int size2) {
    int* result = (int*)malloc((size1 + size2) * sizeof(int));
    int i = 0, j = 0, k = 0;
    
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    while (i < size1) result[k++] = arr1[i++];
    while (j < size2) result[k++] = arr2[j++];
    
    return result;
}

// Method 1: Iterative Merge O(k^2 * n)
void method1(int** arrays, int k, int n) {
    // Start with the first array
    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) result[i] = arrays[0][i];
    int current_size = n;
    
    // Iteratively merge the next array into the result
    for (int i = 1; i < k; i++) {
        int* temp = merge_two_arrays(result, current_size, arrays[i], n);
        free(result); // Free the old result array
        result = temp; // Point to the new merged array
        current_size += n;
    }
    free(result);
}

// Helper for Method 2 (Recursive Divide and Conquer)
int* method2_recursive(int** arrays, int left, int right, int n, int* out_size) {
    // Base case: only one array
    if (left == right) {
        *out_size = n;
        int* res = (int*)malloc(n * sizeof(int));
        for(int i = 0; i < n; i++) res[i] = arrays[left][i];
        return res;
    }
    
    // Divide
    int mid = left + (right - left) / 2;
    int size_left = 0, size_right = 0;
    
    // Conquer
    int* left_arr = method2_recursive(arrays, left, mid, n, &size_left);
    int* right_arr = method2_recursive(arrays, mid + 1, right, n, &size_right);
    
    // Combine
    int* merged = merge_two_arrays(left_arr, size_left, right_arr, size_right);
    
    free(left_arr);
    free(right_arr);
    *out_size = size_left + size_right;
    return merged;
}

// Method 2: Divide and Conquer Merge O(k * n * log k)
void method2(int** arrays, int k, int n) {
    int final_size = 0;
    int* result = method2_recursive(arrays, 0, k - 1, n, &final_size);
    free(result);
}

int main() {
    FILE *fp = fopen("q3_data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    int n = 1000; // Fixed size for each array
    
    // Testing for 6 different values of k
    int k_values[] = {50, 100, 150, 200, 250, 300};
    int num_tests = sizeof(k_values) / sizeof(k_values[0]);
    
    printf("Benchmarking Question 3...\n");
    
    for (int t = 0; t < num_tests; t++) {
        int k = k_values[t];
        
        // Allocate k arrays of size n
        int** arrays = (int**)malloc(k * sizeof(int*));
        for (int i = 0; i < k; i++) {
            arrays[i] = (int*)malloc(n * sizeof(int));
            // Fill with sorted dummy data
            for (int j = 0; j < n; j++) {
                arrays[i][j] = j; 
            }
        }
        
        // Benchmark Method 1
        clock_t start = clock();
        method1(arrays, k, n);
        clock_t end = clock();
        double time1 = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        // Benchmark Method 2
        start = clock();
        method2(arrays, k, n);
        end = clock();
        double time2 = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        fprintf(fp, "%d %f %f\n", k, time1, time2);
        printf("Completed k=%d (Method 1: %f s, Method 2: %f s)\n", k, time1, time2);
        
        // Free memory
        for (int i = 0; i < k; i++) {
            free(arrays[i]);
        }
        free(arrays);
    }
    
    fclose(fp);
    printf("Data generated successfully in q3_data.txt\n");
    return 0;
}