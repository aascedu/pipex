/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:22:40 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/06 13:17:38 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(const char *s, char c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_strdup(const char *s1);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlen(const char *str);

void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*ft_calloc(size_t count, size_t size);


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

char	*add_buffer(char *line, char *buff);
char	*ft_strjoin_free(char *line, char *buff);
char	*ft_strjoin_free2(const char *s1, const char *s2);
char	*get_next_line(int fd);
char	*get_next_line_fd(int fd);

int		ft_newline(char *buff);
int		ft_index_nl(char *buff);

void	ft_bzero_gnl(void *s, size_t n);
void	*ft_memmove_gnl(void *dst, const void *src, size_t len);

#endif
