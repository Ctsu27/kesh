#include "array.h"
#include "lexer.h"
#include "lexer_int.h"

int		handler_undefined(size_t *idx, void *token, char const *input,
	int const *token_definition)
{
	t_token	*tiktok;

	(void)token_definition;
	if ((tiktok = (t_token *)malloc(sizeof(*tiktok))) == NULL)
		return (-2);
	tiktok->p = (unsigned char *)&input[*idx];
	tiktok->len = 1;
	tiktok->token_type = TOKEN_UNDEFINED;
	if (array_push(token, (void *)&tiktok, 1) == EXIT_FAILURE)
	{
		free(tiktok);
		return (-2);
	}
	*idx += 1;
	return (0);
}
