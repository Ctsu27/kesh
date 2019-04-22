#include "strft.h"

int		key_in_env(char **env, char *key, int size)
{
	int		i;

	i = 0;
	while (env[i] != 0)
	{
		if (ft_strncmp(env[i], key, size) == 0 && env[i][size] == '=')
			return (1);
		i++;
	}
	return (0);
}

char	**key_chr(char **env, char *key, int size)
{
	int		i;

	i = 0;
	while (env[i] != 0)
	{
		if (ft_strncmp(env[i], key, size) == 0 && env[i][size] == '=')
			return (env + i);
		i++;
	}
	return (NULL);
}

char	*ft_getenv(char **env, char *name)
{
	unsigned int	len;
	char			*target;

	len = ft_strlen(name);
	if (key_in_env(env, name, len) == 0)
		return (NULL);
	target = *key_chr(env, name, len) + len + 1;
	return (target);
}
