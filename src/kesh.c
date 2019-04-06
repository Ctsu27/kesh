#include <stdio.h>


#include <stdlib.h>
#include "libft.h"
#include "kesh.h"
#include "utils.h"
#include "array.h"
#include "ft_printf.h"

int		main(int argc, char **argv, char **env)
{
	if (argc != 1)
	{
		ft_dpf(2, "usage: %s\n", argv[0]);
		return (EXIT_FAILURE);
	}
	else
	{
		t_array av;

		void	*tmp;

		tmp = (void *)ft_str2dup((char const **)env);
		av = new_array(tmp, ft_str2len(env) * sizeof(char *), sizeof(char *), 1);
		free(tmp);
		if (av.p != NULL)
		{
			foreach_array(&av, ft_putendl);
			foreach_array(&av, free);
			free(av.p);
		}
	}
	return (EXIT_SUCCESS);
}
