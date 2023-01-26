/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:35:55 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/26 14:06:25 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	init_data(&data, argc, argv, envp);
	if (data.ac < 5)
		wrong_arg("too_few");
	if (data.ac > 5)
		wrong_arg("too_many");
	pipex(&data);
	my_close(&data);
	while (data.i-- > 0)
		wait(NULL);
	restore_std(&data);
	return (0);
}
