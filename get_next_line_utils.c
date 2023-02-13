/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:35:56 by imahri            #+#    #+#             */
/*   Updated: 2023/01/02 18:13:11 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;

	i = 0;
	p = malloc ((sizeof(char) * (ft_strlen(s1) + 1)));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t n)
{
	void	*tmp;
	size_t	tsize;
	size_t	i;

	i = 0;
	tsize = count * n;
	if (n != 0 && count != tsize / n)
		return (NULL);
	tmp = malloc(tsize);
	if (!tmp)
		return (0);
	while (i < tsize)
	{
		((char *)tmp)[i] = '\0';
		i++;
	}
	return (tmp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	p = ft_calloc ((ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{		
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	return (p);
}
