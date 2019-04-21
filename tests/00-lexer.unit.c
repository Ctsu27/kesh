#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "chai.h"
#include "lexer.h"
#include "lexer_int.h"

static void	free_token(void *arr, size_t len)
{
	t_token	**tokens;
	size_t	idx;

	tokens = (t_token **)arr;
	idx = 0;
	while (idx < len)
	{
		free(tokens[idx]);
		++idx;
	}
}

static int	check_lexer(unsigned char *fmt)
{
	t_array	*token;
	int		ret;

	token = array_new(sizeof(t_token *));
	ret = lexer(fmt, token, g_token_basic_definition, g_token_basic_handler);
	printf("token->length == %zu\n", token->length);
	array_foreach(token, &show_token);
	array_delete(token, &free_token);
	if (ret != 0)
		printf("ret == %d\n", ret);
	return (ret == 0 ? OK : KO);
}

int			main(void)
{
	t_chai			test[] = {
		{"Should handle minishell level tokens", &check_lexer, NULL},
		{"Should handle simple quote tokens", &check_lexer, NULL},
		{"Should handle double quote tokens", &check_lexer, NULL},
		{"Should handle basic and well formatted tokens", &check_lexer, NULL},
		{"Should handle basic and weird formatted tokens", &check_lexer, NULL},
		{"Should handle expansion with controller operator tokens", &check_lexer, NULL},
		{"Should handle white spaces", &check_lexer, NULL}
	};
	char	*fmt[] = {
		"cmd -flags -with -other -flag args1 args2 / . coucou invalid",
		"cmd '-flags' args2 '\\simple quote\\'",
		"cmd \"-flags\" args2 \"\\\"doubl\\e\\\"quot\\e\\\"\"",
		"cat file.txt | grep \"[a-z]\" > result.txt",
		"cat file.txt|grep \"[a-z]\" > result.txt",
		/**
		 * <cat>  <file.txt>  <|>  <grep>  <"[a-z]">  <'>'>  <result.txt>
		 *  <W>       <W>     <P>   <W>       <W>      <R>       <W>
		 *                              '>'
		 *                             /   \
		 *                           '|'  "result.txt"
		 *                          /   \
		 *                         /     \
		 *                        /       \
		 *                       /         \
		 *                      /           \
		 *               "cat file.txt"  "grep \"[a-z]\""
		 *     
		 */
		"echo ~/$PATH | 'path.txt' && cat -e path.txt",
		/**
		 *  <echo>  <~>  </>  <$PATH>  <|>  <'path.txt'>  <&&>  <cat>  <-e>  <path.txt>
		 *   <W>    <EXP><W>   <EXP>   <R>     <EXP>      <CMD>  <W>   <W>      <W>
		 *                                '&&'
		 *                                /  \
		 *                             '|'    \
		 *                             / \   "cat -e path.txt"
		 *                            /   \
		 *                           /     \
		 *                  "echo ~/$PATH"  "'path.txt'"
		 */
		"     ls    -R . 2>& content_stdout.txt && cat -e content_stdout.txt"
		/**
		 * <ls>  <-R>  <.>  <1>  <'>'>  <content_stdout.txt>  <&&>  <cat>  <-e>  <content_stdout.txt>
		 *  <W>  <W>   <W>  <W>   <R>           <W>           <A>    <W>   <W>            <W>
		 *                                '&&'
		 *                                /  \
		 *                             '>'    \
		 *                             / \  "cat -e content_stdout.txt"
		 *                            /   \
		 *                           /     \
		 *                     "ls -R ."  "content_stdout.txt"
		 */
	};
	int			ret = OK;
	int			ret_test = OK;

	printf("Lexer[%zu]:\n", sizeof(test) / sizeof(*test));
	for (size_t idx = 0,
			max = sizeof(test) / sizeof(*test);
		 idx < max;
		 ++idx)
	{
		if (test[idx].apply_before != NULL)
			test[idx].apply_before();
		ret_test |= test[idx].check((unsigned char *)fmt[idx]);
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
