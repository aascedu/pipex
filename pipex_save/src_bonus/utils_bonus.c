/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurascedu <arthurascedu@student.42ly    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:22:39 by arthurasced       #+#    #+#             */
/*   Updated: 2023/01/16 17:48:01 by arthurasced      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	my_open(int argc, char **argv, char *rule)
{
	int	fd;

	fd = 0;
	if (ft_strncmp(rule, "DOC", 3) == 0)
		fd = open(argv[argc - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
	else if (ft_strncmp(rule, "OPEN", 4) == 0)
		fd = open(argv[1], O_RDONLY);
	else if (ft_strncmp(rule, "CLOSE", 5) == 0)
		fd = open(argv[1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd <= 0)
	{
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		exit(-1);
	}
	return (fd);
}
