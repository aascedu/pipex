/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:05:04 by aascedu           #+#    #+#             */
/*   Updated: 2022/12/05 14:41:54 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	if (dst > src)
	{
		while (i < len)
		{
			((char *)dst)[len - i - 1] = ((char *)src)[len - i - 1];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}

char	*add_buffer(char *line, char *buff)
{
	char	*temp;
	int		i;
	int		j;

	i = ft_index_nl(buff);
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	j = -1;
	while (++j < i)
		temp[j] = buff[j];
	temp[j] = '\0';
	temp = ft_strjoin_free(line, temp);
	ft_memmove(buff, buff + i, BUFFER_SIZE - i);
	ft_bzero(buff + (BUFFER_SIZE - i), ft_strlen(buff + (BUFFER_SIZE - i)));
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = {0};
	char		*line;
	int			byte_read;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_bzero(buff, BUFFER_SIZE + 1), NULL);
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (NULL);
	*line = 0;
	byte_read = 1;
	if (!buff[0])
		byte_read = read(fd, buff, BUFFER_SIZE);
	if (byte_read <= 0)
		return (free(line), NULL);
	while (byte_read)
	{
		if (ft_newline(buff))
			return (add_buffer(line, buff));
		line = add_buffer(line, buff);
		byte_read = read(fd, buff, BUFFER_SIZE);
	}
	return (add_buffer(line, buff));
}
