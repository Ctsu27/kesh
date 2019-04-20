#ifndef HANDLER_H
# define HANDLER_H

# include <stdlib.h>

int		handler_back_quote(size_t *idx, void *token, char const *input,
	int const *token_definition);
int		handler_double_quote(size_t *idx, void *token, char const *input,
	int const *token_definition);
int		handler_sh(size_t *idx, void *token, char const *input,
	int const *token_definition);
int		handler_simple_quote(size_t *idx, void *token, char const *input,
	int const *token_definition);
int		handler_white_space(size_t *idx, void *token, char const *input,
	int const *token_definition);
int		handler_word(size_t *idx, void *token, char const *input,
	int const *token_definition);
#endif
