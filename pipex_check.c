#include "pipex.h"

void	error_file(char *file)
{
	ft_putstr_fd("\033[31mError:\e[0m ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}

void	error_cmd(char *cmd)
{
	ft_putstr_fd("\033[31mError:\e[0m command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}

void	check_args(int argc, char **argv)
{
	if(argc != 5)
	{
		ft_putstr_fd("\033[31mError:\e[0m Wrong number of arguments.\n", 2);
		ft_putstr_fd("Example: ./pipex file1 'cmd1' 'cmd2' file2\n", 2);
		exit(0);
	}
	if(access(argv[1], R_OK) == -1)
		error_file(argv[1]);
	if(access(argv[argc - 1], W_OK) == -1)
		error_file(argv[argc - 1]);
}
