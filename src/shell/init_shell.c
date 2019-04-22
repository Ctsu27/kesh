#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
#include "kesh.h"
#include "utils.h"
#include "limits.h"

inline static int	cpy_env(t_kesh *meta, char **env)
{
	char	**tmp;

	if ((tmp = ft_str2dup((char const **)env)) == NULL)
	{
		array_delete(meta->env, NULL);
		return (-1);
	}
	if (array_push(meta->env, tmp, ft_str2len(tmp)) == EXIT_FAILURE)
	{
		free(tmp);
		array_delete(meta->env, &free_env);
		return (-1);
	}
	free(tmp);
	return (0);
}

inline static int	put_missing_env(t_kesh *meta, t_sv *mandatory_env_field,
	char **env)
{
	char	*str;
	size_t	idx;

	idx = 0;
	while (idx < 4)
	{
		if (!key_in_env(env, mandatory_env_field[idx].str,
				mandatory_env_field[idx].val))
		{
			str = ft_strdup(mandatory_env_field[idx].str);
			if (array_push(meta->env, &str, 1) == EXIT_FAILURE)
			{
				free(str);
				array_delete(meta->env, &free_env);
				return (-1);
			}
		}
		++idx;
	}
	return (0);
}

static int			pwd_in_env(void *s)
{
	char	**ppwd;

	ppwd = (char **)s;
	return (ft_strncmp(*ppwd, "PWD=", 4));
}

inline static int	init_pwd_env(t_kesh *meta, char **env)
{
	size_t	idx;
	char	***e;
	char	ppwd[PATH_MAX + 1];
	char	*cur_pwd;

	if (getcwd(ppwd, PATH_MAX) == NULL
		|| (cur_pwd = ft_strjoin("PWD=", ppwd)) == NULL)
		return (-1);
	if (!key_in_env(env, "PWD", 3))
	{
		if (array_push(meta->env, cur_pwd, 1) == EXIT_FAILURE)
			return (-1);
	}
	else
	{
		if ((idx = array_find_index(meta->env, &pwd_in_env)) == (size_t)-1)
			return (-1);
		e = meta->env->p;
		free(e[idx]);
		e[idx] = (char **)cur_pwd;
	}
	return (0);
}

inline int			init_shell(t_kesh *meta, char **env, char *name)
{
	t_sv	*mandatory_env_field;

	// WE LOVE FORTY TWO NORME YAAAAAAAY !!! BEST NORME OF THE COSMIC ! :DDD
	if ((meta->env = array_new(sizeof(char **))) == NULL)
		return (-1);
	if (ft_str2len(env) > 0)
	{
		if (cpy_env(meta, env) == -1)
			return (-1);
	}
	mandatory_env_field = (t_sv [4]){{"PATH=/bin:/usr/bin:/usr/sbin", 4},
		{"SHLVL=1", 5}, {"TERM=xterm-256color", 4}, {"HOME=/", 4}};
	if (put_missing_env(meta, mandatory_env_field, env) == -1)
		return (-1);
	init_pwd_env(meta, env);
	// TODO init termcaps
	meta->name_prog = name;
	meta->on = 1;
	return (0);
}

