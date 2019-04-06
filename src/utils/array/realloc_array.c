#include "utils.h"
#include "array.h"
#include "memoryft.h"

void	realloc_array(t_array *a, size_t size, size_t size_p,
	unsigned char opt)
{
	t_array	tmp;

	if (a->p == NULL)
		*a = new_array(NULL, size, size_p, opt);
	else
	{
		tmp = *a;
		*a = new_array(NULL, size, size_p, opt);
		if (tmp.size < size)
		{
			ft_memcpy(a->p, tmp.p, tmp.size);
			a->size = tmp.size;
		}
		else
		{
			ft_memcpy(a->p, tmp.p, size);
			a->size = size;
		}
		free(tmp.p);
	}
}
