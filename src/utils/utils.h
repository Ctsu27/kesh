#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

# define C_YELLOW_STR "\033[31m"
# define C_CYAN_STR "\033[36m"
# define C_X_STR "\033[0m"

extern int		ft_err(char *prog, char const *msg);
extern int		ft_getopt(int argc, char **argv, char const *opt_str,
					_Bool *flag);
extern void		ft_mem2del(void ***mem, size_t const size);
extern void		ft_putendl2(char const **s);
extern char		**ft_str2dup(char const **s);
extern _Bool	is_pow_of2(size_t const n);
extern size_t	round_up_pow(size_t n);
#endif
