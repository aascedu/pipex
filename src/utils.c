/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:14:39 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/16 08:35:15 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*find_path(char **envp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		str = ft_substr(envp[i], 0, j);
		if (ft_strncmp(str, "PATH", 5) == 0)
			return (free(str), envp[i]);
		free(str);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*try_path;
	char	*try_cmd;
	char	*total_path;
	char	**path_splitted;

	total_path = find_path(envp);
	path_splitted = ft_split(total_path + 5, ':');
	i = 0;
	while (path_splitted[i])
	{
		try_path = ft_strjoin(path_splitted[i], "/");
		try_cmd = ft_strjoin(try_path, cmd);
		if (access(try_cmd, F_OK | X_OK) == 0)
			return (free(try_path), free_tab(path_splitted), try_cmd);
		free(try_cmd);
		free(try_path);
		i++;
	}
	return (free_tab(path_splitted), NULL);
}
