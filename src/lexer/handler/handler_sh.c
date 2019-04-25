#include "array.h"
#include "lexer.h"
#include "lexer_int.h"
#include "strft.h"

static t_sh_handler const	g_token_sh_definition[] = {
	{
		.token_str = "&&",
		.token_size = 2,
		.token_type = TOKEN_AND
	},
	{
		.token_str = "||",
		.token_size = 2,
		.token_type = TOKEN_OR
	},
	{
		.token_str = "<<",
		.token_size = 2,
		.token_type = TOKEN_DLESS
	},
	{
		.token_str = ">>",
		.token_size = 2,
		.token_type = TOKEN_DGREAT
	},
	{
		.token_str = "<&",
		.token_size = 2,
		.token_type = TOKEN_LESSAGG
	},
	{
		.token_str = "&<",
		.token_size = 2,
		.token_type = TOKEN_LESSAGG
	},
	{
		.token_str = ">&",
		.token_size = 2,
		.token_type = TOKEN_GREATAGG
	},
	{
		.token_str = "&>",
		.token_size = 2,
		.token_type = TOKEN_GREATAGG
	},
	{
		.token_str = ";",
		.token_size = 1,
		.token_type = TOKEN_SEPARATOR
	},
	{
		.token_str = "|",
		.token_size = 1,
		.token_type = TOKEN_PIPE
	},
	{
		.token_str = "<",
		.token_size = 1,
		.token_type = TOKEN_LESS
	},
	{
		.token_str = ">",
		.token_size = 1,
		.token_type = TOKEN_GREAT
	}
};

inline static int	is_expansion(char const c)
{
	return ((c == '$' || c == '~'));
}

static int			sh_controller_operator(t_token *toktok,
	unsigned char const *input, size_t *idx)
{
	size_t	max;
	size_t	i;

	max = sizeof(g_token_sh_definition) / sizeof(*g_token_sh_definition);
	i = 0;
	while (i < max && ft_strncmp(g_token_sh_definition[i].token_str,
			(char const *)input + *idx,
			g_token_sh_definition[i].token_size) != 0)
		++i;
	if (i == max)
		return (-1);
	toktok->p = (unsigned char *)&input[*idx];
	toktok->len = g_token_sh_definition[i].token_size;
	toktok->token_type = g_token_sh_definition[i].token_type;
	return (0);
}

static int			sh_expansion(t_token *toktok, unsigned char const *input,
	size_t *idx, int const *token_definition)
{
	int		token_type;
	size_t	i;

	i = *idx + 1;
	if (input[*idx] == '$')
	{
		token_type = TOKEN_DOLLAR;
		while (token_definition[(int)input[i]] == TOKEN_BASIC_WORD
				&& input[i] != '/')
			++i;
	}
	else
		token_type = TOKEN_TILDE;
	toktok->p = (unsigned char *)&input[*idx];
	toktok->len = i - *idx;
	toktok->token_type = token_type;
	return (0);
}

int					handler_sh(size_t *idx, void *token,
	char const *input, int const *token_definition)
{
	t_token	*tiktok;
	t_token	tmp;
	int		(*handler[2])() = {
		&sh_controller_operator,
		&sh_expansion
	};

	if (handler[is_expansion(input[*idx])](&tmp, input,
			idx, token_definition) == -1)
		return (-1);
	if ((tiktok = (t_token *)malloc(sizeof(*tiktok))) == NULL)
		return (-2);
	*tiktok = tmp;
	if (array_push(token, (void *)&tiktok, 1) == EXIT_FAILURE)
	{
		free(tiktok);
		return (-2);
	}
	*idx = *idx + tiktok->len;
	return (0);
}
