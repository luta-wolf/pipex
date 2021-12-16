/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:05:29 by einterdi          #+#    #+#             */
/*   Updated: 2021/12/16 23:45:49 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **find_path(char **env)
{
	char	**arr;
	int		i;

	i = 0;
	while (env[i])
	{
		if(ft_strnstr(env[i], "PATH=", 5))
		{
			arr = ft_split(env[i] + 5, ':');
			if (!arr)
				error_process();
			return arr;
		}
		i++;
	}
	return (NULL);
}

char *check_cmd(char *cmd, char **arr)
{
	char *tmp;
	char *line;
	int	i;

	i = 0;
	while(arr[i])
	{
		tmp = ft_strjoin(arr[i], "/");
		line = ft_strjoin(tmp, cmd);
		free(tmp);
		if(access(line, F_OK) == 0)
			return line;
		else
			free(line);
		i++;
	}
	error_cmd(cmd);
	return NULL;
}

void	child1_process(int *pipe_fd, char **argv, char **env, int fd1)
{
	char **cmd;
	char **path;
	char *line;

	dup2(fd1, 0);
	dup2(pipe_fd[1], 1);
	cmd = ft_split(argv[2], ' ');
	path = find_path(env);
	line = check_cmd(cmd[0], path);
	close(fd1);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execve(line, cmd, env);
}

void	child2_process(int *pipe_fd, char **argv, char **env, int fd2)
{
	char **cmd;
	char **path;
	char *line;

	dup2(pipe_fd[0], 0);
	dup2(fd2, 1);
	cmd = ft_split(argv[3], ' ');
	path = find_path(env);
	line = check_cmd(cmd[0], path);
	close(fd2);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	execve(line, cmd, env);
}

void pipex(int argc, char **argv, char **env)
{
	int fd1;
	int fd2;
	pid_t pid;
	int pipe_fd[2];

	check_fd(&fd1, &fd2, argv);
	if(pipe(pipe_fd) == -1)
		error_process();
	pid = fork();
	if(pid == -1)
		error_process();
	if (pid == 0)
		child1_process(pipe_fd, argv, env, fd1);
	pid = fork();
	if(pid == -1)
		error_process();
	if (pid == 0)
		child2_process(pipe_fd, argv, env, fd2);
	close(fd1);
	close(fd2);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(0);
	wait(0);
	}

int main(int argc, char **argv, char **env)
{
	check_args(argc, argv);
	pipex(argc, argv, env);
	return 0;
}
