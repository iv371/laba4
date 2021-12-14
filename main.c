#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ** memoryAllocation(int rows, int cols)
{
    int i = 0;
    int **matrix = (int **)malloc(rows*sizeof(int *));
    for( i = 0; i < rows; i++)
    {
      matrix[i] = (int *)malloc(cols*sizeof(int));
    }
    return matrix;
}
int **Manually(int **matrix,int rows,int cols)
    {
    int i,j;
    for (i=0; i<rows; i++)
        {
        for(j=0; j<cols; j++)
            {
            printf("[%d][%d] = ",i+1,j+1);
            scanf("%d", &matrix[i][j]);
            printf("\n");
            }
        }
        return matrix;
    }

int **Auto(int **matrix,int rows,int cols)
    {
    srand(time(NULL));
    int i,j;
    for (i=0; i<rows; i++)
        {
        for(j=0; j<cols; j++)
            {
            matrix[i][j]=rand() % 101;
            }
        }
        return matrix;
    }
void Dump(int **matrix,int rows,int cols)
{
    int i ,j;
      for (i=0; i<rows; i++)
        {
        for(j=0; j<cols; j++)
            {
            printf("%d \t",matrix[i][j]);
            }
            printf("\n");
        }
}
void MaxMin(int **matrix,int rows,int cols)
    {
    int i,j,max,min;
    max=matrix[0][0];
    min=matrix[0][0];
    for(i=0; i<rows; i++)
        {
        for(j=0; j<cols; j++)
            {
            if(min<matrix[i][j])
                {
                min=matrix[i][j];
                }
            }
        }
    for(i=0; i<rows; i++)
        {
        for(j=0; j<cols; j++)
            {
            if(min>matrix[i][j])
                {
                min=matrix[i][j];
                }
            }
        }
    printf("max = %d\n", max);
    printf("min = %d\n", min);
    }

void trans(int **matrix,int rows,int cols)
    {
    int i = 0,j = 0;
    for (i = 0; i < cols; i++)
    {
        for (j = 0; j < rows; j++)
        {
           printf("%d ",matrix[j][i]);
           printf("\t");
        }
        printf("\n");
    }
    }

void DOB(int **matrixA,int rowsA,int colsA,int **matrixB,int rowsB,int colsB)
    {
    int i,j,k,s;
    printf("Multiplication matrix A and B (A x B) : \n");
      for(i = 0;i < rowsA;i++)
        {
          for(j = 0;j < colsB;j++)
          {
             s = 0;
             for(k=0; k < rowsB; k++)
             {
                 s=s+matrixA[i][k]*matrixB[k][j];
             }
             printf("%d \t",s);
          }
          printf("\n");
        }
    }

void array()
{
    int l=5,i = 0,j,k;
    int arr[5];
    for (i = 0; i<l; i++)
    {
      printf("a[%d] = ",i+1);
      scanf("%d",&arr[i]);
    }
    printf("Standart: \n");
    for(i = 0;i<l;i++)
    {
      printf("%d ",arr[i]);
    }
    printf("\n");
    for(i = 0; i<l-1; i++)
    {
        for(j = 0; j<l-1; j++)
        {
          if(arr[j]<arr[j+1])
          {
            k=arr[j+1];
            arr[j] = arr[j];
            arr[j] = k;
          }
        }
    }
    printf("Max -> min: \n");
    for(i = 0;i<l;i++)
    {
      printf("%d ",arr[i]);
    }
}

void suma(int **matrixA,int rowsA,int colsA,int **matrixB,int rowsB,int colsB)
    {
    int i,j,x;
    printf("Sum rows A: \n");
    for( i = 0; i < rowsA; i++)
        {
        x = 0;
        for( j = 0; j <colsA; j++)
            {
            x+=matrixA[i][j];
            }
        printf("Row [%d] = %d \n",i+1,x);
        }
    printf("Sum cols B: \n");
    for( i = 0; i < colsB; i++)
    {
        x = 0;
        for( j = 0; j < rowsB; j++)
        {
            x+=matrixB[j][i];
        }
        printf("Col [%d] = %d \n",i+1,x);
    }
    }
 void swap_test(int *a, int *b)
 {
     int temp;
     temp=*a;
     *a=*b;
     *b=temp;

 }
int main()
    {
    int *a=7, *b=8;
    printf("%d - a \n %d - b \n", a, b);
    swap_test(&a, &b);
    printf("%d - a \n %d - b \n", a, b);
    int task,task2;
    int rowsA,colsA,rowsB,colsB;
    int **matrixA, **matrixB;
    int *testP;
    int test_var=3;
    testP=&test_var;
    printf("%d\n",test_var);
    printf("%d\n\t",*testP);

    printf("Enter size Matrix A1 (N x N)\n N = ");
    scanf("%d",&rowsA);
    printf("\n");
    colsA = rowsA;
    printf("Enter size Matrix B (N x M)\n M = ");
    scanf("%d",&colsB);
    rowsB=rowsA;
    printf("\n");
        matrixA = memoryAllocation(rowsA,colsA);
        matrixB = memoryAllocation(rowsB,colsB);
    printf("1.Anutomatically\n");
    printf("2.Manually\n");
    scanf("%d", &task2);
    if (task2 < 0 || task2 > 2)
        {
        printf("%s", "Sorry, no such task to execute. Good buy!");
        return 0;
        }
    switch (task2)
        {
        case 1:
          matrixA = Auto(matrixA,rowsA,colsA);
          matrixB = Auto(matrixB,rowsB,colsB);
            break;
        case 2:
        printf("Matrix A: \n");
        matrixA = Manually(matrixA,rowsA,colsA);
        printf("Matrix B: \n");
        matrixB = Manually(matrixB,rowsB,colsB);
            break;
        }
    printf("Matrix A:\n");
    Dump(matrixA,rowsA,colsA);
    printf("Matrix B:\n");
    Dump(matrixB,rowsB,colsB);
    printf("%s\n", "Please, provide a task you want to execute:");
    printf("%s\n", "1. Maximum element of matrix A");
    printf("%s\n", "2. Matrix B transposition.");
    printf("%s\n", "3. Matrix production of A and B.");
    printf("%s\n", "4. Sort array.");
    printf("%s\n", "5. Print sum of rows of matrix A and cols of B.");
    scanf("%d", &task);
    if (task < 0 || task > 5)
        {
        printf("%s", "Sorry, no such task to execute. Good buy!");
        return 0;
        }
    switch (task)
        {

        case 1:
            MaxMin(matrixA,rowsA,colsA);
            printf("2. Matrix B transposition.\n");
            break;
        case 2:
           trans(matrixB,rowsB,colsB);
           printf("3. Matrix production of A and B.\n");
            break;
        case 3:
            DOB(matrixA,rowsA,colsA,matrixB,rowsB,colsB);
            printf("4. Sort array.\n");
            break;
        case 4:
            array();
            break;
        case 5:
            printf("5. Print sum of rows of matrix A and cols of B.\n");
            suma(matrixA,rowsA,colsA,matrixB,rowsB,colsB);
            break;

        }
    return 0;
    }
