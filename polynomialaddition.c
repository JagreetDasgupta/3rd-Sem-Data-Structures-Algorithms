#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int size;
    int *power, *co_eff;
} typedef poly;

int mod(int a)
{
    return a > 0 ? a : -a;
}

void print_poly(poly *exp)
{
    for (int i = 0; i < exp->size; i++)
    {
        if (exp->co_eff[i] == 0)
            continue;
        if (i != 0)
            printf(" %c ", exp->co_eff[i] > 0 ? '+' : '-');
        if (mod(exp->co_eff[i]) == 1)
        {
            if (exp->power[i] == 0)
                printf("1 ");
            else if (exp->power[i] == 1)
                printf("x");
            else
                printf("x^%d", exp->power[i]);
        }
        else if (exp->power[i] != 0)
        {
            printf("%dx", mod(exp->co_eff[i]));
            if (exp->power[i] != 1)
                printf("^%d", exp->power[i]);
        }
        else
            printf("%d ", mod(exp->co_eff[i]));
    }
    printf("\n\n");
}

void input_poly(poly *exp)
{
    int size, i;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &size);
    exp->size = size;
    for (i = 0; i < size; i++)
    {
        exp->power = (int *)malloc(size * sizeof(int));
        exp->co_eff = (int *)malloc(size * sizeof(int));
    }

    printf("Enter the exponents in a decreasing order along with their co-effecients: \n");
    for (i = 0; i < size; i++)
        scanf("%d%d", &exp->power[i], &exp->co_eff[i]);
}

void sum_poly(poly *exp1, poly *exp2, poly *exp3)
{
    int i, j = 0, k = 0;
    exp3->size = exp1->size + exp2->size;

    exp3->power = (int *)malloc((exp3->size) * sizeof(int));
    exp3->co_eff = (int *)malloc((exp3->size) * sizeof(int));

    i = 0;
    while (j < exp1->size && k < exp2->size)
    {
        if (exp1->power[j] > exp2->power[k])
        {
            exp3->power[i] = exp1->power[j];
            exp3->co_eff[i++] = exp1->co_eff[j++];
        }
        else if (exp1->power[j] < exp2->power[k])
        {
            exp3->power[i] = exp2->power[k];
            exp3->co_eff[i++] = exp2->co_eff[k++];
        }
        else
        {
            exp3->power[i] = exp1->power[j];
            exp3->co_eff[i++] = exp1->co_eff[j++] + exp2->co_eff[k++];
        }
    }

    while (j < exp1->size)
    {
        exp3->power[i] = exp1->power[j];
        exp3->co_eff[i++] = exp1->co_eff[j++];
    }

    while (k < exp2->size)
    {
        exp3->power[i] = exp2->power[k];
        exp3->co_eff[i++] = exp2->co_eff[k++];
    }

    if (i != exp3->size)
    {
        exp3->power = realloc(exp3->power, i);
        exp3->co_eff = realloc(exp3->co_eff, i);

        exp3->size = i;
    }
}

void free_poly(poly *exp)
{
    free(exp->power);
    free(exp->co_eff);
    free(exp);
}

int main()
{
    poly *exp1 = (poly *)malloc(sizeof(poly)), *exp2 = (poly *)malloc(sizeof(poly)), *result = (poly *)malloc(sizeof(poly));

    printf("Enter the expression 1: \n");
    input_poly(exp1);

    printf("The expression 1 is: \n");
    print_poly(exp1);

    printf("Enter the expression 2: \n");
    input_poly(exp2);

    printf("The expression 2 is: \n");
    print_poly(exp2);

    sum_poly(exp1, exp2, result);
    printf("The result is: \n");
    print_poly(result);

    free_poly(exp1);
    free_poly(exp2);
    free_poly(result);

    return 0;
}