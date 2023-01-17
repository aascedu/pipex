/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:37:14 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/17 10:01:03 by aascedu          ###   ########lyon.fr   */
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
