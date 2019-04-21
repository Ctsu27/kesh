#include <unistd.h>
#include "ft_printf.h"
#include "lexer_int.h"
#include "utils.h"

static char	*token_state_to_string(int const id)
{
	static char *s[TOKEN_SIZE + 1] = {
		[TOKEN_UNDEFINED] = "token undefined",
		[TOKEN_WSPACE] = "token wspace",
		[TOKEN_WORD] = "token word",
		[TOKEN_SQUOTE] = "token squote",
		[TOKEN_DQUOTE] = "token dquote",
		[TOKEN_BQUOTE] = "token bquote",
		[TOKEN_DOLLAR] = "token dollar",
		[TOKEN_TILDE] = "token tilde",
		[TOKEN_AND] = "token and",
		[TOKEN_OR] = "token or",
		[TOKEN_SEPARATOR] = "token separator",
		[TOKEN_PIPE] = "token pipe",
		[TOKEN_LESS] = "token less",
		[TOKEN_GREAT] = "token great",
		[TOKEN_DLESS] = "token dless",
		[TOKEN_DGREAT] = "token dgreat",
		[TOKEN_LESSAGG] = "token lessagg",
		[TOKEN_GREATAGG] = "token greatagg",
		[TOKEN_DLESSAGG] = "token dlessagg",
		[TOKEN_DGREATAGG] = "token dgreatagg",
		"not a token"
	};

	if (id >= 0 && id < TOKEN_SIZE)
		return (s[id]);
	return (s[TOKEN_SIZE]);
}

void		show_token(t_token **token)
{
	if (token == NULL || *token == NULL)
		ft_pf("<TOK> => (NULL)\n");
	else
	{
		ft_pf("<TOK> => (\n");
		ft_dpf(0, C_YELLOW_STR);
		ft_pf("  string: \"");
		write(1, (*token)->p, (*token)->len);
		ft_pf("\"\n");
		ft_dpf(0, C_X_STR);
		ft_dpf(0, C_CYAN_STR);
		ft_pf("  type: %s\n", token_state_to_string((*token)->token_type));
		ft_dpf(0, C_X_STR);
		ft_pf(")\n\n");
	}
}
