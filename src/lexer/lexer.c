#include <stdlib.h>
#include "array.h"
#include "lexer_int.h"

#include "ft_printf.h"
#include "strft.h"

// int		lexer(t_array *input)
int		lexer(char const *input, void *token,
	int const *token_definition, int (*token_handler[])())
{
	size_t	max;
	size_t	idx;
	int		ret;

	(void)token;
	ft_pf("lexer input: [%s]\n", input);
	max = ft_strlen(input);
	idx = 0;
	while (idx < max)
	{
		if (token_handler[token_definition[(int)input[idx]]] == 0)
		{
			ft_dpf(2, "Function token: undefined near [%u] => '%c' :(\n", idx, input[idx]);
			return (-1);
		}
		ret = token_handler[token_definition[(int)input[idx]]](&idx, &token, input[idx]);
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
