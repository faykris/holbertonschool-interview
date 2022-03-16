#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 *
 * @level: level to be printed
 *
 * Return: none
 */
void menger(int level)
{
	int i, j, side, row, col;
	char c;

	if (level < 0)
		return;

	side = pow(3, level);
	for (i = 0; i < side; i++)
	{
		for (j = 0; j < side; j++)
		{
			row = i;
			col = j;
			c = '#';
			while (row || col)
			{
				if (row % 3 == 1 && col % 3 == 1)
					c = ' ';
				row /= 3;
				col /= 3;
			}
			printf("%c", c);
		}
		printf("\n");
	}

}
