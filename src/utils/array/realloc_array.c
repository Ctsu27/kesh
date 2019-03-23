#include "utils.h"
#include "array.h"
#include "memoryft.h"

void	realloc_array(t_array *a, size_t size, size_t size_p)
{
	t_array	tmp;

	if (a->p == NULL)
		*a = new_array(NULL, size, size_p);
	else
	{
		tmp = *a;
		*a = new_array(NULL, round_up_pow(size), size_p);
		ft_memcpy(a->p, tmp.p, tmp.size);
		free(tmp.p);
	}
}
