/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 23:55:12 by imahri            #+#    #+#             */
/*   Updated: 2023/01/03 19:20:21 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_list **a, t_list **b, int size)
{
	if (size == 2)
		ft_swap(a, 'a');
	else if (size == 3)
		push_tree(a);
	else if (size == 4)
		push_four(a, b);
	else if (size == 5)
		push_five(a, b);
	else
	{
		ft_cut(a, b);
		push_to_a(b, a);
	}
	ft_lstclear(a);
}
