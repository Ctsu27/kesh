#include <stdlib.h>

void	*get_ptr(void const *pos,
			size_t const n_block, size_t const size_per_block)
{
	char	*res;

	res = (char *)pos;
	res += n_block * size_per_block;
	return ((void *)res);
}
