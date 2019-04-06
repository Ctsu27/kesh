#include "array.h"
#include "memoryft.h"
#include "utils.h"

void	push_at_array(t_array *a, void *src, size_t size, size_t at)
{
	if (a->capacity - a->size < size)
		realloc_array(a, a->size + size, a->size_p, *(unsigned char *)a->opt);
	ft_memmove(get_ptr(a, (size + at) / a->size_p),
			get_ptr(a, at / a->size_p),
			a->size - at);
	ft_memcpy(get_ptr(a, at / a->size_p), src, size);
	a->size += size;
}
