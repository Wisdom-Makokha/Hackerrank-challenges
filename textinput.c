// Task

// You have to print the character, ch, in the first line. Then print s in next line. In the last line print the sentence, sen.

// Input Format

// First, take a character, ch as input.
// Then take the string, s as input.
// Lastly, take the sentence sen as input.

// Constraints

// Strings for s and sen will have fewer than 100 characters, including the newline.

// Output Format

// Print three lines of output. The first line prints the character, .
// The second line prints the string, .
// The third line prints the sentence, .

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    int max_length = 100;
    char ch;
    char s[max_length];
    char sen[max_length];

    scanf("%c", &ch);
    scanf("%s", s);
    scanf("\n%[^\n]%*c", sen);

    printf("%c\n%s\n%s", ch, s, sen);
    
    exit(EXIT_SUCCESS);
}