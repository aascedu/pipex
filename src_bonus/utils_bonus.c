/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurascedu <arthurascedu@student.42ly    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:22:39 by arthurasced       #+#    #+#             */
/*   Updated: 2023/01/05 19:06:21 by arthurasced      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	wrong_arg(void)
{
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	exit(1);
}

int	open_here_doc(int argc, char **argv)
{
	int fd;
	
	fd = open(argv[argc - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
	{
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		exit(-1);
	}
	return (fd);
}