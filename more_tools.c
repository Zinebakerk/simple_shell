 #include "main.h"
/**
 * get_env - function that get the value of the environement variable
 * @env_var: wanted environment variable
 *
 * Return: the value of the env variable if success
 * or NULL otherwise
 */
char *get_env(const char *env_var)
{
	char *key;
	int i = 0;

	while (environ[i])
	{
		key = str_tok(environ[i], "=");
		if (str_cmp(env_var, key) == 0)
			return (str_tok(NULL, "\n"));
		i++;
	}
	free(key);
	return (NULL);
}
