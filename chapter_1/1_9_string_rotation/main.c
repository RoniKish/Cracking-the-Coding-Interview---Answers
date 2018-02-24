#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSubstring(char S1[], char S2[]);


int main()
{
	int i, cutting_point = 0;
	char S1S1[100];
	char S1[50];
	char S2[50];
	printf("Enter the string for S1: ");
	gets(S1);
	printf("Enter the string for S2: ");
	gets(S2);

	if (strlen(S1) == strlen(S2) && strlen(S1) > 0)
	{
		strcpy(S1S1, S1);
		strcat(S1S1, S1);
		if(isSubstring(S1S1, S1))
            printf("%s is a rotation of %s\n", S1, S2);
	}

	return 0;
}
// checks if S1 S2 are sub-strings (for the purpose of the exercise return 1)
int isSubstring(char S1[], char S2[])
{
	return 1;
}
