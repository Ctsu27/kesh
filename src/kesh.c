#include <stdlib.h>
#include "lexer.h"
#include "lexer_int.h"
#include "libft.h"
#include "ft_printf.h"
#include "kesh.h"
#include "utils.h"

void				free_env(void *data, size_t length)
{
	char	**env;
	size_t	idx;

	env = (char **)data;
	idx = 0;
	while (idx < length)
	{
		free(env[idx]);
		++idx;
	}
}

static void			free_token(void *arr, size_t len)
{
	t_token	**tokens;
	size_t	idx;

	tokens = (t_token **)arr;
	idx = 0;
	while (idx < len)
	{
		free(tokens[idx]);
		++idx;
	}
}

void	show_env(void *p, size_t idx)
{
	char	**s;

	s = (char **)p;
	ft_pf("env[%u] => %s\n", idx, *s);
}

inline static int	shell(t_kesh *meta)
{
	t_array	*token;
	char	*line;
	int		ret;

	array_show(meta->env);
	array_foreach(meta->env, &show_env);
	ft_pf("enter %s\n", __FUNCTION__);
	while (meta->on)
	{
		ft_dpf(0, "%s$>%s ", C_CYAN_STR, C_X_STR);
		// TODO change gnl to line edition
		ret = get_next_line(0, &line);
		if (ret == 1)
		{
			token = array_new(sizeof(t_token *));
			if ((ret = lexer((unsigned char const *)line, token,
				g_token_basic_definition, g_token_basic_handler)) != 0)
				ft_err(meta->name_prog, "Not enought memory for lexer");
			else
			{
				// TODO parser
				// TODO build ast
				// TODO run ast
				// TODO free all
				array_foreach(token, &show_token);
				array_delete(token, &free_token);
				free(line);
			}
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
