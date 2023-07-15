#include <stdio.h>
#include <string.h>
void rotateLeft(int n, char *st)
{
    char c = st[n - 1];
    for (int i = n - 1; i > 0; i--)
        st[i] = st[i - 1];
    st[0] = c;
}

void rotateRight(int n, char *st)
{
    char c = st[0];
    for (int i = 0; i < n - 1; i++)
        st[i] = st[i + 1];
    st[n - 1] = c;
}

int isPalin(int n, char *s)
{
    int i = 0, j = n - 1;
    while (i < j)
        if (s[i++] != s[j--])
            return 0;
    return 1;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int help(int n, char *st)
{
    int ansLeft = 0, ansRight = 0, ans;
    char stpy[1000];
    strcpy(stpy, st);
    for (int i = 0; i < n; i++)
    {
        if (isPalin(n, stpy))
            break;
        rotateLeft(n, stpy);
        ansLeft++;
    }
    strcpy(stpy, st);
    for (int i = 0; i < n; i++)
    {
        if (isPalin(n, stpy))
            break;
        rotateRight(n, stpy);
        ansRight++;
    }
    ans = min(ansLeft, ansRight);
    return ans;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char st[1000];
        scanf("%s", st);
        int n = strlen(st), ans = help(n, st);
        if (ans == n)
            printf("-1\n");
        else
            printf("%d", ans);
    }
}
