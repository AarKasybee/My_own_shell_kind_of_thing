#include "headers.h"

/**
 * _strcspn - returns the length of the initial segment of a string
 * that contains no characters from a specified set of characters
 *
 * @str1: pointer to the string to be searched
 * @str2: pointer to the set of characters to be searched for
 *
 * Return: number of characters that were scanned before the
 * stop condition was met.
 */
size_t _strcspn(const char *str1, const char *str2)
{
	const char *s1 = str1;
	size_t count = 0;

	while (*s1)
	{
		const char *s2 = str2;

		while (*s2)
		{
			if (*s1 == *s2)
			{
				return (count);
			}
			s2++;
		}
		s1++;
		count++;
	}
	return (count);
}
