#ifndef KESH_H
# define KESH_H

enum			e_bool
{
	false = 0,
	true
};

typedef struct	s_kesh
{
	char	**env;
	char	*name_prog;
	_Bool	on;
}				t_kesh;

#endif
