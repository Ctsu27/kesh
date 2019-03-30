#include <stdio.h>
#include <stdlib.h>
#include "chai.h"
#include "ft_printf.h"

static int	check_di(char *fmt, int fd)
{
	ft_dpf(fd, fmt, 1);
	printf(fmt, 1);
	return (1 ? OK : KO);
}

static int	check_u(char *fmt, int fd)
{
	ft_dpf(fd, fmt, (unsigned int)-1);
	printf(fmt, (unsigned int)-1);
	return (1 ? OK : KO);
}

static int	check_x(char *fmt, int fd)
{
	ft_dpf(fd, fmt, 42);
	printf(fmt, 42);
	return (1 ? OK : KO);
}

static int	check_X(char *fmt, int fd)
{
	ft_dpf(fd, fmt, 42);
	return (1 ? OK : KO);
}

static int	check_c(char *fmt, int fd)
{
	ft_dpf(fd, fmt, '!');
	printf(fmt, '!');
	return (1 ? OK : KO);
}

static int	check_s(char *fmt, int fd)
{
	ft_dpf(fd, fmt, "un print string mdr");
	printf(fmt, "un print string mdr");
	ft_dpf(fd, fmt, NULL);
	printf(fmt, NULL);
	return (1 ? OK : KO);
}

int			main(void)
{
	t_chai		test[] = {
		{"Should handle conversion di", &check_di, NULL},
		{"Should handle conversion u", &check_u, NULL},
		{"Should handle conversion x", &check_x, NULL},
		{"Should handle conversion X", &check_X, NULL},
		{"Should handle conversion c", &check_c, NULL},
		{"Should handle conversion s", &check_s, NULL}
	};
	char		*fmt[] = {
		"coucou d[%d]\n",
		"coucou u[%u]\n",
		"coucou x[%x]\n",
		"coucou X[%X]\n",
		"coucou c[%c]\n",
		"coucou s[%s]\n"
	};
	int			ret = OK;
	int			ret_test = OK;

	printf("ft_dpf[%zu]:\n", sizeof(test) / sizeof(*test));
	for (size_t idx = 0, max = sizeof(test) / sizeof(*test);
		 idx < max;
		 ++idx)
	{
		if (test[idx].apply_before != NULL)
			test[idx].apply_before();
		ret_test |= test[idx].check(fmt[idx], 1);
		if (ret_test == OK)
			printf(PAD "%s[v]%s", GREEN, X);
		else
			printf(PAD "%s[x]%s", RED, X);
		printf(" %s\n", test[idx].msg);
		ret |= ret_test;
	}

	if (ret == KO)
		ret = EXIT_FAILURE;
	else
		ret = EXIT_SUCCESS;
	return (ret);
}
