#include "array.h"

void	*get_ptr(void *a, size_t const idx)
{
	return ((((t_array *)a)->opt[OPT_PTR_CONTENT_IDX] == 0)
		? ((char *)((t_array *)a)->p + idx * ((t_array *)a)->size_p)
		: ((void *)((char **)((t_array *)a)->p)[idx]));
}
