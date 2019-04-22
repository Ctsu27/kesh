#include "array.h"
#include "lexer.h"
#include "lexer_int.h"

int		handler_word(size_t *idx, void *token, char const *input,
	int const *token_definition)
{
	t_token	*tiktok;
	size_t	i;

	i = *idx;
	while (token_definition[(int)input[i]] == TOKEN_BASIC_WORD
		|| (int)input[i] == '~')
		++i;
	if ((tiktok = (t_token *)malloc(sizeof(*tiktok))) == NULL)
		return (-2);
	tiktok->p = (unsigned char *)&input[*idx];
	tiktok->len = i - *idx;
	tiktok->token_type = TOKEN_WORD;
	if (array_push(token, (void *)&tiktok, 1) == EXIT_FAILURE)
	{
		free(tiktok);
		return (-2);
	}
	*idx = i;
	return (0);
}
