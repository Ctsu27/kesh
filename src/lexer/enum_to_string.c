#include "lexer_int.h"

inline char	*token_state_to_string(int const id)
{
	char const *s[TOKEN_STATE_SIZE] = {
		"TOKEN_STATE_UNDEFINED",
		"TOKEN_STATE_BASIC",
		"TOKEN_STATE_SQUOTE",
		"TOKEN_STATE_DQUOTE",
		"TOKEN_STATE_BQUOTE",
		"TOKEN_STATE_EXPANSION"
	};

	return (s[id]);
}
