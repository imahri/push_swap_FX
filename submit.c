/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:38:36 by imahri            #+#    #+#             */
/*   Updated: 2023/01/03 21:01:18 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*help_atoi(char *str, int *si)
{
	*si = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*si = -1;
		str++;
	}
	return (str);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	acc;
	int	si;

	i = 0;
	res = 0;
	acc = 0;
	str = help_atoi(str, &si);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = acc * 10 + str[i] - '0';
		if (res == -2147483648 && si == -1 && str[i + 1] == '\0')
			return (-2147483648);
		if (acc > res)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		acc = res;
		i++;
	}
	return (res * si);
}

int	check_do(t_list *list)
{
	t_list	*nd1;
	t_list	*nd2;

	nd1 = list;
	while (nd1)
	{
		nd2 = nd1->next;
		while (nd2)
		{
			if (nd1->content == nd2->content)
				return (1);
			nd2 = nd2->next;
		}
		nd1 = nd1->next;
	}
	return (0);
}

int	sort_max(t_list *list)
{
	t_list	*nd1;
	t_list	*nd2;

	nd1 = list;
	while (nd1 && nd1->next != NULL)
	{
		nd2 = nd1->next;
		if (nd1->content > nd2->content)
			return (1);
		nd1 = nd1->next;
	}
	return (0);
}

void	put_index(t_list *list)
{
	t_list	*tr1;
	t_list	*tr2;

	tr1 = list;
	while (tr1)
	{
		tr1->index = 0;
		tr2 = list;
		while (tr2)
		{
			if (tr1->content > tr2->content)
				tr1->index += 1;
			tr2 = tr2->next;
		}
		tr1 = tr1->next;
	}
}
