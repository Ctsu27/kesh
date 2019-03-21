#include <stdlib.h>
#include "strft.h"

char	**ft_str2dup(char const **s)
{
	size_t	i;
	char	**res;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0)
		++i;
	if ((res = (char **)malloc(sizeof(char **) * (i + 1))))
	{
		i = 0;
		while (s[i] != NULL)
		{
			if ((res[i] = ft_strdup(s[i])) == NULL)
			{
				while (--i != (size_t)-1)
					free(res[i]);
				free(res);
				return (NULL);
			}
			++i;
		}
		res[i] = 0;
	}
	return (res);
}
