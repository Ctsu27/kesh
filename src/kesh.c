#include <stdlib.h>
#include "libft.h"
#include "kesh.h"
#include "utils.h"
#include "array.h"
#include "ft_printf.h"

// void	init_kesh(t_kesh *meta, char **env)
// {
// 	void	*tmp;
// 
// 	meta->on = 1;
// 	tmp = (void *)ft_str2dup((char const **)env);
// 	meta->env = new_array(tmp, ft_str2len(env) * sizeof(char *), sizeof(char *), OPT_PTR_CONTENT);
// 	free(tmp);
// }

int		main(int argc, char **argv, char **env)
{
	// t_kesh	meta_data;
	(void)env;
	
	if (argc != 1)
	{
		ft_dpf(2, "usage: %s\n", argv[0]);
		return (EXIT_FAILURE);
	}
	else
	{
		// init_kesh(&meta_data, env);
	}
	return (EXIT_SUCCESS);
}
