#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

extern void		ft_mem2del(void ***mem, size_t const size);
extern void		ft_putendl2(char const **s);
extern char		**ft_str2dup(char const **s);
extern void		*get_ptr(void const *pos,
						size_t const n_block, size_t const size_per_block);
extern _Bool	is_pow_of2(size_t const n);
extern size_t	round_up_pow(size_t n);
#endif
