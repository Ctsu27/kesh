#include "array.h"
#include "ft_printf.h"

void	array_show(t_array *a)
{
	if (a == NULL)
		ft_pf("<A> => (NULL)\n");
	else
	{
		ft_pf("<A> => (\n");
		ft_pf("  p: %p\n", a->p);
		ft_pf("  length: %u\n", a->length);
		ft_pf("  capacity: %u\n", a->capacity);
		ft_pf("  sizeof: %u\n", a->p_size);
		ft_pf(")\n\n");
	}
}
