#include <stdio.h>
#include <stdlib.h>
#include "chai.h"
#include "lexer.h"

static int	check_lexer(char *fmt)
{
	int		ret;

	ret = lexer(fmt);
	if (ret != 0)
		printf("ret == %d\n", ret);
	return (0 ? OK : KO);
}

int			main(void)
{
	t_chai		test[] = {
		{"____________test lexer", &check_lexer, NULL},
		{"____________test lexer", &check_lexer, NULL},
		{"____________test lexer", &check_lexer, NULL}
	};
	char		*fmt[] = {
		"cat file.txt | grep \"[a-z]\" > result.txt",
		"cat file.txt|grep \"[a-z]\" > result.txt",
		"echo $PATH | path.txt && cat -e path.txt"
		/**
		 * <cat>  <file.txt>  <|>  <grep>  <"[a-z]">  <>>  <result.txt>
		 *  <W>       <W>     <P>   <W>       <W>     <R>       <W>
		 *                 '>'
		 *                /   \
		 *              '|'  "result.txt"
		 *             /   \
		 *            /     \
		 *           /       \
		 *          /         \
		 *         /           \
		 *  "cat file.txt"  "grep \"[a-z]\""
		 *     
		 */
	};
	int			ret = OK;
	int			ret_test = OK;

	printf("Lexer[%zu]:\n", sizeof(test) / sizeof(*test));
	for (size_t idx = 0, max = sizeof(test) / sizeof(*test);
		 idx < max;
		 ++idx)
	{
		if (test[idx].apply_before != NULL)
			test[idx].apply_before();
		ret_test |= test[idx].check(fmt[idx]);
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
