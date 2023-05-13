#include "headers.h"
/**
 * _puts - prints string to standard output
 * @str: input
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
