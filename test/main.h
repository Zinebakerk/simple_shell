#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;
typedef struct builtin
{
	char *cmd;
	void (*f)(char **cmd, char *shell_name);
} builtin;


void prints(char *str);
void execmd(char **cmd, char *shell_name, char **env);
char *read_cmd(void);
char **split(char *buffer);
char **read_split_cmd(void);
char *handle_path(char *cmd);
char *get_env(const char *env_var);
/* bultin */
void exit_builtin(char **cmd, char *shell_name);
int handle_builtin(char **cmd, char *shell_name);
void env_builtin(char **cmd, char *shell_name);
void free_2Darray(char **arr);


#define PROMPT "#cisfun$ "
#endif
