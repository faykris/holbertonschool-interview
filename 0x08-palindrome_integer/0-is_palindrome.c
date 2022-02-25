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
	int ltr_number = n, rtl_number = 0, modulus = 0;

	while (n != 0)
	{
		modulus = n % 10;
		rtl_number *= 10;
		rtl_number += modulus;
		n /= 10;
	}

	return (ltr_number == rtl_number ? 1 : 0);
}
