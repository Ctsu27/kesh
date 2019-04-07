#include "array.h"
#include "utils.h"

void	delete_array(t_array *a, void (*callback)(void *))
{
	size_t	idx;
	size_t	max;

	if (callback != NULL)
	{
		idx = 0;
		max = a->size / a->size_p;
		while (idx < max)
		{
			callback(get_ptr(a, idx));
			++idx;
		}
	}
	free(a);
}
