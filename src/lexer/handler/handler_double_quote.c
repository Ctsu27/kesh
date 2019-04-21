#include "array.h"
#include "lexer.h"
#include "lexer_int.h"

inline static void	very_usefull_function_because_of_ft_norme(t_token *tiktok,
	char const *pos, size_t len)
{
	tiktok->p = (unsigned char *)pos;
	tiktok->len = len;
	tiktok->token_type = TOKEN_DQUOTE;
}

int					handler_double_quote(size_t *idx, void *token,
	char const *input, int const *token_definition)
{
	t_token	*tiktok;
	size_t	i;

	i = *idx + 1;
	while ((int)input[i] != '\0')
	{
		if (token_definition[(int)input[i]] == TOKEN_BASIC_DQUOTE)
			break ;
		if ((int)input[i] == '\\')
			++i;
		++i;
	}
	if ((int)input[i] == '\0')
		return (1);
	if ((tiktok = (t_token *)malloc(sizeof(*tiktok))) == NULL)
		return (-2);
	very_usefull_function_because_of_ft_norme(tiktok, &input[*idx + 1],
		i - (*idx + 1));
	if (array_push(token, (void *)&tiktok, 1) == EXIT_FAILURE)
	{
		free(tiktok);
		return (-2);
	}
	*idx = i + 1;
	return (0);
}
