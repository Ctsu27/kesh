#include "array.h"
#include "lexer.h"
#include "lexer_int.h"
#include "expansion.h"
#include "utils.h"

#include "ft_printf.h"
// TOKEN_WORD,                 => keep
// TOKEN_SQUOTE,               => keep
// TOKEN_DQUOTE,               => \ ` " $ (*) are not keeped
// TOKEN_BQUOTE,               => let the ast run this state
// TOKEN_DOLLAR,               => replace by var in **env
// TOKEN_TILDE,                => replace by HOME in **env
// TOKEN_AND,                  => keep
// TOKEN_OR,                   => keep
// TOKEN_SEPARATOR,            => keep
// TOKEN_PIPE,                 => keep
// TOKEN_LESS,                 => keep
// TOKEN_GREAT,                => keep
// TOKEN_DLESS,                => keep / heredoc
// TOKEN_DGREAT,               => keep
// TOKEN_LESSAGG,              => keep
// TOKEN_GREATAGG,             => keep

static void *(*g_apply_expansion[TOKEN_SIZE])() = {
	[TOKEN_UNDEFINED] = NULL,
	[TOKEN_WSPACE] = NULL,
	[TOKEN_WORD] = &none_expansion,
	[TOKEN_SQUOTE] = &none_expansion,
	[TOKEN_DQUOTE] = NULL,
	[TOKEN_BQUOTE] = NULL,
	[TOKEN_DOLLAR] = NULL,
	[TOKEN_TILDE] = NULL,
	[TOKEN_AND] = &none_expansion,
	[TOKEN_OR] = &none_expansion,
	[TOKEN_SEPARATOR] = &none_expansion,
	[TOKEN_PIPE] = &none_expansion,
	[TOKEN_LESS] = &none_expansion,
	[TOKEN_GREAT] = &none_expansion,
	[TOKEN_DLESS] = NULL,
	[TOKEN_DGREAT] = &none_expansion,
	[TOKEN_LESSAGG] = &none_expansion,
	[TOKEN_GREATAGG] = &none_expansion
};

static void	*apply_expansion(void *p)
{
	ft_pf("Enter %s:%s\n", __FILE__, __func__);
	t_token	**token;

	token = (t_token **)p;
	show_token(token);
	if (g_apply_expansion[(*token)->token_type] == NULL)
	{
		ft_dpf(2, "apply expansion == NULL\n");
		return (NULL);
	}
	return (g_apply_expansion[(*token)->token_type](token));
}

int			token_adjust(t_array **token)
{
	ft_pf("Enter %s:%s\n", __FILE__, __func__);
	t_array	*tiktok;

	// apply expansion and heredoc (with new tokens array) (do not change token type)
	// TODO add free tokens function in array_map
	if ((tiktok = array_map(*token, &apply_expansion, &free_token)) == NULL)
		return (EXIT_FAILURE);
	array_delete(*token, &free_token);
	*token = (t_array *)tiktok;
	// if all good
	// 	-> join joinable tokens (the new array one) (with the old array token => token[idx]->type)
	ft_pf("exit success %s:%s\n", __FILE__, __func__);
	return (EXIT_SUCCESS);
}
