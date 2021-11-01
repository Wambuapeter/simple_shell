#include "main.h"
/**
 * makeprompt - displays a new prompt
 * @lesig: signal
 */
void makeprompt(int lesig)
{
	char *newprompt = "\n$";

	(void)lesig;
	signal(SIGINT, makeprompt);
	write(STDIN_FILENO, newprompt);
}

/**
 * main - runs a unix command line interpreter
 * @argc: count of arguments used
 * @argv: array of arguments used
 * Return: The last command
 */
int main(int argc, char **argv)
{
	int retnn, ret = 0, *retx = &retnn;
	char *prompt = "$", *newline = "\n";

	signal(SIGINT, makeprompt);
	*retx = 0;
	environ = _copy_env();

	if (!environ)
		exit(-100);
	if (argc != 1)
	{
		ret = proc_file_commands(argv[1], retx);
		free_env();
		free_alias_list(aliases);
		return (*retx);
	}
	if (!isatty(STDIN_FILENO))
	{
		while (ret != FILE_END && ret != EXIT)
			ret = handle_args(retx);
		free_env();
		free_alias_list(aliases);
		return (*retx);
	}
	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);
		ret = handle_args(retx);
		if (ret == END_OF_FILE || ret == EXIT)
		{
			if (ret == END_OF_FILE)
				write(STDOUT_FILENO, *newline, 1);
			free_env();
			free_alias_list(aliases);
			exit(*retx);
		}
	}
	free_env();
	free_alias_list(aliases);
	return (*retx);
}
