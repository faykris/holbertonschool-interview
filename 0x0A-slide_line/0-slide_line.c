#include "slide_line.h"

/**
 * slide_right - slide the array of ints to right
 *
 * @line: integer array pointer
 * @size: quantity of elements in array
 *
 * Return: None
 */
void slide_right(int *line, size_t size)
{
	int i, tmp, pos = size - 1;

	for (i = size - 1; i >= 0 && pos >= 0; i--)
	{
		while (pos > 0 && line[pos] != 0)
			pos--;
		if (line[i] != 0 && i < (int)pos)
		{
			tmp = line[i];
			line[i] = line[pos];
			line[pos] = tmp;
		}
	}
}

/**
 * slide_left - slide the array of ints to left
 *
 * @line: integer array pointer
 * @size: quantity of elements in array
 *
 * Return: None
 */
void slide_left(int *line, size_t size)
{
	size_t i, tmp, pos = 0;

	for (i = 0; i < size && pos < size; i++)
	{
		while (line[pos] != 0)
			pos++;
		if (line[i] != 0 && i > pos)
		{
			tmp = line[i];
			line[i] = line[pos];
			line[pos] = tmp;
		}
	}
}

/**
 * slide_line - move on a single horizontal line like 2048 game
 *
 * @line: integer array pointer
 * @size: quantity of elements in array
 * @direction: the direction of the merge left or right
 *
 * Return: 1 when sucess, otherwhise 0
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t s, p = 0;

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		for (s = 1; s < size && line[s] != 0; s++)
			if (line[s - 1] == line[s])
			{
				line[s - 1] *= 2;
				line[s] = 0;
				p = 1;
			}
		if (p)
			slide_left(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		for (s = size - 1; s > 0 && line[s - 1] != 0; s--)
			if (line[s - 1] == line[s])
			{
				line[s] *= 2;
				line[s - 1] = 0;
				p = 1;
			}
		if (p)
			slide_right(line, size);
	}
	else
		return (0);

	return (1);
}
