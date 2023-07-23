// Task

// Write a function int max_of_four(int a, int b, int c, int d) which reads four arguments and returns the greatest of them.

// Note

// There is not built in max function in C. Code that will be reused is often put in a separate function, e.g. int max(x, y) that returns the greater of the two values.

// Input Format

// Input will contain four integers -  a, b, c, d, one on each line.

// Output Format

// Print the greatest of the four integers.
// Note: I/O will be automatically handled.
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int max(int *numarray);

    int arraynum[4];
    int ourmax;

    printf("Enter your numbers: ");
    
    scanf("%d %d %d %d", arraynum, arraynum + 1, arraynum + 2, arraynum + 3);

    ourmax = max(arraynum);
    printf("Our max is: %d", ourmax);

    exit(EXIT_SUCCESS);
}

int max(int *numarray)
{
    int maximum = *numarray;
    int i = 1;

    for(numarray++; i < 4; numarray++, i++)
        if(maximum < *numarray)
            maximum = *numarray;

    return maximum;
}