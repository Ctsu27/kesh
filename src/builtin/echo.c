#include "array.h"
#include "utils.h"
#include "ioft.h"

int		builtin_echo(int argc, t_array *argv, t_array *env)
{
	int		idx;

	(void)env;
	idx = 1;
	if (idx < argc)
	{
		ft_putstr((char const *)get_ptr(argv, idx));
		++idx;
		while (idx < argc)
		{
			ft_putchar(' ');
			ft_putstr((char const *)get_ptr(argv, idx));
			++idx;
		}
	}
	ft_putchar('\n');
	return (0);
}
