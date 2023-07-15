#include <stdio.h>
#include <string.h>

void swapInt(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
void swapChar(char *a, char *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
void sort(int n, int *arr, char *st)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swapInt(&arr[j], &arr[j + 1]);
                swapChar(&st[j], &st[j + 1]);
            }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char p[26], s[100];
        scanf("%s", p);
        scanf("%s", s);
        int n = strlen(s);
        int arr[n], buc[26];
        for (int i = 0; i < 26; i++)
            buc[p[i] - 'a'] = i;
        for (int i = 0; i < n; i++)
            arr[i] = buc[s[i] - 'a'];
        sort(n, arr, s);
        printf("%s\n", s);
    }
}