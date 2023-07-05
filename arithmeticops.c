// Your task is to take two numbers of int data type, two numbers of float data type as input and output their sum:

// Declare 4 variables: two of type int and two of type float.
// Read 2 lines of input from stdin (according to the sequence given in the 'Input Format' section below) and initialize your 4 variables.
// Use the + and - operator to perform the following operations:
// Print the sum and difference of two int variable on a new line.
// Print the sum and difference of two float variable rounded to one decimal place on a new line.

#include<stdio.h>
#include<stdlib.h>

#define UPPERCONSTRAINT 10000
float absolutefloat(float nonegative);
int absoluteint(int nonegative);

int main(void)
{
    float floatconstraint(float restrain);
    int intconstraint(int restrain);
    int numint1 = 0;
    int numint2 = 0;
    int intsum = 0;
    int intdiff = 0;
    float numfloat1 = 0.0;
    float numfloat2 = 0.0;
    float floatsum = 0.0;
    float floatdiff = 0;
    char discard[200];
    
    //Entering the integers
    printf("Enter two integers on the same line separated by a space: ");
    scanf("%d %d", &numint1, &numint2);
    scanf("%[^\n]%*c", discard);

    //Ensuring number is within constraints
    numint1 = intconstraint(numint1);
    numint2 = intconstraint(numint2);

    //Entering the floats
    printf("Enter two floats on the same line separated by a space: ");
    scanf("%f %f", &numfloat1, &numfloat2);
    scanf("%[^\n]%*c", discard);

    //Ensuring the number is within constraints
    numfloat1 = floatconstraint(numfloat1);
    numfloat2 = floatconstraint(numfloat2);

    //Calculations for integers
    intsum = numint1 + numint2;
    intdiff = numint1 - numint2;
    
    //Calculations for floats
    floatsum = numfloat1 + numfloat2;
    floatdiff = numfloat1 - numfloat2;

    printf("%d %d\n%.1f %.1f", intsum, intdiff, floatsum, floatdiff);

    exit(EXIT_SUCCESS);
}

//This function is to make floating point values meet this constraint
//1 <= floatvalue <= 10000
float floatconstraint(float restrain)
{
    float temp;
    //wholepart stores the integer value of restrain
    int wholepart = (int) restrain; 

    restrain = absolutefloat(restrain);
    //floating point values cannot be operated on by the modulus operator
    //temp stores the decimal part
    //getting the remainder after dividing with upper constraint leaves us with values below it
    temp = restrain - wholepart;

    //if statement to ensure upper constraint is not cut off
    if(wholepart != UPPERCONSTRAINT)
        wholepart %= UPPERCONSTRAINT;

    //joining the integer and decimal parts back together
    restrain = wholepart + temp;

    return restrain;
}

//This function is to make int values meet this constraint
//1 <= integer <= 10000
int intconstraint(int restrain)
{
    restrain = absoluteint(restrain);

    //Easier for int values to use modulus operator
    //ensures the constraint of being lower than equal to upper constraint is met
    if(restrain != UPPERCONSTRAINT)
        restrain %= UPPERCONSTRAINT;

    return restrain;
}

//Function to get the absolute values of integers
int absoluteint(int nonegative)
{
    if(nonegative < 0)
        nonegative = -nonegative;

        return nonegative;
}

//Funtion to get the absolute value of floats
float absolutefloat(float nonegative)
{
    if(nonegative < 0)
        nonegative = -nonegative;

    return nonegative;
}