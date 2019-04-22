#ifndef KESH_H
# define KESH_H

# include "array.h"

typedef struct	s_sv
{
	char	*str;
	size_t	val;
}				t_sv;

typedef struct	s_kesh
{
	t_array	*env;
	t_array	*ast;
	t_array	*token;
	char	*name_prog;
	_Bool	kill;
	_Bool	on;
}				t_kesh;

extern void		free_env(void *data, size_t length);
extern int 		init_shell(t_kesh *meta, char **env, char *name);
#endif
