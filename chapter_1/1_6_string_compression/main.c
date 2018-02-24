#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    char word[50];
    char comp_word[50];
    char buffer[50];
    strcpy(buffer, "");
    strcpy(comp_word, "");

    strcpy(word, "aaacceeeed");
    // creating an setting an hash table for char
    char letter_count[256];
    for(i=0;i<256;i++)
        letter_count[i] = 0;
    // counting the number of times a letter shows
    for(i=0;i<strlen(word);i++)
    {
        letter_count[(int) word[i]]++;
    }
    for(i=0;i<256;i++)
    {
        if(letter_count[i] == 0)
            continue;
        else
        {
            sprintf(buffer, "%d", letter_count[i]);
            strcat(comp_word, buffer);
            sprintf(buffer, "%c", i);
            strcat(comp_word, buffer);
        }
    }
    if(strlen(comp_word) > strlen(word))
        printf("the shortest term is: %s", word);
    else
        printf("the shortest term is: %s", comp_word);

    return 0;
}
