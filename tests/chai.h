#ifndef CHAI_H
# define CHAI_H

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define X		"\033[0m"
# define PAD	"    "
# define OK		0
# define KO		1

typedef struct	s_chai
{
	char	*msg;
	int		(*check)();
	void	(*apply_before)();
}				t_chai;

#endif
