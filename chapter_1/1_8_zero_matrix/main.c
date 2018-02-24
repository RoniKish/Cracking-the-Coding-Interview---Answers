#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void print_mat(int arr[], int n);
void mat_set(int mat[], int i, int j);

int main()
{
	int ran_num;
	srand((unsigned) time(NULL));
	ran_num = rand() % 16;
	int i, j;
	int *mat;
	int *temp_mat;
	mat = (int *)malloc(4 * 4 * sizeof(int));
	temp_mat = (int *)malloc(4 * 4 * sizeof(int));
	// creates the matrix
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			mat[i * 4 + j] = i * 4 + j;
			temp_mat[i * 4 + j] = i * 4 + j;
		}
	}
	// enter a random spot "0"
	mat[ran_num] = 0;
	// prints the matrix
	print_mat(mat, 4 * 4);
	printf("\n\n");

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (mat[i * 4 + j] == 0)
			{
				mat_set(temp_mat, i, j);
			}
		}
	}
	print_mat(temp_mat, 4 * 4);

	free(mat);
	free(temp_mat);
	return 0;
}
// prints a matrix
void print_mat(int mat[], int n)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", mat[i * 4 + j]);
		}
		printf("\n");
	}
}
// sets the lines and raws to 0
void mat_set(int mat[], int i, int j)
{
	int k;
	for (k = 0; k < 4; k++)
	{
		mat[k * 4 + j] = 0;
		mat[i * 4 + k] = 0;
	}
}
