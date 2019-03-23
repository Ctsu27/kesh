#include "array.h"

size_t	find_index_array(t_array *a, int (*cmp)(void *))
{
	size_t	max;
	size_t	idx;
	size_t	size_p;

	if (cmp == NULL)
		return ((size_t)-1);
	max = a->size;
	idx = 0;
	size_p = a->size_p;
	while (idx < max)
	{
		if (cmp(a->p + (idx * size_p)) == 0)
			return (idx);
		++idx;
	}
	return ((size_t)-1);
}
