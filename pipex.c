/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:05:29 by einterdi          #+#    #+#             */
/*   Updated: 2021/12/16 13:57:55 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *pipe_fd, char **argv, char **env, int fd1)
{

}

void	parent_process(int *pipe_fd, char **argv, char **env, int fd2)
{
//	wait();
}

void check_cmd(char *cmd, char **arr)
{
	char *tmp;
	char *line;
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while(arr[i])
	{
		line = ft_strjoin(arr[i], "/");
		tmp = line;
		line = ft_strjoin(line, cmd);
		free(tmp);
		if(access(line, F_OK) == -1)
			flag = 1;
		else if(access(line, F_OK) == 0)
		{
			flag = 0;
			printf("%s\n", line);
			break;
		}
//		free(line);
		i++;
	}
	free(line);
	if(flag == 1)
		error_cmd(cmd);
}

char **find_path(char **env)
{
	char	**arr;
	int		i;

	i = 0;
	while (env[i])
	{
		if(ft_strnstr(env[i], "PATH=", 5))
			arr = ft_split(env[i] + 5, ':');
		i++;
	}
	if(!arr)
		free_arr(arr);
	return (arr);
}

void pipex(int argc, char **argv, char **env)
{
	char **arr;
	char **av;
	int i;
	int fd1;
	int fd2;

	pid_t pid;
	int pipe_fd[2];

	fd1 = open(argv[1], O_RDONLY);
	if(fd1 == -1)
		error_file(argv[1]);
	fd2 = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(fd2 == -1)
		error_file(argv[argc - 1]);



	arr = find_path(env);
	i = 2;
	while (i < argc -1)
	{
		av = ft_split(argv[i], ' ');
		check_cmd(av[0], arr);
		i++;
	}


	if(pipe(pipe_fd) == -1)
		error_process();
	pid = fork();
	if(pid == -1)
		error_process();
	if (pid == 0)
		child_process(pipe_fd, argv, env, fd1);
	else
		parent_process(pipe_fd, argv, env, fd2);
}

int main(int argc, char **argv, char **env)
{
	check_args(argc, argv);
	pipex(argc, argv, env);
//	while (1);
	return 0;
}
