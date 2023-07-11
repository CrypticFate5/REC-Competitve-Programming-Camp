# Lab-02 Two-Pointers In-Place

### Print Intersection of 2-Sorted Arrays

#### Problem Statement
Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays. 

Input Format
The first line contains T, the number of test cases. Following T lines contain:
1. Line 1 contains N1, followed by N1 integers of the first array
2. Line 2 contains N2, followed by N2 integers of the second array

Output Format  
The intersection of the arrays in a single line

#### Sample input and output

Input:  
1  
3 10 17 57  
6 2 7 10 15 57 246    

Output:  
10 57

Input:  
1  
6 1 2 3 4 5 6  
2 1 6  

Output:  
1 6

- [Brute Force](./Print-Intersection-of-2-Sorted-Arrays/BruteForce.c)
```
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
```

- [Efficient Approach](./Print-Intersection-of-2-Sorted-Arrays/Efficient.c)

```
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
```

### Pair with difference K

#### Problem Statement

Given an array A of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[j] - A[i] = k, i != j.

##### Example:

Input:  
3  
1 3 5  
4    
Output  
1  
Explanation:  
YES as 5 - 1 = 4

Return 0 / 1 (0 for false, 1 for true) for this problem.

#### Sample input and output

INPUT(s):  
10  
1 4 6 8 12 14 15 20 21 25  
1    
OUTPUT(s):  
1

INPUT(s):
10  
1 2 3 5 11 14 16 24 28 29  
0    
OUTPUT(s): 
0

INPUT(s):
10  
0 2 3 7 13 14 15 20 24 25  
10   
OUTPUT(s):  
1

- [Brute Force]()

```
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
```

- [Efficient Approach]()

```
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
```
---
