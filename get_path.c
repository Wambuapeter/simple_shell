#include "main.h"
/**
 * get_path - locates a command in the path
 * @command: what to locate
 * Return: -1 if command not found
 */
char *get_path(char *command)
{
	char **path, *temp;
	lists_t *dirs, *head;
	struct stat buf;
	int size;

	path = _get_env("PATH");
	if (!path)
		return (NULL);

	dirs = get_path_dir(*path + 5);
	head = dirs;

	while (dirs)
	{
		temp = malloc(_strlen(dirs->dirs) + _strlen(command) + 2);
		if (!temp)
			return (NULL);

		_strcpy(temp, dirs->dirs);
		_strcat(temp);
		_strcat(command);

		size = buf->st_size;
		if (stat(temp, &buf) == 0)
		{
			free_list(head);
			return (temp);
		}

		dirs = dirs->next;
		free(temp);
	}
	free_list(head);

	return (NULL);
}
