#ifndef ARRAY_H
# define ARRAY_H

# include <stdlib.h>

/*
**	@param p allocated memory
**	@param capacity size of *p in bytes
**	@param size size of occupied in *p
*/

typedef struct	s_array
{
	void	*p;
	size_t	capacity;
	size_t	size;
	size_t	size_p;
}				t_array;

extern void		*find_array(t_array *a, int (*cmp)(void *));
extern size_t	find_index_array(t_array *a, int (*cmp)(void *));

extern t_array init_array(void *p, size_t capacity,
	size_t size, size_t size_p);

extern t_array new_array(void *src, size_t size, size_t size_p);

extern void push_array(t_array *a, void *src, size_t size);

extern void realloc_array(t_array *a, size_t size, size_t size_p);
#endif
