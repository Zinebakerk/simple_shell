#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void prints(char *str);
char **read_cmd(void);
void execmd(char **cmd, char *shell_name);
char *read_cmd(void);
char **split(char *buffer);
char **read_split_cmd(void);
#define PROMPT "#cisfun$ "
#endif
