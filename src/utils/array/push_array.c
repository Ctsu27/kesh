#include "array.h"
#include "memoryft.h"
#include "utils.h"

void	push_array(t_array *a, void *src, size_t size)
{
	if (a->capacity - a->size < size)
		realloc_array(a, a->size + size, a->size_p);
	ft_memcpy(get_ptr(a->p, a->size / a->size_p, a->size_p), src, size);
	a->size += size;
}
