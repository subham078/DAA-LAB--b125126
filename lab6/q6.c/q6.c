//q.6.2D SQUARE MATRIX OPERATIONS

#include <stdio.h>
#include <math.h>

#define MAX 100

/* Display Matrix */
void displayMatrix(double A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%8.2lf ", A[i][j]);
        }

        printf("\n");
    }
}

/* (i) Matrix Addition */
void matrixAddition(double A[MAX][MAX],
                    double B[MAX][MAX],
                    double C[MAX][MAX],
                    int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

/* (ii) Matrix Multiplication */
void matrixMultiplication(double A[MAX][MAX],
                          double B[MAX][MAX],
                          double C[MAX][MAX],
                          int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/* (iii) Check Zero Matrix */
int isZeroMatrix(double A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
                return 0;
        }
    }

    return 1;
}

/* (iv) Check Symmetric Matrix */
int isSymmetric(double A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i][j] != A[j][i])
                return 0;
        }
    }

    return 1;
}

/* (v) Find Determinant using Gaussian Elimination */
double determinant(double A[MAX][MAX], int n)
{
    double det = 1.0;

    for (int i = 0; i < n; i++)
    {
        int pivot = i;

        for (int j = i + 1; j < n; j++)
        {
            if (fabs(A[j][i]) > fabs(A[pivot][i]))
                pivot = j;
        }

        if (fabs(A[pivot][i]) < 1e-9)
            return 0;

        if (pivot != i)
        {
            for (int j = 0; j < n; j++)
            {
                double temp = A[i][j];
                A[i][j] = A[pivot][j];
                A[pivot][j] = temp;
            }

            det = -det;
        }

        det *= A[i][i];

        for (int j = i + 1; j < n; j++)
        {
            double factor = A[j][i] / A[i][i];

            for (int k = i; k < n; k++)
            {
                A[j][k] -= factor * A[i][k];
            }
        }
    }

    return det;
}

/* (vi) Transpose In-Place */
void transpose(double A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}

/*
   (vii) Dominant Eigenvalue and Eigenvector
   using Power Iteration
*/
void powerIteration(double A[MAX][MAX], int n)
{
    double x[MAX];
    double y[MAX];

    for (int i = 0; i < n; i++)
        x[i] = 1.0;

    double eigenvalue = 0;

    for (int iteration = 0; iteration < 1000; iteration++)
    {
        double maxValue = 0;

        /* y = A*x */
        for (int i = 0; i < n; i++)
        {
            y[i] = 0;

            for (int j = 0; j < n; j++)
            {
                y[i] += A[i][j] * x[j];
            }

            if (fabs(y[i]) > maxValue)
                maxValue = fabs(y[i]);
        }

        /* Normalize */
        for (int i = 0; i < n; i++)
            x[i] = y[i] / maxValue;

        eigenvalue = maxValue;
    }

    printf("\nDominant Eigenvalue = %.6lf\n", eigenvalue);

    printf("Corresponding Eigenvector:\n");

    for (int i = 0; i < n; i++)
        printf("%.6lf\n", x[i]);
}

int main()
{
    int n, choice;

    double A[MAX][MAX];
    double B[MAX][MAX];
    double C[MAX][MAX];

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("\nEnter elements of Matrix A:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }

    do
    {
        printf("\n========== MATRIX OPERATIONS ==========\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Check Zero Matrix\n");
        printf("4. Check Symmetric Matrix\n");
        printf("5. Find Determinant\n");
        printf("6. Transpose In-Place\n");
        printf("7. Find Eigenvalue and Eigenvector\n");
        printf("8. Display Matrix\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("\nEnter elements of Matrix B:\n");

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    scanf("%lf", &B[i][j]);
                }
            }

            matrixAddition(A, B, C, n);

            printf("\nA + B =\n");
            displayMatrix(C, n);

            break;

        case 2:

            printf("\nEnter elements of Matrix B:\n");

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    scanf("%lf", &B[i][j]);
                }
            }

            matrixMultiplication(A, B, C, n);

            printf("\nA x B =\n");
            displayMatrix(C, n);

            break;

        case 3:

            if (isZeroMatrix(A, n))
                printf("Matrix is a Zero Matrix.\n");
            else
                printf("Matrix is NOT a Zero Matrix.\n");

            break;

        case 4:

            if (isSymmetric(A, n))
                printf("Matrix is Symmetric.\n");
            else
                printf("Matrix is NOT Symmetric.\n");

            break;

        case 5:
        {
            double temp[MAX][MAX];

            /* Copy A because determinant modifies matrix */
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    temp[i][j] = A[i][j];
            }

            printf("Determinant = %.2lf\n",
                   determinant(temp, n));

            break;
        }

        case 6:

            transpose(A, n);

            printf("\nTranspose of Matrix A:\n");
            displayMatrix(A, n);

            break;

        case 7:

            powerIteration(A, n);

            break;

        case 8:

            printf("\nMatrix A:\n");
            displayMatrix(A, n);

            break;

        case 0:

            printf("Program terminated.\n");
            break;

        default:

            printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
