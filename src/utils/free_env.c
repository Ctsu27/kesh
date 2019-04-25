#include <stdlib.h>

void	free_env(void *data, size_t length)
{
	char	**env;
	size_t	idx;

	env = (char **)data;
	idx = 0;
	while (idx < length)
	{
		free(env[idx]);
		++idx;
	}
}
