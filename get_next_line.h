/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:20:55 by fschipor          #+#    #+#             */
/*   Updated: 2024/04/01 19:00:56 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*get_next_line(int fd);
int	str_len(char *str);
char * ft_strjoin(char *s1, char *s2);
int	ft_strlcpy(char *dst, const char *src, int dstsize);
void	*ft_calloc(int count, int size);
int	ft_strchr(char *s, char c);
void	ft_bzero(void *s, int n);

#endif