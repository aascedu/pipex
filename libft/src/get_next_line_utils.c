/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:09:51 by arthurasced       #+#    #+#             */
/*   Updated: 2023/01/06 10:03:55 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero_gnl(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			((char *)s)[i] = 0;
			i++;
		}
	}
}

int	ft_newline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_index_nl(char *buff)
{
	int	i;

	i = -1;
	while (buff[++i])
	{
		if (buff[i] == '\n')
		{
			i++;
			break ;
		}
	}
	return (i);
}

char	*ft_strjoin_free(char *line, char *temp)
{
	char	*result;
	int		line_len;
	int		temp_len;
	int		i;

	line_len = ft_strlen(line);
	temp_len = ft_strlen(temp);
	result = (char *)malloc(sizeof(char) * (line_len + temp_len + 1));
	if (!result)
	{
		free(line);
		free(temp);
		return (NULL);
	}
	i = -1;
	while (line[++i])
		result[i] = line[i];
	i = -1;
	while (temp[++i])
		result[line_len + i] = temp[i];
	result[line_len + temp_len] = '\0';
	free(line);
	free(temp);
	return (result);
}
