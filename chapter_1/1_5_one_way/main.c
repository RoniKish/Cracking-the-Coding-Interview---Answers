#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int one_edit_replace(char word[], char comparison[]);


int main()
{
	char word[50];
	strcpy(word, "abcde");
	// entering the word to compare
	printf("the word is: %s \nenter ur word: ", word);
	char comparison[50];
	scanf("%s", comparison);

	// check to see if the words are the same
	if (strlen(word) == strlen(comparison))
	{
		one_edit_replace(word, comparison);
		return 1;
	}

	// check to see if the difference in words length is more then 1
	if (abs(strlen(word) - strlen(comparison)) > 1)
	{
		printf("the words are more then 1 char different \n");
		return 0;
	}

	// check to see if the difference in words length is only 1
	char long_string[50],short_string[50];
    // first finding the shorter and longer string
	if (strlen(word) > strlen(comparison))
	{
        strcpy(long_string, word);
        strcpy(short_string, comparison);
	}
	else
	{
        strcpy(long_string, comparison);
        strcpy(short_string, word);
	}
	// checking to see if its only 1 insert/ deletion away
	int index1 = 0;
	int index2 = 0;
	while(index1 < strlen(short_string) && index2 < strlen(long_string))
    {
        if(short_string[index1] != long_string[index2])
        {
            if(index1 != index2)
            {
                printf("the words are more then 1 edit away");
                return 0;
            }
            index2++;
        }
        else
        {
            index1++;
            index2++;
        }
    }

	printf("the words are just one insert away \n");
	return 1;
}

// a function to check when the words length are the same
int one_edit_replace(char word[], char comparison[])
{
	if (strcmp(word, comparison) == 0)
	{
		printf("the words are execly the same \n");
		return 1;
	}
	int i,changes = 0;
	for (i = 0; i < strlen(word); i++)
	{
		if (word[i] != comparison[i])
		{
			if (changes == 1)
			{
				printf("the words are more then 1 char replaced \n");
				return 0;
			}
			changes++;
		}
	}
	printf("the words are one way edit away \n");
	return 1;
}
