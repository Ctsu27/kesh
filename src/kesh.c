#include <stdlib.h>
#include "lexer.h"
#include "lexer_int.h"
#include "libft.h"
#include "ft_printf.h"
#include "kesh.h"
#include "utils.h"


#include <unistd.h>

static void			free_env(void *data, size_t length)
{
	char	**env;
	size_t	idx;

	env = (char **)data;
	idx = 0;
	while (idx < length)
	{
		// ft_pf("freeing: env[%u] => [%p]\n", idx, env[idx]);
		free(env[idx]);
		++idx;
	}
}

static void	free_token(void *arr, size_t len)
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

inline static int	init_kesh(t_kesh *meta, char **env, char *name)
{
	size_t	idx;
	char	**tmp;

	if ((meta->env = array_new(sizeof(char **))) == NULL)
		return (-1);
	if ((tmp = ft_str2dup((char const **)env)) == NULL)
	{
		array_delete(meta->env, NULL);
		return (-1);
	}
	idx = 0;
	while (tmp[idx] != 0)
	{
		if (array_push(meta->env, tmp + idx, 1) == EXIT_FAILURE)
		{
			ft_mem2del((void ***)&tmp, ft_str2len(tmp));
			array_delete(meta->env, &free_env);
			return (-1);
		}
		++idx;
	}
	free(tmp);
	meta->name_prog = name;
	meta->on = 1;
	return (0);
}

int		read_line(char **input)
{
	int		ret;
	char	buf[2];

	buf[1] = '\0';
	ret = 1;
	while (ft_strchr(*input, '\n') == NULL && ret > 0)
	{
		if ((ret = read(0, buf, 1)) == -1)
			return (-1);
		else if (ret > 0)
		{
			if ((*input = ft_strjoin_free(*input, buf, 0b10)) == NULL)
				return (-1);
		}
		else
			return (0);
	}
	(*input)[ft_strlen(*input) - 1] = '\0';
	return (1);
}

inline static int	kesh(t_kesh *meta)
{
	t_array	*token;
	char	*line;
	int		ret;

	ft_pf("enter %s\n", __FUNCTION__);
	while (meta->on)
	{
		ft_dpf(0, "%s$>%s ", C_CYAN_STR, C_X_STR);
		// ret = get_next_line(0, &line);
		if ((line = ft_strnew(0)) == NULL)
			return (ft_err(meta->name_prog, "Not enought memory"));
		ret = read_line(&line);
		if (ret == 1)
		{
			token = array_new(sizeof(t_token *));
			if ((ret = lexer((unsigned char const *)line, token,
				g_token_basic_definition, g_token_basic_handler)) != 0)
				ft_err(meta->name_prog, "Not enought memory for lexer");
			else
			{
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
	// ft_pf("env:\n");
	// ft_putendl2((char const **)env);
	if (init_kesh(&meta_data, env, argv[0]) != 0)
	{
		ft_dpf(2, "%s: Run out of memory\n", argv[0]);
		return (EXIT_FAILURE);
	}
	ret = kesh(&meta_data);
	array_delete(meta_data.env, &free_env);
	return (ret);
}
