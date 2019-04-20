#include <stdlib.h>
#include "array.h"
#include "lexer_int.h"


#include "ft_printf.h"
#include "strft.h"

int		lexer(unsigned char const *input, void *token,
	int const *token_definition, int (*token_handler[])())
{
	t_array	*a;
	size_t	max;
	size_t	idx;
	int		ret;

	ft_pf("lexer input: [%s]\n", input);
	a = (t_array *)token;
	max = ft_strlen((char *)input);
	idx = 0;
	while (idx < max)
	{
		if (token_handler[token_definition[(int)input[idx]]] == NULL)
		{
			ft_dpf(2, "Function token: undefined near [%u] => '%c' :(\n", idx, input[idx]);
			return (-1);
		}
		ret = token_handler[token_definition[(int)input[idx]]](&idx, token, input, token_definition);
		if (ret != 0)
		{
			if (ret == -1)
				ft_dpf(2, "Unexpected token near [%u] => '%c' :(\n", idx, input[idx]);
			else if (ret == -2)
				ft_dpf(2, "error memory allocation\n");
			else if (ret == 1)
				ft_pf("need closure :D\n");
			return (ret);
		}
	}
	return (0);
}
