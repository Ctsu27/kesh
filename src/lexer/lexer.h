#ifndef LEXER_H
# define LEXER_H

typedef struct	s_token
{
	unsigned char	*p;
	size_t			len;
	int				token_type;
}				t_token;

extern int const	g_token_basic_definition[256];
extern int			(*g_token_basic_handler[7])();

int				lexer(unsigned char const *input, void *token,
	int const *token_definition, int (*token_handler[])());
#endif
