#include "main.h"

/**
 * print_env - prints the environment
 * @args: arguments passed
 * @input: a pointer at beginning of args
 * Return: always 0,-1 if error
 */
int print_env(char **args, char __attribute__((unused)) **input)
{
	int index;
	char nc = '\n';

	if (!environ)
		return (-1);

	for (index = 0; environ[index]; index++)
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, &nc, 1);
	}

	(void)args;
	return (0);
}
