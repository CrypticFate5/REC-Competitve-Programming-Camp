#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d", &n);
        int arr1[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr1[i]);
        scanf("%d", &m);
        int arr2[m];
        for (int i = 0; i < m; i++)
            scanf("%d", &arr2[i]);
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (arr1[i] == arr2[j])
            {
                printf("%d ", arr1[i]);
                i++;
                j++;
            }
            else if (arr1[i] > arr2[j])
                j++;
            else
                i++;
        }
    }
    return 0;
}