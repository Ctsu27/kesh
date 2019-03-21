#ifndef BUILTIN_H
# define BUILTIN_H

int		builtin_cd(void)__attribute__((hot));
int		builtin_echo(void);
int		builtin_env(void);
int		builtin_exit(void);
int		builtin_setenv(void);
int		builtin_unsetenv(void);

#endif
