#include <stdlib.h>

void	ft_mem2del(void ***mem, size_t const size)
{
	size_t	idx;

	if (mem != NULL && size > 0)
	{
		idx = 0;
		while (idx < size)
		{
			free((*mem)[idx]);
			++idx;
		}
		free(*mem);
		*mem = NULL;
	}
}
