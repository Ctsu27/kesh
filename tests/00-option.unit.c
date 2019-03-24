#include <stdio.h>
#include <stdlib.h>
#include "chai.h"
#include "utils.h"

typedef struct	s_payload
{
	int		argc;
	char	**argv;
	char	*opt_str;
	char	*expected_flag;
	int		expected_ret;
	_Bool	flag[256];
}				t_payload;

static int	check_error_option(int argc, char **argv, char const *opt_str, _Bool *flag,
				int expected_ret, char *expected_flag)
{
	int		ret;

	ret = ft_getopt(argc, argv, opt_str, flag);
	return (ret == -1 ? OK : KO);
}

static int	check_option(int argc, char **argv, char const *opt_str, _Bool *flag,
				int expected_ret, char *expected_flag)
{
	int		ret;
	int		opt_ret = 1;

	ret = ft_getopt(argc, argv, opt_str, flag);
	for (size_t idx = 0; expected_flag[idx] != '\0'; ++idx) {
		if (flag[(int)expected_flag[idx]] == 0)
			opt_ret = 0;
		opt_ret &= flag[(int)expected_flag[idx]];
	}
	return (ret == expected_ret && opt_ret == 1 ? OK : KO);
}

int			main(void)
{
	t_chai		test[] = {
		{"Should have good option", &check_option, NULL},
		{"Should have good option with multiple same flag", &check_option, NULL},
		{"Should have not get flags after '--'", &check_option, NULL},
		{"Should return -1 for invalid flag", &check_error_option, NULL}
	};
	t_payload data[] = {
		{
			.argv = (char *[sizeof(data[0].argv)]){"./a.out", "-lafoS", "arg1", "arg2", 0},
			.argc = 5,
			.opt_str = "-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1",
			.expected_flag = "lafoS",
			.expected_ret = 2,
			.flag = {[0 ... 255] = 0}
		},
		{
			.argv = (char *[sizeof(data[0].argv)]){"./a.out", "-llall", "-alll", "arg1", "arg2", 0},
			.argc = 5,
			.opt_str = "-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1",
			.expected_flag = "la",
			.expected_ret = 3,
			.flag = {}
		},
		{
			.argv = (char *[sizeof(data[0].argv)]){"./a.out", "-ls", "-ta", "--", "-p", "arg1", "arg2", 0},
			.argc = 8,
			.opt_str = "-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1",
			.expected_flag = "lsta",
			.expected_ret = 4,
			.flag = {}
		},
		{
			.argv = (char *[sizeof(data[0].argv)]){"lsls", "-ll.all", "-alll", "arg1", "arg2", 0},
			.argc = 5,
			.opt_str = "-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1",
			.expected_flag = "l and error :D",
			.expected_ret = -1,
			.flag = {}
		}
	};
	int			ret = OK;
	int			ret_test;

	printf("ft_getopt[%zu]:\n", sizeof(test) / sizeof(*test));
	for (size_t idx = 0, max = sizeof(test) / sizeof(*test);
		 idx < max;
		 ++idx)
	{
		if (test[idx].apply_before != NULL)
			test[idx].apply_before();
		ret_test |= test[idx].check(data[idx].argc, data[idx].argv, data[idx].opt_str, data[idx].flag,
								   data[idx].expected_ret, data[idx].expected_flag);
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
