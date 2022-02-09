#include "palindrome.h"

/**
 * is_palindrome - checks if a unsigned integer is a palindrome or not
 *
 * @n: long number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	char text[20];
	size_t i = 0, j = 0, t_length = 0;

	sprintf(text, "%lu", n);
	t_length = strlen(text);
	j = t_length - 1;

	for (; i < (t_length / 2); i++, j--)
		if (text[i] != text[j])
			return (0);
	return (1);
}
