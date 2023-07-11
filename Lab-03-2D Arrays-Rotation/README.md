# Lab-03 2D Arrays Rotation

### [Rotate Image - 90 Degree](Rotate-Img.c)

#### Problem Statement

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

Input:   
matrix =   
[[1,2,3]  
,[4,5,6],  
[7,8,9]]

Output:  
[[7,4,1]  
,[8,5,2],  
[9,6,3]]

#### Constraints

- n == matrix.length == matrix[i].length
- 1 <= n <= 20
- -1000 <= matrix[i][j] <= 1000

#### Sample input and output
Input  

3  
1 2 3  
4 5 6  
7 8 9  

Result  
7 4 1  
8 5 2  
9 6 3  

#### Code

```
#include <stdio.h>

void swap(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}
void transpose(int n, int arr[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(&arr[i][j], &arr[j][i]);
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    transpose(n, arr);
    for (int k = 0; k < n; k++)
    {
        int i = 0, j = n - 1;
        while (i < j)
        {
            swap(&arr[k][i], &arr[k][j]);
            i++;
            j--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}
```

### [Matrix Rotation](Matrix-Rot.c)

#### Problem Statement

You are given a square matrix of dimension N. Let this matrix be called A. Your task is to rotate A in clockwise direction by S degrees, where S is angle of rotation. On the matrix, there will be 3 types of operations viz.

1. Rotation
Rotate the matrix A by angle S, presented as input in form of A S
2. Querying
Query the element at row K and column L, presented as input in form of Q K L
3. Updation
Update the element at row X and column Y with value Z, presented as input in form of U X Y Z

Print the output of individual operations as depicted in Output Specification.

Input Format:

Input will consist of three parts, viz.

- Size of the matrix (N)
- The matrix itself (A = N * N)
- Various operations on the matrix, one operation on each line. (Beginning either with A, Q or U)
- -1 will represent end of input

Note:  
- Angle of rotation will always be multiples of 90 degrees only.
- All Update operations happen only on the initial matrix. After update all the previous rotations have to be applied on the updated matrix

Output Format:

For each Query operation print the element present at K-L location of the matrix in its current state.

#### Constraints

- 1<=N<=1000
- 1<=Aij<=1000
- 0<=S<=160000
- 1<=K, L<=N
- 1<=Q<=100000

#### Sample Input and Output

##### Input 

2  
1 2  
3 4  
A 90  
Q 1 1  
Q 1 2  
A 90  
Q 1 1  
U 1 1 6  
Q 2 2  
-1  

##### Output

3  
1  
4  
6  

##### Explanation:

Initial Matrix

1 2  
3 4  

After 90-degree rotation, the matrix will become

3 1  
4 2  

Now the element at A11 is 3 and A12 is 1.

Again the angle of rotation is 90 degrees, now after the rotation the matrix will become

4 3  
2 1  

Now the element at A11 is 4.

As the next operation is Update, update initial matrix i.e.

6 2  
3 4  

After updating, apply all the previous rotations (i.e. 180 = two 90 degree rotations)

The matrix will now become

4 3     
2 6  

Now A22 is 6.

#### Code

```
#include <stdio.h>

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void transpose(int n, int arr[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(&arr[i][j], &arr[j][i]);
        }
    }
}

void rotate(int n,int arr[][n]){
    transpose(n,arr);
    for(int k=0;k<n;k++){
        int i=0,j=n-1;
        while(i<j) {
            swap(&arr[k][i++],&arr[k][j--]);
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    char op[2];
    int rot=0;
    while (1)
    {
        scanf("%s", op);
        if (op[0] == -1)
            return 0;
        else if (op[0] == 'Q')
        {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", arr[x - 1][y - 1]);
        }
        else if (op[0] == 'U')
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            if(rot==0) arr[x - 1][y - 1] = z;
            else if(rot==1) arr[y-1][n-x]=z;
            else if(rot==2) arr[n-x][n-y]=z;
            else arr[n-y][x-1]=z;
        }
        else
        {
            int x, r;
            scanf("%d", &x);
            x = x % 360;
            r = x / 90;
            rot=(rot+r)%4;
            for(int i=0;i<r;i++){
                rotate(n,arr);
            }
        }
    }
}
```