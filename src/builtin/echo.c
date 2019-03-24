#include "ioft.h"

int		builtin_echo(int argc, char **argv, __attribute__((unused))char **env)
{
	int		idx;

	idx = 1;
	if (idx < argc)
	{
		ft_putstr(argv[idx]);
		++idx;
		while (idx < argc)
		{
			ft_putchar(' ');
			ft_putstr(argv[idx]);
			++idx;
		}
	}
	ft_putchar('\n');
	return (0);
}
