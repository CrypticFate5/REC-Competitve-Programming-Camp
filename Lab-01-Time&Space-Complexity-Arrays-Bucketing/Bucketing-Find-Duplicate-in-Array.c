#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n], buc[n];
    memset(buc, 0, sizeof(buc));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        buc[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (buc[i] > 1)
        {
            printf("%d", i);
            return 0;
        }
    }
}