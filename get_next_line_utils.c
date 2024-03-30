/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:20:48 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/30 22:15:27 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char * ft_strjoin(char *s1, char *s2)
{
	char *str;
	int i;
	int j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (str_len(s1) + str_len(s2) + 1));
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}


int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}