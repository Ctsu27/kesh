#include "array.h"

void	foreach_array(t_array *a, void (*callback)())
{
	size_t	idx;

	if (callback != NULL)
	{
		idx = 0;
		while (idx < a->size)
		{
			callback(a->p, a->size, a);
			++idx;
		}
	}
}
