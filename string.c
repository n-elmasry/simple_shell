#include "main.h"
/**
 * _strlen - find the lenght of  string
 * @s: input
 * @ len: lenght of string
 * Descrption:  function that count the lenght of  string
 * Return: len of string
*/

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
/**
 * _strcpy - copies a string from one pointer to another.
 * @src: string to be copied.
 * @dest: string to copy to..
 * Return: destination .
*/
char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - fuction conctanate two strings
 * @dest: sting destanation
 * @src: string to be concatanating
 * Return: dest
*/

char *_strcat(char *dest, const char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strdup - function copies a string from location to another
 * @str: inputes str to be copied
 * Return: NULL for filure and new_string for success
*/
char *_strdup(const char *str)
{
	int i = 0;
	char *new_string;

	if (str == NULL)
		return (NULL);

	while (str[i] != '\0')
		i++;
	new_string = malloc((i + 1) * sizeof(char));
	if (new_string == NULL)
		return (NULL);

	_strcpy(new_string, str);

	return (new_string);
}
/**
 * _strcmp - a fnction that compares two strings
 * @s1: first string
 * @s2: second string
 * Return: s1 - s2
*/

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
