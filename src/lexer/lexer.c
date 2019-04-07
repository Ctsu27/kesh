#include <stdlib.h>
#include "array.h"
#include "lexer_int.h"

#include "ft_printf.h"
#include "strft.h"

// int		lexer(t_array *input)
int		lexer(char *input, t_array *token)
{
	size_t	max;
	size_t	idx;
	int		ret;

	(void)token;
	ft_pf("lexer input: [%s]\n", input);
	ft_pf("sizeof(g_token_definition) = %u\n", (unsigned int)sizeof(g_token_definition));
	ft_pf("sizeof(g_token_basic_handler) = %u\n", (unsigned int)sizeof(g_token_basic_handler));
	max = ft_strlen(input);
	idx = 0;
	while (idx < max)
	{
		if (g_token_basic_handler[g_token_definition[TOKEN_STATE_BASIC][(int)input[idx]]] == 0)
		{
			ft_dpf(2, "Function token: undefined near [%u] => '%c' :(\n", idx, input[idx]);
			return (-1);
		}
		ret = g_token_basic_handler[g_token_definition[TOKEN_STATE_BASIC][(int)input[idx]]](&idx, &token, input[idx]);
		if (ret != 0)
		{
			if (ret == -1)
				ft_dpf(2, "Something happened near [%u] => '%c' :(\n", idx, input[idx]);
				else if (ret == 1)
				ft_pf("need closure :D\n");
			return (ret);
		}
		++idx;
	}
	return (0);
}
