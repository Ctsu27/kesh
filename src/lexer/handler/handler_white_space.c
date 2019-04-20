#include "array.h"
#include "lexer.h"
#include "lexer_int.h"

int		handler_white_space(size_t *idx, void *token, char const *input,
	int const *token_definition)
{
	(void)token;
	while (token_definition[(int)input[*idx]] == TOKEN_BASIC_WSPACE)
		*idx += 1;
	return (0);
}
