#ifndef LEXER_H
# define LEXER_H

/*
**	";"		->		TOKEN_SEMICOLON
**	"|"		->		TOKEN_PIPE
**	"<"		->		TOKEN_LESS
**	"<<"	->		TOKEN_DLESS
**	">"		->		TOKEN_GREAT
**	">>"	->		TOKEN_DGREAT
**	"<&"	->		TOKEN_LESSAND
**	">&"	->		TOKEN_GREATAND
*/

enum	e_token_state
{
	TOKEN_STATE_UNDEFINED,
	TOKEN_STATE_BASIC,
	TOKEN_STATE_QUOTE,
	TOKEN_STATE_EXPANSION,
	TOKEN_STATE_SIZE
};

enum	e_token_undefined_type
{
	TOKEN_UNDEFINED_UNDEFINED
};

enum	e_token_basic_type
{
	TOKEN_BASIC_UNDEFINED,
	TOKEN_BASIC_WSPACE,
	TOKEN_BASIC_WORD,
	TOKEN_BASIC_QUOTE,
	TOKEN_BASIC_SEMICOLON,
	TOKEN_BASIC_PIPE,
	TOKEN_BASIC_AND,
	TOKEN_BASIC_LESS,
	TOKEN_BASIC_GREAT,
	TOKEN_BASIC_EXPANSION
};

enum	e_token_shell_type
{
	TOKEN_KESH_UNDEFINED,
	TOKEN_KESH_WORD,
	TOKEN_KESH_SEMICOLON,
	TOKEN_KESH_PIPE,
	TOKEN_KESH_LESS,
	TOKEN_KESH_DLESS,
	TOKEN_KESH_GREAT,
	TOKEN_KESH_DGREAT,
	TOKEN_KESH_LESSAND,
	TOKEN_KESH_GREATAND
};

typedef struct	s_token
{
	char			*matcher;
	int				(*check_syntax)(void *);
	int				(*f)(void *);
	unsigned int	type;
}				t_token;
#endif
