/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:05:20 by einterdi          #+#    #+#             */
/*   Updated: 2021/12/10 08:50:57 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/errno.h>
#include <string.h>

void	error_cmd(char *cmd);
void	error_file(char *file);
void	check_args(int argc, char **argv);

#endif
