#include "array.h"
#include "memoryft.h"

int		array_push_at(t_array *a, void const *src, size_t n_element,
	size_t const at)
{
	void	*pos;
	size_t	used_space;
	size_t	size;

	size = n_element * a->p_size;
	used_space = a->length * a->p_size;
	if (a->capacity - used_space > size)
	{
		if (array_realloc(a, a->length + n_element, a->p_size) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		pos = a->p + at * a->p_size;
		ft_memmove(pos + size, pos, a->length * a->p_size - size);
		ft_memcpy(pos, src, size);
		a->length += n_element;
	}
	return (EXIT_SUCCESS);
}
