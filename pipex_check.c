/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:59:43 by einterdi          #+#    #+#             */
/*   Updated: 2021/12/16 23:16:38 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_file(char *file)
{
	ft_putstr_fd("\033[31mError:\e[0m ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	error_cmd(char *cmd)
{
	ft_putstr_fd("\033[31mError:\e[0m command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	check_args(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_putstr_fd("\033[31mError:\e[0m Wrong number of arguments.\n", 2);
		ft_putstr_fd("Example: ./pipex file1 'cmd1' 'cmd2' file2\n", 2);
		exit(EXIT_FAILURE);
	}
/*	if(access(argv[1], R_OK) == -1)
		error_file(argv[1]);
	if(access(argv[argc - 1], W_OK) == -1)
		error_file(argv[argc - 1]);*/
}

void	error_process(void)
{
	perror("\033[31mError:\e[0m ");
	exit(EXIT_FAILURE);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void check_fd(int *fd1, int *fd2, char **argv)
{
	*fd1 = open(argv[1], O_RDONLY);
	if(*fd1 == -1)
		error_file(argv[1]);
	*fd2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(*fd2 == -1)
		error_file(argv[4]);
}
