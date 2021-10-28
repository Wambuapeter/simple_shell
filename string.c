#include "main.h"
/**
 *_strcmpdir - compare the string to incur the dir.
 * @str1: string.
 * @str2: string.
 *
 * Return: 0 if match and any other number otherwise.
 */
int _strcmpdir(char *str1, char *str2)
{
	for (int index = 0; (*str2 != '\0' && *str1 != '\0') && *str1 == *str2; str1++)
	{
		if (index == 3)
			break;
		index++;
		str2++;
	}

	return (*str1 - *str2);
}
/**
 * charput - writes the character like putchar
 * @chr: the character to print
 *
 * Return: on success 1, on error -1 and errno is set appropriately.
 */
int charput(char chr)
{
	return (write(1, &chr, 1));
}

/**
 * place - same as puts in C
 * @str0: a pointer that the integer we want to set to 402
 *
 * Return: void
 */
void place(char *str0)
{
	while (*str0 != '\0')
	{
		charput(*str0);
		str0++;
	}
}

/**
 * _str_len - string length.
 * @str0: My string.
 * Return: Length.
 */
int _strlen(char *str0)
{
	int index = 0;

	while (str0[index] != '\0')
		index++;

	return (index);
}

/**
 * str_concat - concatenate strings.
 * @str1: the first string.
 * @str2: the second string.
 * Return: strings.
 */
char *str_concat(char *str1, char *str2)
{
	char *bela;
	int len_str1, len_str2, index0 = 0, index1 = 0, peter;

	if (str1 == NULL)
		str1 == "";

	if ( str2 == NULL)
		str2 == "";

	len_str1 = _strlen(str1);
	
	len_str2 = _strlen(str2);

	bela = malloc(((len_str1) + (len_str2) + 1) * sizeof(char));

	if (bela == NULL)
		return (NULL);
	for (; index1 < len_str1; index1++)
	{
		bela[index1] = str1[index1];
	}

	for (index0 = len_str1, peter = 0; peter <= len_str2; index0++,peter++)
	{
		bela[index0] = str2[peter];
	}
	return (bela);
}

