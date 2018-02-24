// checking to see if a word has more then 1 unique char
// WITHOUT AN ARRAY
// this code is run in C
#include <stdio.h>
#include <string.h>

int main()
{
    // defining variables
    char word[256];
    int i,j;
    strcpy(word, "abcdea");
    int str_length = strlen(word);
    // if a word is longer then 256 char then it must include 2
    // char of the same kind

    if (str_length > 256)
        printf("the word is not unique");

    // compare each char to the following char in "word"
    for(i = 0;i<str_length;i++)
    {
        for (j = i+1; j<str_length;j++)
        {
            if(word[i] == word[j])
            {
                printf("the word is not unique");
                return 0;
            }
        }
    }

    printf("the word is unique");
    return 0;
}
