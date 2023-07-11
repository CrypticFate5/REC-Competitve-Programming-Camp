# Lab-01 Time & Space Complexity Arrays, Bucketing

### Find Duplicate in Array

#### Problem Statement
Given a read only array of n + 1 integers between 1 and n, find one number that repeats.

#### Sample input and output

INPUT(s):  
11  
10 9 7 6 5 1 2 3 8 4 7    
OUTPUT(s):  
7  

INPUT(s):  
5  
1 2 3 4 4    
OUTPUT(s):  
4  

INPUT(s):  
5  
1 1 2 3 4    
OUTPUT(s):  
1  

- [Brute Force](.Brute-Force-FInd-Duplicate-in-Array.c)

```
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                printf("%d", arr[i]);
                return 0;
            }
        }
    }
    return 0;
}
```
- [Bucketing Approach](.Bucketing-Find-Duplicate-in-Array.c)

```
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
```

- [Efficient Approach](Efficient-Find-Duplicate-in-Array.c)

```
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
```
---
