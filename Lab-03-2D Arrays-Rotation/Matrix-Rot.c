#include <stdio.h>

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
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

void rotate(int n, int arr[][n])
{
    transpose(n, arr);
    for (int k = 0; k < n; k++)
    {
        int i = 0, j = n - 1;
        while (i < j)
            swap(&arr[k][i++], &arr[k][j--]);
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
    char op[2];
    int rot = 0;
    while (1)
    {
        scanf("%s", op);
        if (op[0] == -1)
            return 0;
        else if (op[0] == 'Q')
        {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", arr[x - 1][y - 1]);
        }
        else if (op[0] == 'U')
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            if (rot == 0)
                arr[x - 1][y - 1] = z;
            else if (rot == 1)
                arr[y - 1][n - x] = z;
            else if (rot == 2)
                arr[n - x][n - y] = z;
            else
                arr[n - y][x - 1] = z;
        }
        else
        {
            int x, r;
            scanf("%d", &x);
            x = x % 360;
            r = x / 90;
            rot = (rot + r) % 4;
            for (int i = 0; i < r; i++)
            {
                rotate(n, arr);
            }
        }
    }
}