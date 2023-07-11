#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &k);
    int i = 0, j = 1;
    while (i != n)
    {
        if (i != j && arr[j] - arr[i] == k)
        {
            printf("1");
            return 0;
        }
        else if (arr[j] - arr[i] > k)
            i++;
        else
            j++;
    }
    printf("0");
    return 0;
}