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

/* external variables */
extern char **environ;

/* builtin.c */
int ctrld_builtin(char **args);
int cd_builtin(char **args);
int help_built(char **args);
int exit_builtin(char **args);
int _fork(char **arg, char **av, char **env, char *lineptr, int np, int c);

/* get_cmd.c */
*get_cmd(void);

/* get_env.c */
void _getenv(char **env);

/* strin_tools.c */
int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _putchar(char c);

char *_get_path(char **env);
int _values_path(char **arg, char **env);
char **tokenize(char *lineptr);
void _exit_command(char **args, char *lineptr, int _exit);


#endif /* SHELL_H */
