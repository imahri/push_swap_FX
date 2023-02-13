/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submitt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:24:52 by imahri            #+#    #+#             */
/*   Updated: 2023/01/03 19:38:47 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **av)
{
	char	**str;
	int		i;

	i = 0;
	while (av[++i])
	{
		str = ft_split(av[i], ' ');
		if (str == NULL)
			return (1);
		if (susb(str) == 0)
		{
			ft_free_tab(str);
			write(2, "Error\n", 6);
			return (1);
		}
		else
			ft_free_tab(str);
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	susb(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		if (str[i][j] == '\0')
			return (0);
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	stock_a(t_list **a, int ac, char **av)
{
	int		i;
	int		j;
	char	**str;
	t_list	*new_node;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		str = ft_split(av[i], ' ');
		while (str[j])
		{
			new_node = ft_lstnew(ft_atoi(str[j]));
			if (!new_node)
			{
				ft_lstclear(a);
				exit (1);
			}
			lst_add_back(a, new_node);
			j++;
		}
		ft_free_tab(str);
	}
	put_index(*a);
}
