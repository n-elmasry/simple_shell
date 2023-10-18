#include "main.h"

/**
 * _putchar - Fucnction print a char
 * @c: inputed char
 * Return: 0 for success and 1 for failure
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
