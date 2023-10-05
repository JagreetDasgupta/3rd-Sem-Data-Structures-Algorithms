#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
int main()
{
    int r, c, size = 0, k = 1;
    printf("Enter the number of Rows and Columns in the Matrix \n");
    scanf("%d%d", &r, &c);
    int **mat = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
    {
        mat[i] = (int *)malloc(c * sizeof(int));
    }
    printf("Enter the elements in the matrix\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Input Matrix: ");
    printf("\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", mat[i][j]);
            if (mat[i][j] != 0)
            {
                size++;
            }
        }
        printf("\n");
    }
    int sp[size + 1][3], ts[size + 1][3];
    sp[0][0] = r;
    sp[0][1] = c;
    sp[0][2] = size;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] != 0)
            {
                sp[k][0] = i;
                sp[k][1] = j;
                sp[k][2] = mat[i][j];
                k++;
            }
        }
    }
    printf("Triplet is : \n");
    for (int i = 0; i < size + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", sp[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < size + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ts[i][0] = sp[i][1];
            ts[i][1] = sp[i][0];
            ts[i][2] = sp[i][2];
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            if (ts[j][0] > ts[j + 1][0])
            {
                swap(&ts[j][0], &ts[j + 1][0]);
                swap(&ts[j][1], &ts[j + 1][1]);
                swap(&ts[j][2], &ts[j + 1][2]);
            }
        }
    }
    printf("Transpose of Triplet is : \n");
    for (int i = 0; i < size + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", ts[i][j]);
        }
        printf("\n");
    }
    if (3 * (size + 1) < (c * r))
    {
        printf("Sparse is Beneficial\n");
    }
    else
    {
        printf("Sparse is Not Benificial\n");
    }
}