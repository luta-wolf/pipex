/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:05:29 by einterdi          #+#    #+#             */
/*   Updated: 2021/12/08 18:54:07 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	char *s;
	char **arr;

	int i;

	i = 0;
	while (env[i])
	{
		if(ft_strnstr(env[i], "PATH=", 5))
			s = env[i];
		i++;
	}
	printf("%s\n", s);
	i = 0;
	arr = ft_split(s + 5, ':');
	i = 0;
	while(arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}

	return 0;
}
