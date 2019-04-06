#include "array.h"
#include "utils.h"

void	foreach_array(t_array *a, void (*callback)())
{
	size_t	idx;
	size_t	max;

	if (callback != NULL)
	{
		idx = 0;
		max = a->size / a->size_p;
		while (idx < max)
		{
			callback(get_ptr(a, idx), idx, a);
			++idx;
		}
	}
}
