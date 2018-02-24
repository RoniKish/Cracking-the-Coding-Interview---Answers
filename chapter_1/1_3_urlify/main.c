#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,word_length;
    char word[50];
    strcpy(word, "this is a check");
    word_length = strlen(word);
    // running on the string char by char till we get a space
    for(i=0;i<word_length;i++)
    {
        if(word[i] == ' ')
            printf("%%20");
        else
        printf("%c", word[i]);
    }

    printf("\n");
    return 0;
}
