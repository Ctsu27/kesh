#include <stdlib.h>
#include "ioft.h"

inline static void	set_flag_set(_Bool *sets, char const *opt_str)
{
	size_t	idx;

	idx = 0;
	while (opt_str[idx] != '\0')
	{
		sets[(int)opt_str[idx]] = 1;
		++idx;
	}
}

inline static int	ft_getopt_flags(char const **argv, size_t const idx,
						_Bool const *flag_set, _Bool *flag)
{
	size_t	idx2;

	idx2 = 1;
	while (argv[idx][idx2] != '\0')
	{
		if (flag_set[(int)argv[idx][idx2]])
			flag[(int)argv[idx][idx2]] = 1;
		else
		{
			ft_putstr_fd(argv[0], 2);
			ft_putstr_fd(": illegal option -- ", 2);
			ft_putchar_fd(argv[idx][idx2], 2);
			ft_putchar_fd('\n', 2);
			return (-1);
		}
		++idx2;
	}
	return (0);
}

int			ft_getopt(int argc, char **argv, char const *opt_str, _Bool *flag)
{
	_Bool	flag_set[256];
	int		idx;

	set_flag_set(flag_set, opt_str);
	if (argc < 2)
		return (1);
	idx = 1;
	while (idx < argc && argv[idx][0] == '-' && argv[idx][1] != '\0')
	{
		if (argv[idx][1] == '-' && argv[idx][2] == '\0')
			return (idx + 1);
		if (ft_getopt_flags((char const **)argv, idx, flag_set, flag) == -1)
			return (-1);
		++idx;
	}
	return (idx);
}
