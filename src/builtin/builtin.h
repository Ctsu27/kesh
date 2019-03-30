#ifndef BUILTIN_H
# define BUILTIN_H

# include "array.h"

int		builtin_cd(int argc, t_array *argv, t_array *env);
int		builtin_echo(int argc, t_array *argv, t_array *env);
int		builtin_env(int argc, t_array *argv, t_array *env);
int		builtin_exit(int argc, t_array *argv, t_array *env);
int		builtin_setenv(int argc, t_array *argv, t_array *env);
int		builtin_unsetenv(int argc, t_array *argv, t_array *env);

#endif
