#include "sandpiles.h"

/**
 * print_grid - print a sandpile grid
 * @grid: matrix 3 x 3 sandpile
 *
 * Return: none
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * valid_sandpile - Checks if grid contains valid
 * @grid: matrix 3 x 3 sandpile
 *
 * Return: void
 */
static int valid_sandpile(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);

	return (1);
}

/**
 * sum_grids - make sum between grid1 and grid2
 * @grid1: first matrix 3 x 3 sandpile
 * @grid2: second matrix 3 x 3 sandpile
 *
 * Return: none
 */
static void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
}

/**
 * topple_sandpile - Move across the grid to operate a sum
 * @grid: matrix 3 x 3 sandpile
 * @temp_pile: helper grid with matrix 3 x 3 sandpile
 *
 * Return: none
 */
static void topple_sandpile(int grid[3][3], int temp_pile[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			temp_pile[i][j] = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
			{
				temp_pile[i][j] -= 4;
				if (i + 1 < 3)
					temp_pile[i + 1][j] += 1;
				if (i - 1 >= 0)
					temp_pile[i - 1][j] += 1;
				if (j + 1 < 3)
					temp_pile[i][j + 1] += 1;
				if (j - 1 >= 0)
					temp_pile[i][j - 1] += 1;
			}
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first 3 x 3 matrix
 * @grid2: second 3 x 3 matrix
 *
 * Return: none
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

	int temp_pile[3][3];

	sum_grids(grid1, grid2);
	while (valid_sandpile(grid1) == 0)
	{
		print_grid(grid1);
		topple_sandpile(grid1, temp_pile);
		sum_grids(grid1, temp_pile);
	}
}
