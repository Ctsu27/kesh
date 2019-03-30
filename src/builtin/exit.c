#include <stdlib.h>
#include "array.h"
#include "strft.h"
#include "utils.h"

int		builtin_exit(int argc, t_array *argv, t_array *env)
{
	(void)env;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
		exit(ft_atoi((char const *)(((char **)argv->p)[1])));
	ft_err(((char **)argv->p)[0], "too many arguments");
	return (EXIT_FAILURE);
}
