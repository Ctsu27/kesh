#include "array.h"
#include "lexer.h"
#include "lexer_int.h"

int		handler_simple_quote(size_t *idx, void *token, char const *input,
	int const *token_definition)
{
	t_token	*tiktok;
	size_t	i;

	i = *idx + 1;
	while ((int)input[i] != '\0'
		&& token_definition[(int)input[i]] != TOKEN_BASIC_SQUOTE)
		++i;
	if ((int)input[i] == '\0')
		return (1);
	if ((tiktok = (t_token *)malloc(sizeof(*tiktok))) == NULL)
		return (-2);
	tiktok->p = (unsigned char *)&input[*idx + 1];
	tiktok->len = i - (*idx + 1);
	tiktok->token_type = TOKEN_SQUOTE;
	if (array_push(token, (void *)&tiktok, 1) == EXIT_FAILURE)
	{
		free(tiktok);
		return (-2);
	}
	*idx = i + 1;
	return (0);
}
