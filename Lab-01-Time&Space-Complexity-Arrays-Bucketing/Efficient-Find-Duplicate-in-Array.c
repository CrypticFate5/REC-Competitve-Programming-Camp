#include <stdio.h>

int main()
{
    int n, arrsum = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        arrsum += arr[i];
    }
    int tot = n * (n - 1) / 2;
    printf("%d", arrsum - tot);
    return 0;
}