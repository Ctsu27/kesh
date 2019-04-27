#include "lexer.h"

void	free_token(void *arr, size_t len)
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

void	delete_token(void *arr, size_t len)
{
	t_token	**tokens;
	size_t	idx;

	tokens = (t_token **)arr;
	idx = 0;
	while (idx < len)
	{
		free(tokens[idx]->p);
		free(tokens[idx]);
		++idx;
	}
}
