#include <stdio.h>
#include <stdlib.h>
/**
 * main - allocates memory dynamically
 * Return: the array
 */
int main(void)
{
	char *arr = malloc(size);

	if (size == 0 || arr == 0)
	return (0);
	while (size--)
	arr[size] = c;
	return (arr);
}
