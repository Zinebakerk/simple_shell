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


char *_getline(void);
char **split_line(char *line);
int _execute(char **arg, char **av, char **env, int counter);
char *_getenv(char *variable);


list_dir *build_dir_list(void);
char *_getpath(char *command);
char *handle_path(char *command);


list_dir *add_node_end(list_dir **head, const char *str);
void free_list_dir(list_dir *head);


int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
