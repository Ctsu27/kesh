#ifndef ARRAY_H
# define ARRAY_H

# include <stdlib.h>

/*
**	@param p allocated memory
**	@param capacity size of *p in bytes
**	@param size size in size_p byte
**	@param opt boolean flags:
**		- bit 1 -> content is a pointer
*/

# define OPT_PTR_CONTENT_IDX 0

# define OPT_PTR_CONTENT 0x1

typedef struct	s_array
{
	void	*p;
	size_t	capacity;
	size_t	size;
	size_t	size_p;
	_Bool	opt[8];
}				t_array;

extern void		*find_array(t_array *a, int (*cmp)(void *));
extern size_t	find_index_array(t_array *a, int (*cmp)(void *));
extern void		foreach_array(t_array *a, void (*callback)());

extern t_array	init_array(void *p, size_t capacity,
	size_t size, size_t size_p);

extern t_array new_array(void *src, size_t size, size_t size_p,
	unsigned char const opt);

extern void		push_array(t_array *a, void *src, size_t size);
extern void		push_at_array(t_array *a, void *src, size_t size, size_t at);

extern void		realloc_array(t_array *a, size_t size, size_t size_p,
	unsigned char opt);
#endif
