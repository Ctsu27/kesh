#ifndef LEXER_H
# define LEXER_H


extern int const	g_token_basic_definition[256];
extern int			(*g_token_basic_handler[12])();

int					lexer(unsigned char const *input, void *token,
	int const *token_definition, int (*token_handler[])());
#endif
