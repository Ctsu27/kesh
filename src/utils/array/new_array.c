#include "utils.h"
#include "memoryft.h"
#include "array.h"

t_array	new_array(void *src, size_t size, size_t size_p,
	unsigned char const opt)
{
	t_array	a;
	void	*p;
	size_t	pow_of2;
	size_t	used_space;

	pow_of2 = round_up_pow(size);
	if ((p = malloc(pow_of2)) == NULL)
		return (init_array(NULL, 0, 0, 0));
	if (src != NULL)
	{
		ft_memcpy(p, src, size);
		used_space = size;
	}
	else
	{
		ft_bzero(p, size);
		used_space = 0;
	}
	a = init_array(p, pow_of2, used_space, size_p);
	*(unsigned char *)a.opt = opt;
	return (a);
}
