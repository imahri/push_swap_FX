/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:16:30 by imahri            #+#    #+#             */
/*   Updated: 2023/01/02 18:57:34 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	p_min(t_list **a)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		len;

	tmp = *a;
	len = ft_lstsize(*a);
	i = tmp->content;
	j = 1;
	while (tmp)
	{
		if (tmp->content < i)
			i = tmp->content;
		tmp = tmp->next;
	}
	tmp = *a;
	while (tmp && tmp->content != i)
	{	
		tmp = tmp->next;
		j++;
	}
	return (j);
}

int	pos_nb(t_list **b, int index)
{
	t_list	*tmp;
	int		pos;

	pos = 1;
	tmp = *b;
	while (tmp && tmp->index != index)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

int	ft_nb_inst(int len, int pos)
{
	if (pos < (len / 2))
		return (pos - 1);
	return (len - pos + 1);
}
