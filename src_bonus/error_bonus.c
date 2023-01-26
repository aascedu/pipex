/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:10:08 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/26 15:47:08 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	wrong_arg(char *error)
{
	if (ft_strncmp(error, "too_few", 7) == 0)
		ft_putendl_fd("Too few args, see subject.", STDERR_FILENO);
	if (ft_strncmp(error, "too_many", 8) == 0)
		ft_putendl_fd("Too many args, see subject.", STDERR_FILENO);
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
