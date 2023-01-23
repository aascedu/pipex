/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:59:32 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/23 16:01:36 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	index_first_cmd(t_pipex *data)
{
	if (ft_strncmp(data->av[1], "here_doc", ft_strlen(data->av[1]) == 0))
		return (3);
	return (2);
}
