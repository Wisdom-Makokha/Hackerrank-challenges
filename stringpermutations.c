//This is to be a program to find all the different permutations of a set of strings

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *output;

int main(int size, char *array[])
{ 
    void permutations(char **array, int size, int num);
    void swapstrings(char **array, int pos1, int pos2);
    

    if((output = fopen("Permute", "w")) == NULL)
    {
        fprintf(stderr, "Error opening file!\n");
        exit(EXIT_FAILURE);
    }
    
    swapstrings(array, 0, size - 1);
    size--;
    permutations(array, size, size);
    
    fclose(output);
    exit(EXIT_SUCCESS);
}

void swapstrings(char **array, int pos1, int pos2)
{
    char *temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

void printarray(char **array, int num)
{
    for(int i = 0; i < num; i++)
        fprintf(output, "%s", array[i]);
    
    fprintf(output, "\n");
}

void permutations(char **array, int size, int num)
{
    void swapstrings(char **array, int pos1, int pos2);
    void printarray(char **array, int num);
    if(size == 1)
    {
        printarray(array, num);
        return;
    }

    for(int i = 0;i < size; i++)
    {
        permutations(array, size - 1, num);

        if(size % 2 == 1)
            swapstrings(array,size - 1, 0);
        else
            swapstrings(array, i, size - 1);
    }
}