#include <stdio.h>

void swap(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}
void transpose(int n, int arr[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(&arr[i][j], &arr[j][i]);
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    transpose(n, arr);
    for (int k = 0; k < n; k++)
    {
        int i = 0, j = n - 1;
        while (i < j)
        {
            swap(&arr[k][i], &arr[k][j]);
            i++;
            j--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}