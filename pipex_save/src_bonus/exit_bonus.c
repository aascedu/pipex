/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurascedu <arthurascedu@student.42ly    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:28:43 by arthurasced       #+#    #+#             */
/*   Updated: 2023/01/16 17:45:01 by arthurasced      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	wrong_arg_b(char *error)
{
	if (ft_strncmp(error, "too_few", 7) == 0)
		ft_putendl_fd("Too few args, see subject.", STDERR_FILENO);
	if (ft_strncmp(error, "too_many", 8) == 0)
		ft_putendl_fd("Too many args, see subject.", STDERR_FILENO);
	exit(1);
}
