# kesh
21sh project @42

General Instructions
--------------------
- This project will be evaluated by humans only. You’re allowed to organise and
name your files as you see fit, but you must follow the following rules.
- The executable file must be named 21sh.
- Your Makefile must compile the project and must contain the usual rules. It must
recompile and re-link the program only if necessary.
- If you are clever, you will use your library for your 21sh. Submit also your folder
libft including its own Makefile at the root of your repository. Your Makefile
will have to compile the library, and then compile your project.
- Your project must be written in accordance with the Norm. Only norminette is
authoritative.
- You have to handle errors carefully. In no way can your program quit in an unexpected manner (Segmentation fault, bus error, double free, etc).
- Your program cannot have memory leaks.
- Within the mandatory part, you are allowed to use only the following libc functions:
  - malloc, free
  - access
  - open, close, read, write
  - opendir, readdir, closedir
  - getcwd, chdir
  - stat, lstat, fstat
  - fork, execve
  - wait, waitpid, wait3, wait4
  - signal, kill
  - exit
  - pipe
  - dup, dup2
  - isatty, ttyname, ttyslot
  - ioctl
  - getenv
  - tcsetattr, tcgetattr
  - tgetent
  - tgetflag
  - tgetnum
  - tgetstr
  - tgoto
  - tputs
- You are allowed to use other functions or other librairies to complete the bonus
part as long as their use is justified during your defense. Be smart!

Mandatory part
--------------
To begin with, every minishell features are implicitly part of the 21sh mandatory part.
Furthermore you’ll have to add the following new features:
- A line edition feature using the termcaps library. Check the following description
below.
- The ctrl+D et ctrl+C keys combination features for line edition and process execution.
- The “;” command line separator
- Pipes “|”
- The 4 following redirections “<”, “>”, “<<” et “>>”
- File descriptor aggregation, for example to close the standard error output:
```
$> ls
riri
$> rm riri; cat riri 2>&-
```
Here is a representative example of commands your 21sh must be able to execute
correctly:
```
$> mkdir test ; cd test ; ls -a ; ls | cat | wc -c > fifi ; cat fifi
. ..
5
$>
```
Regarding the line edition, you must at least manage the following features. The
keys to be used are used as examples, you’re free to use other ones as long as your shell
remains logical and intuitive. The person evaluating you will decide what’s logical and
intuitive, so be careful not to get carried away with creativity.
- Edit the line where the cursor is located.
- Move the cursor left and right to be able to edit the line at a specific location.
Obviously new characters have to be inserted between the existing ones similarly
to a classic shell.
- Use up and down arrows to navigate through the command history which we will
then be able to edit if we feel like it (the line, not the history)
- Cut, copy, and/or paste all or part of a line using the key sequence you prefer.
- Move directly by word towards the left or the right using ctrl+LEFT and ctrl+RIGHT
or any other reasonable combination of keys.
- Go directly to the beginning or the end of a line by pressing home and end.
- Write AND edit a command over a few lines. In that case, we would love that
ctrl+UP and ctrl+DOWN allow to go from one line to another in the command
while remaining in the same column or otherwise the most appropriate column.
- Completely manage quotes and double quotes, even on several lines (expansions
excluded).
