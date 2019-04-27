#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>

typedef struct	s_token
{
	unsigned char	*p;
	size_t			len;
	int				token_type;
}				t_token;

typedef struct	s_tokens
{
	t_token	**p;
	size_t	length;
	size_t	capacity;
	size_t	p_size;
}				t_tokens;

extern int const	g_token_basic_definition[256];
extern int			(*g_token_basic_handler[7])();

int				lexer(unsigned char const *input, void *token,
	int const *token_definition, int (*token_handler[])());
#endif
