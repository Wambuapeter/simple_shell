#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>

extern char **environ;

#define FILE_END -2
#define EXIT -3

/**
 * struct builtins - a struct defining builtin commands
 * @name: it's name
 * @f: pointer to the commands builtin
 */
typedef struct builtins_s
{
	char *name;
	int (*f)(char **argv, char **input);
} builtins_t;

typedef struct aliases_s
{
	char *name;
	char *value;
	struct aliases_s *next;
} aliases_t;

char *show_input(void);
void prompt(void);
char *_strcat(char *src);
int _strlen(char *str);
void place(char *str);
char *findfile(char *command);
char *find_command(char *command);
int compare(char *s1, char *s2);
int _strcmpdir(char *s1, char *s2);
int charput(char c);
void place(char *str);
char *str_concat(char *s1, char *s2);
int lookforslash(char *cmd);
int compareExit(char *s1, char *s2);
int compareEnv(char *s1, char *s2);
void execute_proc(char **cmd);
char **identify_string(char *parameter);
void controlC(int sig);

int handle_args(int *exe_ret);
void free_alias_list(aliases_t *head);
/* some builtin functions */
char **_copy_env(void);
void free_env(void);
char **_get_env(const char *var);

int proc_file_commands(char *file_path, int *retx);

#endif
