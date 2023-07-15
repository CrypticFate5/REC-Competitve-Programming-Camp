#include <stdio.h>
#include <math.h>
#include <string.h>

void seiveHelp(int *seive, int *primes, int *primesCount, int x, int y)
{
    for (int i = 2; i < y; i++)
    {
        if (seive[i])
        {
            if (i >= x)
            {
                primes[*primesCount] = i;
                *primesCount = *primesCount + 1;
            }
            for (int j = i * i; j <= y; j += i)
                seive[j] = 0;
        }
    }
}

int sumofsqdig(int n)
{
    int ans = 0;
    while (n)
    {
        int x = n % 10;
        ans += (x * x);
        n /= 10;
    }
    return ans;
}

int main()
{
    int n, x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &n);
    if (x <= 0 || y <= 0)
    {
        printf("Invalid Input");
        return 0;
    }
    int seive[y + 1], primes[1000], primesCount = 0, happyCount = 0;
    memset(seive, 1, sizeof(seive));
    seiveHelp(seive, primes, &primesCount, x, y + 1);
    int happy[primesCount];
    for (int i = 0; i < primesCount; i++)
    {
        int temp = primes[i];
        while (1)
        {
            int x = sumofsqdig(primes[i]);
            if (x == 1)
            {
                happy[happyCount++] = temp;
                break;
            }
            else if (x / 4 == 1)
                break;
            primes[i] = x;
        }
    }
    if (happyCount >= n)
        printf("%d\n", happy[n - 1]);
    else
        printf("No number is present at this index");
}