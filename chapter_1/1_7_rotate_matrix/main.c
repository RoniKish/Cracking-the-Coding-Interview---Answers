#include <stdlib.h>
#include <stdio.h>

void print_mat(int mat[], int n);


int main()
{
	int i,j, arr_set = 0;
	int *mat;
	int *temp_mat;
	mat = (int *)malloc(4 * 4 * sizeof(int));
	temp_mat = (int *)malloc(4 * 4 * sizeof(int));
	// Creates the matrix
	for ( i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			mat[i*4 + j] = i * 4 + j;
		}
	}
	print_mat(mat, 4 * 4);
	printf("\n\n");
	// Creates a new matrix in a 90 degree turn
	for (i = 0; i < 4; i++)
	{
		for (j = 3; j > -1; j--)
		{
			temp_mat[arr_set] = mat[j * 4 + i];
			arr_set++;
		}
	}
	print_mat(temp_mat, 4 * 4);

	return 0;
}
// Prints the matrix
void print_mat(int mat[], int n)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", mat[i*4 + j]);
		}
		printf("\n");
	}
}
