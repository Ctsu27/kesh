#ifndef LEXER_INT_H
# define LEXER_INT_H

# include <stdlib.h>

/*
**	";"		->		TOKEN_SEMICOLON
**	"|"		->		TOKEN_PIPE
**	"<"		->		TOKEN_LESS
**	">"		->		TOKEN_GREAT
**	"<<"	->		TOKEN_DLESS
**	">>"	->		TOKEN_DGREAT
**	"<&"	->		TOKEN_LESSAGG
**	">&"	->		TOKEN_GREATAGG
**	"<<&"	->		TOKEN_DLESSAGG
**	">>&"	->		TOKEN_DGREATAGG
*/

enum	e_token_basic_type
{
	TOKEN_BASIC_UNDEFINED,
	TOKEN_BASIC_WSPACE,
	TOKEN_BASIC_WORD, // maybe do a handler for identifier and control structure (bonus)
	TOKEN_BASIC_SQUOTE,
	TOKEN_BASIC_DQUOTE,
	TOKEN_BASIC_BQUOTE,
	TOKEN_BASIC_SH // need a handler to get the appropriate shell token
};

enum	e_token_shell_type
{
	TOKEN_SH_UNDEFINED,
	TOKEN_SH_SEMICOLON,
	TOKEN_SH_PIPE,
	TOKEN_SH_LESS,
	TOKEN_SH_GREAT,
	TOKEN_SH_DLESS,
	TOKEN_SH_DGREAT,
	TOKEN_SH_LESSAGG,
	TOKEN_SH_GREATAGG,
	TOKEN_SH_DLESSAGG,
	TOKEN_SH_DGREATAGG
};

enum	e_token_type
{
	TOKEN_UNDEFINED,
	TOKEN_WSPACE,
	TOKEN_WORD,
	TOKEN_SQUOTE,
	TOKEN_DQUOTE,
	TOKEN_BQUOTE,
	TOKEN_PIPE,
	TOKEN_LESS,
	TOKEN_GREAT,
	TOKEN_DLESS,
	TOKEN_DGREAT,
	TOKEN_LESSAGG,
	TOKEN_GREATAGG,
	TOKEN_DLESSAGG,
	TOKEN_DGREATAGG,
	TOKEN_SIZE
};

typedef struct	s_token
{
	unsigned char	*p;
	size_t			len;
	int				token_type;
}				t_token;

extern void		show_token(t_token **token);
#endif
