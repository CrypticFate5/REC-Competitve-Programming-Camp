#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &k);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] - arr[i] == k)
            {
                printf("1");
                return 0;
            }
        }
    }
    printf("0");
    return 0;
}