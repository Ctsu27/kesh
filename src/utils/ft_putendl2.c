#include <stdlib.h>
#include "ioft.h"

void	ft_putendl2(char const **s)
{
	size_t	idx;

	if (s != NULL)
	{
		idx = 0;
		while (s[idx] != 0)
		{
			ft_putendl(s[idx]);
			++idx;
		}
	}
}
