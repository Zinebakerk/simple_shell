#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define PROMPT "$ "

extern char **environ;

/**
 * struct list_dir - singly linked list
 * @dir: directorie name
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 *
 */
typedef struct list_dir
{
	char *dir;
	struct list_dir *next;
} list_dir;

/**
 * struct builtins - bultin and its function
 * @builtin: the builtin
 * @f: function to handle the builtin
 *
 * Description: builtin and its function
 * for simple shell
 */
typedef struct builtins
{
	char *builtin;
	void (*f)(char **, char **, char **, int);
} builtins;

int _execute(char **arg, char **av, char **env, unsigned int idx);
char *_getenv(char *variable);
char *_getline(void);
char **split_line(char *line);

list_dir *build_dir_list(void);
char *_getpath(char *command);

list_dir *add_node_end(list_dir **head, const char *str);
void free_list_dir(list_dir *head);

int is_builtin(char *command);
void handle_builtin(char **command, char **av, char **env, int status);
void exit_shell(char **command, char **av, char **env, int status);
void print_env(char **command, char **av, char **env, int status);




int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

void free2Darray(char **array);
void print_error(char *name, unsigned int idx, char *cmd);
char *_itoa(unsigned int n);
void reverse_string(char str[], int len);

#endif
