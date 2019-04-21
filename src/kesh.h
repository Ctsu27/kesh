#ifndef KESH_H
# define KESH_H

#include "array.h"

typedef struct	s_kesh
{
	t_array	*env;
	char	*name_prog;
	_Bool	on;
}				t_kesh;

#endif
