#include "array.h"
#include "memoryft.h"
#include "utils.h"

int		array_realloc(t_array *a, size_t length, size_t p_size)
{
	void	*p;
	size_t	size_to_cpy;
	size_t	new_capacity;

	if (a == NULL)
		return (EXIT_FAILURE);
	new_capacity = round_up_pow(length * p_size);
	if (a->capacity != new_capacity)
	{
		if ((p = malloc(new_capacity)) == NULL)
			return (EXIT_FAILURE);
		size_to_cpy = a->length * p_size;
		if (size_to_cpy > new_capacity)
			size_to_cpy = new_capacity;
		ft_memcpy(p, a->p, size_to_cpy);
		free(a->p);
		a->p = p;
		a->capacity = new_capacity;
	}
	return (EXIT_SUCCESS);
}
