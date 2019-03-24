#include "array.h"
#include "ioft.h"

int		builtin_echo(int argc, t_array *argv, __attribute__((unused))t_array *env)
{
	char	**av;
	int		idx;

	idx = 1;
	if (idx < argc)
	{
		av = (char **)argv->p;
		ft_putstr(av[idx]);
		++idx;
		while (idx < argc)
		{
			ft_putchar(' ');
			ft_putstr(av[idx]);
			++idx;
		}
	}
	ft_putchar('\n');
	return (0);
}
