/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:05:20 by einterdi          #+#    #+#             */
/*   Updated: 2021/12/19 15:17:17 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/errno.h>
# include <string.h>
# include <fcntl.h>

// pipex_check.c
void	error_cmd(char *cmd);
void	error_file(char *file);
void	error_process(void);
void	check_args(int argc);
void	free_arr(char **arr);
void	check_fd(int *fd1, int *fd2, char **argv);

// pipex_utils.c
char	**find_path(char **env);
char	*get_line(char *cmd, char **arr);

#endif


// ./pipex file1 yes "head -10" file2
// ./pipex /dev/urandom "cat -e" "head -10" file2

