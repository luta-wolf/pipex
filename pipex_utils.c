/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:47:26 by einterdi          #+#    #+#             */
/*   Updated: 2021/12/17 09:52:19 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

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

char *get_line(char *cmd, char **arr)
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
