#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

void prints(char *str);
void execmd(char **cmd, char *shell_name, char **env);
char *read_cmd(void);
char **split(char *buffer);
char **read_split_cmd(void);
char *handle_path(char *cmd);
unsigned int str_len(char *str);
char *str_cpy(char *dest, const char *src);
char *str_cat(char *dest, const char *src);
int str_cmp(const char *s1, const char *s2);
char *str_dup(const char *str);
char *str_tok(char *str, const char *delimiter);
char* str_chr(const char* str, int c);

#define PROMPT "#cisfun$ "
#endif
