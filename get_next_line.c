/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:03:14 by imahri            #+#    #+#             */
/*   Updated: 2023/01/03 01:59:17 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_strlen_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

static	char	*current_line(char *str)
{
	char	*result;
	int		i;

	if (str == NULL)
		return (NULL);
	result = malloc(sizeof(char) * ft_strlen_n(str) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	result[i] = '\0';
	return (result);
}

static	char	*next_line(char	*str)
{
	char	*result;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	i = 0;
	if (!str[i] || !str[i + 1])
		return (free(str), NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i])
		i++;
	result = malloc(sizeof(char) * ft_strlen(str + i) + 1);
	if (result == NULL)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*next;
	char		*buffer;
	char		*c_l;
	int			count;

	buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ft_strchr(next, '\n') == NULL)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count <= 0)
		{
			free(buffer);
			if (!next || !*next)
				return (free(next), next = NULL, NULL);
			return (c_l = ft_strdup(next), free(next), next = NULL, c_l);
		}
		buffer[count] = '\0';
		next = ft_strjoin(next, buffer);
	}
	free(buffer);
	c_l = current_line(next);
	next = next_line(next);
	return (c_l);
}
