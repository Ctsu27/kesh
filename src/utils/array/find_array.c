#include "array.h"
#include "utils.h"

void	*find_array(t_array *a, int (*cmp)(void *))
{
	size_t	max;
	size_t	idx;
	size_t	size_p;

	if (cmp == NULL)
		return (NULL);
	max = a->size;
	idx = 0;
	size_p = a->size_p;
	while (idx < max)
	{
		if (cmp(get_ptr(a->p, idx, size_p)) == 0)
			return (get_ptr(a->p, idx, size_p));
		++idx;
	}
	return (NULL);
}
