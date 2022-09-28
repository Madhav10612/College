#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *x, int *y)
{
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

void print_mat(float(*mat)[4], int r, int c){

    printf("\nMatrix:\n");
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("%.2f ",mat[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void mat_standardize(float (*mat)[4], float (*inv)[4], int r, int c)
{

    float divisor;

    for(int i=0; i<r; i++){
        divisor = mat[i][i];
        for(int j=i; j<c; j++){
            mat[i][j] /= divisor;
            inv[i][j] /= divisor;
        }
    }
}

void mat_inv_lower(float (*mat)[4], float (*inv)[4], int r, int c, int skip, int index)
{

    float multiple = 0.0;
    int row;

    for (int i = (0 + skip); i < r - 1; i++)
    {

        if (mat[index][index] == 0)
            index++;
        if (index >= r)
            return;

        multiple = mat[i + 1][index] / mat[index][index];
        printf("Multiple: %d %d: %f\n", index, i, multiple);

        for (int j = index; j < c; j++)
        {
            mat[i + 1][j] -= (mat[index][j] * multiple);
        }

        for(int k=0; k<c; k++)
            inv[i + 1][k] -= (inv[index][k] * multiple);

        print_mat(mat, r, c);
    }
}

void mat_inv_upper(float (*mat)[4], float (*inv)[4], int r, int c, int skip, int index)
{

    float multiple = 0.0;
    int row;

    for (int i = r-1; i>= 0+skip; i--)
    {

        if (mat[index][index] == 0)
            index--;
        if (index < 0)
            return;

        multiple = mat[i - 1][index] / mat[index][index];
        printf("Multiple: %d %d: %f\n", index, i, multiple);

        for (int j = c-1; j >index; j--)
        {
            mat[i - 1][j] -= (mat[index][j] * multiple);
        }

        for (int k = 0; k < c; k++)
            inv[i - 1][k] -= (inv[index][k] * multiple);

        print_mat(mat, r, c);
    }
}

void mat_transpose(float (*mat)[4], int r, int c){
    for (int i = 0; i < r; i++)
        for (int j = 0; j < i; j++)
            swap((int *)&mat[i][j], (int *)&mat[j][i]);
}

void mat_inv(int r, int c)
{
    float mat[4][4] = { {1, 2, 3, 4},
                        {2, 3, 4, 5},
                        {9, 7, 11, 3},
                        {1, 29, 5, 11}};

    float inv[4][4] = {{1, 0, 0, 0},
                       {0, 1, 0, 0},
                       {0, 0, 1, 0},
                       {0, 0, 0, 1}};

    print_mat(mat, r, c);

    mat_inv_lower(mat, inv, 4, 4, 0, 0);
    mat_inv_lower(mat, inv, 4, 4, 1, 1);
    mat_inv_lower(mat, inv, 4, 4, 2, 2);

    printf("Inverse ");
    print_mat(inv, 4, 4);

    mat_standardize(mat, inv, 4, 4);

    mat_inv_upper(mat, inv, 4, 4, 0, 0);
    mat_inv_upper(mat, inv, 4, 4, 1, 1);
    mat_inv_upper(mat, inv, 4, 4, 2, 2);

    print_mat(mat, r, c);

    printf("Inverse ");
    print_mat(inv, 4, 4);
}

int main(){
    
    mat_inv(4,4);

    return 0;
}
