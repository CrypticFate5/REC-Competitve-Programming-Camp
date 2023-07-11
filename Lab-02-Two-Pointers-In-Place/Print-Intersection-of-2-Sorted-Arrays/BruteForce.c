#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int m, n;
        scanf("%d", &m);
        int arr1[m];
        for (int i = 0; i < m; i++)
            scanf("%d", &arr1[i]);
        scanf("%d", &n);
        int arr2[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr2[i]);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr1[i] == arr2[j])
                {
                    printf("%d ", arr1[i]);
                    break;
                }
            }
        }
    }
    return 0;
}