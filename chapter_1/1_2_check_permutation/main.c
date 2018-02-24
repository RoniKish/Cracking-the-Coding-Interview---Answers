#include <stdio.h>
#include <string.h>

int main()
{
    char word[256];
    char permutation[256];
    int i,word_length;
    strcpy(word, "abcde");
    strcpy(permutation, "acebd");
    word_length = strlen(word);

    // in case the the 2nd word is not in the same length as
    // the 1st word, there is no way it can be a permutation
    if(word_length != strlen(permutation))
    {
        printf("the word is not a permutation");
        return 0;
    }

    // creating and setting an array to 0 for counting
    int word_char[256];
    for(i=0;i<256;i++)
    {
        word_char[i] = 0;
    }
    // counting the appearances of each letter
    for(i=0;i<word_length;i++)
    {
        word_char[word[i]]++;
    }
    // decreasing the appearances of each letter
    for(i=0;i<word_length;i++)
    {
        word_char[permutation[i]]--;
        if(word_char[permutation[i]] < 0)
        {
            printf("the word is not a permutation");
            return 0;
        }
    }

    printf("the word is a permutation");
    return 1;
}
