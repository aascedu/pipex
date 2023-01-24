/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:59:32 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/24 14:28:59 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	index_first_cmd(t_pipex *data)
{
	if (ft_strncmp(data->av[1], "here_doc", ft_strlen(data->av[1]) == 0))
		return (3);
	return (2);
}

void	reset_pipe(t_pipex *data)
{
	if (data->i % 2 == 0)
	{
		close(data->p_end1[0]);
		close(data->p_end1[1]);
		if (pipe(data->p_end1) == -1)
			exit(1);
	}
	else
	{
		close(data->p_end2[0]);
		close(data->p_end2[1]);
		if (pipe(data->p_end2) == -1)
			exit(1);
	}
}
