/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:13:38 by imahri            #+#    #+#             */
/*   Updated: 2023/01/03 00:50:57 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vm_push(t_list **a, t_list **b, int chunk, int ref)
{
	int	i;

	i = 0;
	while (i < ref && *a)
	{
		if ((*a)->index < chunk)
		{
			if ((*a)->index >= (chunk - (ref / 2)))
			{
				ft_push(a, b, 'a');
				ft_rotate(b, 'b');
			}
			else
				ft_push(a, b, 'a');
			i++;
		}
		else
			ft_rotate(a, 'a');
	}
}

void	ft_cut(t_list **a, t_list **b)
{
	int	len;
	int	chunk;
	int	ref;

	len = ft_lstsize(*a);
	if (len < 200)
	{
		chunk = len / 5;
		ref = len / 5;
		while (ft_lstsize(*a))
		{
			vm_push(a, b, chunk, ref);
			chunk += ref;
		}	
	}
	else
	{
		chunk = len / 9;
		ref = len / 9;
		while (ft_lstsize(*a))
		{
			vm_push(a, b, chunk, ref);
			chunk += ref;
		}
	}
}
