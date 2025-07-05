#include <stdlib.h>
#include <unistd.h>


/**
 * get_env - returns the value of an environment variable
 * @name: environment variable
 * @env: environment variables array
 *
 * Return: returns the value of the environment variable
 */
char *get_env(char *name, char **env)
{
	int i = 0;
	char *c;
	int j;

	if (name == NULL || env == NULL)
		return (NULL);
	while (env[i] != NULL)
	{
		c = env[i];
		j = 0;
		while (*c != '\0' && name[j] != '\0' && name[j] == *c)
		{
			c++;
			j++;
			if (*c == '=' && name[j] == '\0')
				return (c + 1);
		}
		i++;
	}
	return (NULL);
}

/**
 * is_non_interactive_mode - determines if shell is in non-interactive mode
 *
 * Return: 1 if non-interactive mode, 0 if interactive mode
 */
int is_non_interactive_mode(void)
{
	return (!isatty(STDIN_FILENO));
}

/**
 * is_a_number - returns whether s is a number or not
 * @s: a null terminated string
 *
 * Return: 1 if s is a number or zero otherwise
 */
int is_a_number(char *s)
{
	if (*s == '\0')
		return (1);
	if (*s < '0' || *s > '9')
		return (0);
	return (is_a_number(s + 1));
}
