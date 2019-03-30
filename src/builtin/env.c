#include "array.h"
#include "strft.h"
#include "utils.h"

static void	**cpy(t_array const *env)
{
	char	**e;

	(void)env;
	e = NULL;
	return ((void **)e);
}

static void	**empty(void)
{
	return ((void **)malloc(sizeof(char **)));
}

int			builtin_env(int argc, t_array *argv, t_array *env)
{
	static void		**(*cpy_env[2])() = {&cpy, &empty};
	char			**e;
	int				idx;
	_Bool			flag[256];
	char			**av;

	av = (char **)argv->p;
	idx = ft_getopt(argc, av, "i", flag);
	if (idx == -1)
		return (EXIT_FAILURE);
	e = (char **)cpy_env[(int)flag['i']]((t_array const *)env);
	// while setenv
	if (idx == argc)
		ft_putendl2((char const **)e);
	else
	{
		// run_bin(env);
	}
	ft_mem2del((void ***)&e, ft_str2len(e));
	return (EXIT_SUCCESS);
}
