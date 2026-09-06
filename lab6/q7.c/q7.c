//q.7.Convolution of Two Vectors

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define PI acos(-1.0)

void fft(double complex a[], int n, int invert)
{
    if (n == 1)
        return;

    double complex even[n / 2];
    double complex odd[n / 2];

    for (int i = 0; i < n / 2; i++)
    {
        even[i] = a[2 * i];
        odd[i] = a[2 * i + 1];
    }

    fft(even, n / 2, invert);
    fft(odd, n / 2, invert);

    for (int k = 0; k < n / 2; k++)
    {
        double angle = 2 * PI * k / n;

        if (invert)
            angle = -angle;

        double complex w = cos(angle) + I * sin(angle);

        double complex t = w * odd[k];

        a[k] = even[k] + t;
        a[k + n / 2] = even[k] - t;
    }

    if (invert)
    {
        for (int i = 0; i < n / 2; i++)
        {
            even[i] /= 2;
            odd[i] /= 2;
        }
    }
}

void convolution(double A[], int m,
                 double B[], int n,
                 double C[])
{
    int size = 1;

    while (size < m + n - 1)
        size *= 2;

    double complex FA[size];
    double complex FB[size];

    for (int i = 0; i < size; i++)
    {
        FA[i] = 0;
        FB[i] = 0;
    }

    for (int i = 0; i < m; i++)
        FA[i] = A[i];

    for (int i = 0; i < n; i++)
        FB[i] = B[i];

    fft(FA, size, 0);
    fft(FB, size, 0);

    for (int i = 0; i < size; i++)
        FA[i] *= FB[i];

    fft(FA, size, 1);

    for (int i = 0; i < m + n - 1; i++)
        C[i] = creal(FA[i]) / size;
}

int main()
{
    int m, n;

    printf("Enter size of A: ");
    scanf("%d", &m);

    printf("Enter size of B: ");
    scanf("%d", &n);

    double A[m], B[n], C[m + n - 1];

    printf("Enter elements of A:\n");
    for (int i = 0; i < m; i++)
        scanf("%lf", &A[i]);

    printf("Enter elements of B:\n");
    for (int i = 0; i < n; i++)
        scanf("%lf", &B[i]);

    convolution(A, m, B, n, C);

    printf("\nConvolution:\n");

    for (int i = 0; i < m + n - 1; i++)
        printf("%.2lf ", C[i]);

    printf("\n");

    return 0;
}