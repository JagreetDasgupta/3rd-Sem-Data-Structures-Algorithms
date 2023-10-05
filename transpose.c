#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int col;
    int value;
} Triple;

// Function to convert a matrix into its sparse representation
Triple *convertToSparse(int **matrix, int rows, int cols, int *sparseSize)
{
    int nonZeroCount = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                nonZeroCount++;
            }
        }
    }

    *sparseSize = nonZeroCount;
    Triple *sparse = (Triple *)malloc(nonZeroCount * sizeof(Triple));
    int k = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = matrix[i][j];
                k++;
            }
        }
    }

    return sparse;
}

// Function to calculate the transpose of the matrix in sparse representation
Triple *transposeSparse(Triple *sparse, int sparseSize, int rows, int cols, int *transSparseSize)
{
    *transSparseSize = sparseSize;
    Triple *transSparse = (Triple *)malloc(sparseSize * sizeof(Triple));

    int *rowTermsCount = (int *)calloc(cols, sizeof(int));
    int *startingPos = (int *)malloc(cols * sizeof(int));

    // Calculate the number of terms in each column
    for (int i = 0; i < sparseSize; i++)
    {
        rowTermsCount[sparse[i].col]++;
    }

    // Calculate starting position for each column
    startingPos[0] = 0;
    for (int i = 1; i < cols; i++)
    {
        startingPos[i] = startingPos[i - 1] + rowTermsCount[i - 1];
    }

    // Calculate the transpose of the matrix
    for (int i = 0; i < sparseSize; i++)
    {
        int col = sparse[i].col;
        int pos = startingPos[col];
        transSparse[pos].row = sparse[i].col;
        transSparse[pos].col = sparse[i].row;
        transSparse[pos].value = sparse[i].value;
        startingPos[col]++;
    }

    free(rowTermsCount);
    free(startingPos);
    return transSparse;
}

// Function to display the sparse representation of a matrix
void displaySparse(Triple *sparse, int sparseSize)
{
    printf("Sparse Representation:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < sparseSize; i++)
    {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

int main()
{
    int rows, cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    int **matrix = (int *)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sparseSize, transSparseSize;
    Triple *sparse = convertToSparse(matrix, rows, cols, &sparseSize);
    displaySparse(sparse, sparseSize);

    Triple *transSparse = transposeSparse(sparse, sparseSize, rows, cols, &transSparseSize);
    displaySparse(transSparse, transSparseSize);

    // Free allocated memory
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    free(sparse);
    free(transSparse);

    return 0;
}