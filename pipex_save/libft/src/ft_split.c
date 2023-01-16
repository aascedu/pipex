/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:32:35 by aascedu           #+#    #+#             */
/*   Updated: 2022/11/21 10:07:07 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countargs(const char *str, char c)
{
	int	i;
	int	args;

	args = 0;
	i = 0;
	while (str[i])
	{
		if (i == 0)
		{
			if (str[i] != c)
				args++;
		}
		else
		{
			if (str[i] != c && str[i - 1] == c)
				args++;
		}
		i++;
	}
	return (args);
}

static char	**ft_freeall(char **res, int args)
{
	int	i;

	i = 0;
	while (i <= args)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static char	*ft_dupstr(const char *s, char c, char **res)
{
	int		i;
	char	*copy;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	copy = malloc(sizeof(char) * (i + 1));
	if (!copy)
		return ((char *)ft_freeall(res, ft_countargs(s, c)));
	i = 0;
	while (s[i] && s[i] != c)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		i;
	int		arg;

	if (s == NULL)
		return (NULL);
	result = malloc(sizeof(char *) * (ft_countargs(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	arg = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			result[arg++] = ft_dupstr(&s[i], c, result);
			while (s[i] && s[i] != c)
				i++;
		}
		if (s[i])
			i++;
	}
	result[arg] = NULL;
	return (result);
}
