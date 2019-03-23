#include "utils.h"
#include "memoryft.h"
#include "array.h"

t_array	new_array(void *src, size_t size, size_t size_p)
{
	void	*p;
	size_t	pow_of2;

	pow_of2 = round_up_pow(size);
	if ((p = malloc(pow_of2)) == NULL)
		return (init_array(NULL, 0, 0, 0));
	if (src != NULL)
		ft_memcpy(p, src, pow_of2);
	else
		ft_bzero(p, pow_of2);
	return (init_array(p, pow_of2, 0, size_p));
}
