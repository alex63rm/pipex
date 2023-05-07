***Funciones autorizadas:

• open, close, read, write,
malloc, free, perror,
strerror, access, dup, dup2,
execve, exit, fork, pipe,
unlink, wait, waitpid

• ft_printf and any equivalent
YOU coded

Se permite usar LIBFT

Tu programa deberá ejecutarse de la siguiente forma:

./pipex archivo1 comando1 comando2 archivo2

Deberá utilizar 4 argumentos:

• archivo1 y archivo2 son nombres de arhivos.
• comando1 y comando2 son comandos de shell con sus respectivos parámetros

EJEMPLOS

./pipex infile "ls -l" "wc -l" outfile
debe hacer:
<infile ls -l | wc -l >outfile