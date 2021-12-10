/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:05:29 by einterdi          #+#    #+#             */
/*   Updated: 2021/12/10 08:45:53 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		free(line);
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
	return (arr);
}

void pipex(int argc, char **argv, char **env)
{
	char **arr;
	char **av;
	int i;

	arr = find_path(env);
	i = 2;
	while (i < argc -1)
	{
		av = ft_split(argv[i], ' ');
		check_cmd(av[0], arr);
		i++;
	}
}

int main(int argc, char **argv, char **env)
{
	check_args(argc, argv);
	pipex(argc, argv, env);
	//while (1);
	return 0;
}
