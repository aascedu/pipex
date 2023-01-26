/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:04:54 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/26 16:21:09 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wrong_arg(void)
{
	ft_putendl_fd("Wrong args, see subject.", STDERR_FILENO);
	exit(1);
}

void	open_error(char *str)
{
	ft_putstr_fd("Permission denied: ", STDERR_FILENO);
	ft_putendl_fd(str, 2);
}

void	path_error(void)
{
	ft_putendl_fd("Error finding the PATH line in envp var", 2);
	exit(1);
}
