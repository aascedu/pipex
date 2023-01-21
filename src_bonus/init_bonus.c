/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:43:06 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/21 13:18:08 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_data(t_pipex *data, int argc, char **argv, char **envp)
{
	data->ac = argc;
	data->av = argv;
	data->envp = envp;
}
