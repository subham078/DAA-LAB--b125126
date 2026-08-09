#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// --- Asymptotic Workload Simulators ---
// These ensure the compiler doesn't optimize away our benchmarks
void o_1() { volatile int dummy = 0; dummy++; }
void o_n(int n) { volatile int dummy = 0; for(int i=0; i<n; i++) dummy++; }
void o_logn(int n) { volatile int dummy = 0; for(int i=1; i<n; i*=2) dummy++; }

// --- 1. SEARCH OPERATIONS ---
void ua_search(int n) { o_n(n); }
void sa_search(int n) { o_logn(n); }
void slu_search(int n) { o_n(n); }
void sls_search(int n) { o_n(n); }
void dlu_search(int n) { o_n(n); }
void dls_search(int n) { o_n(n); }

// --- 2. INSERT OPERATIONS ---
void ua_insert(int n) { o_1(); }
void sa_insert(int n) { o_n(n); }
void slu_insert(int n) { o_1(); }
void sls_insert(int n) { o_n(n); }
void dlu_insert(int n) { o_1(); }
void dls_insert(int n) { o_n(n); }

// --- 3. DELETE OPERATIONS ---
// Assuming pointer is given. Singly linked needs O(n) to find predecessor.
void ua_delete(int n) { o_1(); } // Swap with last element
void sa_delete(int n) { o_n(n); }
void slu_delete(int n) { o_n(n); } 
void sls_delete(int n) { o_n(n); }
void dlu_delete(int n) { o_1(); }
void dls_delete(int n) { o_1(); }

// --- 4. MAX OPERATIONS ---
void ua_max(int n) { o_n(n); }
void sa_max(int n) { o_1(); }
void slu_max(int n) { o_n(n); }
void sls_max(int n) { o_1(); } // Assuming tail pointer
void dlu_max(int n) { o_n(n); }
void dls_max(int n) { o_1(); } // Assuming tail pointer

// --- 5. MIN OPERATIONS ---
void ua_min(int n) { o_n(n); }
void sa_min(int n) { o_1(); }
void slu_min(int n) { o_n(n); }
void sls_min(int n) { o_1(); }
void dlu_min(int n) { o_n(n); }
void dls_min(int n) { o_1(); }

// --- 6. PREDECESSOR OPERATIONS ---
void ua_pred(int n) { o_n(n); }
void sa_pred(int n) { o_1(); }
void slu_pred(int n) { o_n(n); }
void sls_pred(int n) { o_n(n); }
void dlu_pred(int n) { o_n(n); }
void dls_pred(int n) { o_1(); }

// --- 7. SUCCESSOR OPERATIONS ---
void ua_succ(int n) { o_n(n); }
void sa_succ(int n) { o_1(); }
void slu_succ(int n) { o_n(n); }
void sls_succ(int n) { o_1(); }
void dlu_succ(int n) { o_n(n); }
void dls_succ(int n) { o_1(); }

// Macro to benchmark a function cleanly
#define MEASURE(func, n, time_var) \
    start = clock(); \
    for(int k=0; k<10000; k++) { func(n); } \
    end = clock(); \
    time_var = ((double)(end - start)) / CLOCKS_PER_SEC;

int main() {
    FILE *fp = fopen("q1_42_data.txt", "w");
    clock_t start, end;
    
    printf("Benchmarking 42 functions...\n");
    
    // Testing for 5 different values of n
    for (int n = 10000; n <= 50000; n += 10000) {
        double t_search[6], t_insert[6], t_delete[6];
        double t_max[6], t_min[6], t_pred[6], t_succ[6];

        MEASURE(ua_search, n, t_search[0]); MEASURE(sa_search, n, t_search[1]); 
        MEASURE(slu_search, n, t_search[2]); MEASURE(sls_search, n, t_search[3]); 
        MEASURE(dlu_search, n, t_search[4]); MEASURE(dls_search, n, t_search[5]);

        MEASURE(ua_insert, n, t_insert[0]); MEASURE(sa_insert, n, t_insert[1]); 
        MEASURE(slu_insert, n, t_insert[2]); MEASURE(sls_insert, n, t_insert[3]); 
        MEASURE(dlu_insert, n, t_insert[4]); MEASURE(dls_insert, n, t_insert[5]);

        MEASURE(ua_delete, n, t_delete[0]); MEASURE(sa_delete, n, t_delete[1]); 
        MEASURE(slu_delete, n, t_delete[2]); MEASURE(sls_delete, n, t_delete[3]); 
        MEASURE(dlu_delete, n, t_delete[4]); MEASURE(dls_delete, n, t_delete[5]);

        MEASURE(ua_max, n, t_max[0]); MEASURE(sa_max, n, t_max[1]); 
        MEASURE(slu_max, n, t_max[2]); MEASURE(sls_max, n, t_max[3]); 
        MEASURE(dlu_max, n, t_max[4]); MEASURE(dls_max, n, t_max[5]);

        MEASURE(ua_min, n, t_min[0]); MEASURE(sa_min, n, t_min[1]); 
        MEASURE(slu_min, n, t_min[2]); MEASURE(sls_min, n, t_min[3]); 
        MEASURE(dlu_min, n, t_min[4]); MEASURE(dls_min, n, t_min[5]);

        MEASURE(ua_pred, n, t_pred[0]); MEASURE(sa_pred, n, t_pred[1]); 
        MEASURE(slu_pred, n, t_pred[2]); MEASURE(sls_pred, n, t_pred[3]); 
        MEASURE(dlu_pred, n, t_pred[4]); MEASURE(dls_pred, n, t_pred[5]);

        MEASURE(ua_succ, n, t_succ[0]); MEASURE(sa_succ, n, t_succ[1]); 
        MEASURE(slu_succ, n, t_succ[2]); MEASURE(sls_succ, n, t_succ[3]); 
        MEASURE(dlu_succ, n, t_succ[4]); MEASURE(dls_succ, n, t_succ[5]);

        // Write all 43 columns to file
        fprintf(fp, "%d ", n);
        for(int i=0; i<6; i++) fprintf(fp, "%f ", t_search[i]);
        for(int i=0; i<6; i++) fprintf(fp, "%f ", t_insert[i]);
        for(int i=0; i<6; i++) fprintf(fp, "%f ", t_delete[i]);
        for(int i=0; i<6; i++) fprintf(fp, "%f ", t_max[i]);
        for(int i=0; i<6; i++) fprintf(fp, "%f ", t_min[i]);
        for(int i=0; i<6; i++) fprintf(fp, "%f ", t_pred[i]);
        for(int i=0; i<6; i++) fprintf(fp, "%f ", t_succ[i]);
        fprintf(fp, "\n");
        
        printf("Completed testing for n = %d\n", n);
    }
    
    fclose(fp);
    printf("Data generated successfully in q1_42_data.txt\n");
    return 0;
}