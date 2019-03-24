#include <stdlib.h>
#include "ioft.h"

int		ft_err(char *prog, char const *msg)
{
	ft_putstr_fd(prog, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
	return (EXIT_FAILURE);
}
