/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:03:33 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/04 15:11:43 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd1 < 0 || fd2 < 0)
		return (1);
}
