#include "array.h"

inline t_array	init_array(void *p, size_t capacity, size_t size, size_t size_p)
{
	t_array	a;

	a.p = p;
	a.capacity = capacity;
	a.size = size;
	a.size_p = size_p;
	return (a);
}
