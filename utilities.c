#include <stdlib.h>


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
