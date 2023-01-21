/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:37:35 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/21 13:37:27 by aascedu          ###   ########lyon.fr   */
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

void	free_fd(int **p_fd, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		free(p_fd[i]);
		i++;
	}
	free(p_fd);
}

int	my_open(t_pipex *data, char *rule)
{
	int	fd;

	fd = 0;
	if (ft_strncmp(rule, "DOC", 3) == 0)
		fd = open(data->av[data->ac - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
	else if (ft_strncmp(rule, "OPEN", 4) == 0)
		fd = open(data->av[1], O_RDONLY);
	else if (ft_strncmp(rule, "CLOSE", 5) == 0)
		fd = open(data->av[data->ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd <= 0)
	{
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		exit(-1);
	}
	return (fd);
}
