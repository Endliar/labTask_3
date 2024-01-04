#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int N)
{
    int** matrix = (int**)malloc(N * sizeof(int*));

    for (int i = 0; i < N; i++) {
        matrix[i] = (int*)malloc(N * sizeof(int));

        for (int j = 0; j < N; j++)
        {
            printf("Enter a value for the element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    return matrix;
}

int countPositiveNumbers(int** matrix, int N)
{
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] > 0)
            {
                count++;
            }
        }
    }
    return count;
}

void countNegativeDiagonalElements(int** matrix, int N)
{
    int mainDiagonalCount = 0;
    int sideDiagonalCount = 0;

    for (int i = 0; i < N; i++) {
        if (matrix[i][i] < 0) {
            mainDiagonalCount++;
        }

        if (matrix[i][N - 1 - i] < 0)
        {
            sideDiagonalCount++;
        }
    }
    
    printf("The number of negative elements on the main diagonal: %d\n", mainDiagonalCount);
    printf("The number of negative elements on the side diagonal: %d\n", sideDiagonalCount);
}

void freeMatrix(int** matrix, int N)
{
    for (int i = 0; i < N; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main()
{
    int N = 3;
    int** matrix = createMatrix(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    int positiveNumbers = countPositiveNumbers(matrix, N);
    printf("The number of positive numbers in the matrix: %d\n", positiveNumbers);
    countNegativeDiagonalElements(matrix, N);

    freeMatrix(matrix, N);
    return 0;
}

