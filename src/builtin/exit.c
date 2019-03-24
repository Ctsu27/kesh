#include <stdlib.h>
#include "strft.h"
#include "utils.h"

int		builtin_exit(int argc, char **argv, __attribute__((unused))char **env)
{
	if (argc == 1)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
		exit(ft_atoi(argv[1]));
	ft_err(argv[0], "too many arguments");
	return (EXIT_FAILURE);
}
