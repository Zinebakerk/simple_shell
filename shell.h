#ifndef MAIN_H
#define MAIN_H

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
int exit_shell(char **args);
int ctrl_d_builtin(char **args);
int cd_builtin(char **args);
int help_builtin(char **args);

int _fork(char **arg, char **av, char **env, char *lineptr, int np, int c);

/* get_cmd.c */
 char *get_cmd(void);

 /* get_env.c */
void _getenv(char **env);

/* string_tools.c */
int str_cmp(char *s1, char *s2);
size_t strn_cmp(char *s1, char *s2, size_t n);
int str_len(char *s);
char *str_cpy(char *dest, char *src);
char *str_cat(char *dest, char *src);

/* tokenizer.c*/
char **toke_nize(char *ptr);

/* paths_value.c */
char *get_pat(char **env);
int get_path_values(char *arg[], char **env);

#endif
