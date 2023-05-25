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
char *get_cmd(void);

/* get_env.c */
void _getenv(char **env);

/* strin_tools.c */
int str_cmp(char *s1, char *s2);
size_t str_ncmp(char *s1, char *s2, size_t n);
int str_len(char *s);
char *str_cpy(char *dest, char *src);
char *str_cat(char *dest, char *src);
/* tokenizer + path_values */
char *get_pat(char **env);
int  get_path_values(char *arg[], char **env);
char **toke_nize(char *ptr);



#endif /* SHELL_H */
