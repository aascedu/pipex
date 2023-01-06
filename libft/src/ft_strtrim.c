/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:13:57 by aascedu           #+#    #+#             */
/*   Updated: 2022/11/16 16:15:51 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charmatch(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_istart(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (i == 0)
		{
			if (ft_charmatch(s1[i], set) == 0)
				return (i);
		}
		else
			if (ft_charmatch(s1[i - 1], set) == 1
				&& ft_charmatch(s1[i], set) == 0)
				break ;
		i++;
	}
	return (i);
}

static int	ft_iend(const char *s1, const char *set)
{
	int	i;

	i = (int)ft_strlen(s1) - 1;
	while (i >= 0)
	{
		if (i == (int)ft_strlen(s1) - 1)
		{
			if (ft_charmatch(s1[i], set) == 0)
				return (i);
		}
		else
			if (ft_charmatch(s1[i + 1], set) == 1
				&& ft_charmatch(s1[i], set) == 0)
				break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	int		len;
	int		i;

	if (s1 == NULL)
		return (NULL);
	len = ft_iend(s1, set) - ft_istart(s1, set) + 1;
	if (ft_istart(s1, set) == (int)ft_strlen(s1))
		return (ft_strdup("\0"));
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s1[ft_istart(s1, set) + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
