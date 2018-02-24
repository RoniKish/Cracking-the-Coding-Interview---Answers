#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,checker = 0;
    int letters_num = 0;
    char word[50];
    strcpy(word, "ab cdcb a");

    // creating and setting an array to 0 for counting
    int char_count[256];
    for(i=0;i<256;i++)
    {
        char_count[i] = 0;
    }
    // counting the number of shows each char does & number of letters
    for(i=0;i<strlen(word);i++)
    {
        letters_num++;
        char_count[(int) word[i]]++;
        if(word[i] == 32) // a space is not a letter ('32' ASPCII for space)
        {
            char_count[(int) word[i]]--;
            letters_num--;
        }
    }

    if(letters_num % 2 == 0)
    {
        for(i=0;i<strlen(word);i++)
        {
            if(char_count[(int) word[i]] % 2 == 1)
            {
                printf("the word is not a Palindrome Permutation");
                return 0;
            }
        }
        printf("the word is a Palindrome Permutation");
        return 1;
    }
    if(letters_num % 2 == 1)
    {
        if(char_count[(int) word[i]] % 2 == 1)
            checker++;
        if(checker > 1)
        {
            printf("the word is not a Palindrome Permutation");
            return 0;
        }
        printf("the word is a Palindrome Permutation");
        return 1;
    }
    return 0;
}
