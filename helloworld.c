//This challenge requires you to print  on a single line, and
// then print the already provided input string to stdout. If
// you are not familiar with C, you may want to read about 
//the printf() command.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    char * hisstring = (char *) calloc(100, sizeof(char));

    if(hisstring == NULL)
    {
        fprintf(stderr, "calloc failed!\n");
        exit(EXIT_FAILURE);
    }
    char mystring[100];

    scanf("%[^\n]%*c", hisstring);

    fprintf(stdout, "Hello, World\n%s", hisstring);

    free(hisstring);
    
    exit(EXIT_SUCCESS);
}