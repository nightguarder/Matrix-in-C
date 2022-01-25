#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h" //greatest_common_divisor & least common multiple
#include "matrix.h" //matrix allocation, memory free(), matrix printf() 

#define MAX_SIZE 1000 

void swap(int *x, int *y) 
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

int erorr(int argc, char** argv)
{
    if( argc == 2 )
      printf("The argument entered is: %s\n", argv[1]);
   
    else if( argc > 2 ) 
      printf("Too many arguments entered. \n");
   
    else 
      printf("Expected a parameter. \n");
      
    return 0;
}

void read_input(char *argv[],int *n1,int *n2)
{
    char *p;
    errno = 0;
    int n = 0;

    //convert string to long &p = modified end pointer 10 = radix number 
    long temp = strtol(argv[2],&p,10);
    long temp2 = strtol(argv[3],&p,10);

    //if parameter is invalid or larger than int
    if (errno != 0 || *p != '\0'|| temp>INT_MAX || temp<INT_MIN)
    erorr(n,argv);

    if (argv[3]==NULL) //argv[3] is missing
    {
        *n1 = temp;
        *n2 = temp;
    }

    //return the input numbers
    else{
        *n1 = temp;
        *n2 = temp2;
    }
}
//fill the matrix
void pointer_function(int **matrix,int row, int col, int (*func)(int ,int)){
    int ret = func(row,col);

    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; i < col; i++)
            matrix[i][j] = ret; 
    
}

int main(int argc, char** argv){
   //argv[0] == program name
   //argv[1] == parameters

   //pointer to a function
    int (*func)(int x, int y) = NULL;
    int n = 3, m = 3;
    int pn,pm = 0;
    int **matrix;
     
    printf("parameters passed: %s, %s, %s\n",argv[1],argv[2],argv[3]);
    //if argv[2] parameter is valid
    if (argv[2])
    read_input(argv,&pn,&pm);

    printf("input numbers are : %d, %d \n",pn,pm);

    if (argv[1][1] == 'g' || argv[1][1] == 'l')
    {
        //printf("parametr is : g or l");
         while (*argv++ && **argv == '-')
        {
            switch (argv[0][1])
            {
            case 'g':
                func = &gcd;
                gcd(pn,pm);
                break;
            case 'l':
                func = &lcm;
                lcm(pn,pm);
                break;
            default:
            erorr(argc,argv);
                break;
            }
        } 
    }
    //zadny parametr nenalezen
    /*  if (!argv[0] || !argv[1])
    erorr(argc,argv);  */
    int size = sizeof (*matrix) / sizeof (**matrix);

    matrix = allocate_matrix(matrix,pn,pm);
    pointer_function(matrix,n,m,func);
    print_matrix(matrix,pm);
    free_array(matrix,size);
    //free(matrix);
    
    return 0;
}
