#include "utils.h"
#include "memoryft.h"
#include "array.h"

static inline size_t	new_array_ft_norm(void *p, void *src, size_t size)
{
	if (src != NULL)
	{
		ft_memcpy(p, src, size);
		return (size);
	}
	ft_bzero(p, size);
	return (0);
}

t_array					*new_array(void *src, size_t size, size_t size_p,
	unsigned char const opt)
{
	t_array	*res;
	void	*p;
	size_t	pow_of2;
	size_t	used_space;

	if ((res = (t_array *)malloc(sizeof(*res))) == NULL)
		return (NULL);
	pow_of2 = round_up_pow(size);
	if ((p = malloc(pow_of2)) == NULL)
	{
		free(res);
		return (NULL);
	}
	used_space = new_array_ft_norm(p, src, size);
	*res = init_array(p, pow_of2, used_space, size_p);
	*(unsigned char *)(*res).opt = opt;
	return (res);
}
