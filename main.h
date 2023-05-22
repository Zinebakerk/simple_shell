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
#define PROMPT "#cisfun$ "
#endif
