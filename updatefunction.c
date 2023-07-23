// Task

// Complete the function void update(int *a,int *b). It receives two integer pointers, int* a and int* b. Set the value of  to their sum, and  to their absolute difference. There is no return value, and no return statement is needed.
// a = a + b
// b = |a - b|

// Input Format

// The input will contain two integers, a and b, separated by a newline.

// Output Format

// Modify the two values in place and the code stub main() will print their values.

// Note: Input/ouput will be automatically handled. You only have to complete the function described in the 'task' section.

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    void update(int *pa, int *pb);
    
    int a, b;
    int *pa = &a;
    int *pb = &b;

    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);

    update(pa, pb);

    printf("The sum is %d\nThe difference is %d", *pa, *pb);

    exit(EXIT_SUCCESS); 
}

void update(int *pa, int *pb)
{
    int sum = *pa + *pb;
    int difference = *pa - *pb;

    if(difference < 0)
        difference = -difference;

    *pa = sum;
    *pb = difference;
}