#include "utils.h"

size_t	round_up_pow(size_t n)
{
	if (n == 0)
		return (1);
	if (is_pow_of2((size_t const)n))
		return (n);
	--n;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n |= n >> 32;
	return (n + 1);
}
