#include <stdlib.h>
#include "ft_printf.h"

int		ft_err(char *prog, char const *msg)
{
	ft_dpf(2, "%s: %s\n", prog, msg);
	return (EXIT_FAILURE);
}
