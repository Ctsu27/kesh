#include <stdlib.h>
#include "lexer.h"
#include "lexer_int.h"
#include "libft.h"
#include "ft_printf.h"
#include "kesh.h"
#include "parser.h"
#include "utils.h"

void	show_env(void *p, size_t idx)
{
	char	**s;

	s = (char **)p;
	ft_pf("env[%u] => %s\n", idx, *s);
}

inline static int	shell(t_kesh *meta)
{
	char	*line;
	int		ret;

	// array_foreach(meta->env, &show_env);
	ft_pf("enter %s\n", __FUNCTION__);
	while (meta->on)
	{
		meta->kill = 0;
		ft_dpf(0, "%s$>%s ", C_CYAN_STR, C_X_STR);
		// TODO change gnl to line edition
		ret = get_next_line(0, &line);
		if (ret == 1)
		{
			meta->token = array_new(sizeof(t_token *));
			if ((ret = lexer((unsigned char const *)line, meta->token,
							g_token_basic_definition, g_token_basic_handler)) != 0)
				array_delete(meta->token, &free_token);
				// ft_err(meta->name_prog, "Not enought memory for lexer");
			else
			{
				// TODO parser
				// array_foreach(meta->token, &show_token);
				if (token_adjust(&meta->token) == EXIT_SUCCESS)
				{
					// TODO build ast
					// if (ast_build() == EXIT_SUCCESS)
					// {
						// TODO run ast
					// }
					// TODO free all
					array_delete(meta->token, &delete_token);
				}
			}
			free(line);
		}
		else if (ret == 0)
		{
			free(line);
			meta->on = 0;
			ft_dpf(0, "exit\n");
		}
		else
		{
			free(line);
			return (ft_err(meta->name_prog, "Not enought memory"));
		}
	}
	return (EXIT_SUCCESS);
}

int					main(int argc, char **argv, char **env)
{
	t_kesh	meta_data;
	int		ret;
	
	if (argc != 1)
	{
		ft_dpf(2, "usage: %s\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (init_shell(&meta_data, env, argv[0]) != 0)
	{
		ft_dpf(2, "%s: Run out of memory\n", argv[0]);
		return (EXIT_FAILURE);
	}
	ret = shell(&meta_data);
	array_delete(meta_data.env, &free_env);
	return (ret);
}
