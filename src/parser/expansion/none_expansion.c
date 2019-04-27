#include "lexer.h"
#include "memoryft.h"

#include "ft_printf.h"
void	*none_expansion(void *token)
{
	ft_pf("Enter %s:%s\n", __FILE__, __func__);
	t_token	**tiktok;
	t_token	*res;

	tiktok = (t_token **)token;
	if ((res = (t_token *)malloc(sizeof(*res))) == NULL)
		return (NULL);
	if ((res->p = (unsigned char *)malloc(sizeof(char)
				* ((*tiktok)->len + 1))) == NULL)
	{
		free(res);
		return (NULL);
	}
	ft_memcpy(res->p, (*tiktok)->p, (*tiktok)->len);
	res->p[(*tiktok)->len] = '\0';
	res->token_type = (*tiktok)->token_type;
	res->len = (*tiktok)->len;
	return (res);
}
