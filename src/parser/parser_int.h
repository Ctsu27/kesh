#ifndef PARSER_INT_H
# define PARSER_INT_H

enum	ast_node_type
{
	AST_COMMAND,
	// "ls -l"
	AST_PIPE,
	// "|"
	AST_SEPARATOR,
	// ";"
	AST_AND,
	// "&&"
	AST_OR,
	// "||"
	AST_REDIR_IN,
	// ">"
	AST_REDIR_OUT,
	// "<"
	AST_APP_REDIR_IN,
	// ">>"
	AST_HEREDOC
	// "<<"
};
// "<&"
// "&<"
// ">&"
// "&>"

typedef struct	s_ast_node
{
	void	*data;
	int		type;
}				t_ast_node;
#endif
