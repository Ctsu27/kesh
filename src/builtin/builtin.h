#ifndef BUILTIN_H
# define BUILTIN_H

int		builtin_cd(int argc, char **argv, char **env)__attribute__((hot));
int		builtin_echo(int argc, char **argv, char **env)__attribute__((cold));
int		builtin_env(int argc, char **argv, char **env);
int		builtin_exit(int argc, char **argv, char **env)__attribute__((cold));
int		builtin_setenv(int argc, char **argv, char **env);
int		builtin_unsetenv(int argc, char **argv, char **env);

#endif
