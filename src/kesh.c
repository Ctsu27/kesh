#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "kesh.h"
#include "utils.h"

int		main(int argc, char **argv, char **env)
{
	t_kesh	val;

	printf("Hello world !\n");
	if (argc != 1)
	{
		printf("usage: %s\n", argv[0]);
		return (EXIT_FAILURE);
	}
	else
	{
		printf("run shell\n");
		// init_env()
		if ((val.env = ft_str2dup((char const **)env)) != NULL)
		{
			ft_putendl2((char const **)val.env);
			val.name_prog = argv[0];
			val.on = true;
			// shell(val)
			// free_all()
			ft_mem2del((void ***)&val.env, ft_str2len(val.env));
		}
	}
	return (EXIT_SUCCESS);
}
