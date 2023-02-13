/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:14:59 by imahri            #+#    #+#             */
/*   Updated: 2022/12/30 01:18:40 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_push(t_list **b, t_list **a, int index)
{
	int	len;
	int	pos;
	int	count_instru;

	len = ft_lstsize(*b);
	pos = pos_nb(b, index);
	count_instru = ft_nb_inst(ft_lstsize(*b), pos);
	while (count_instru)
	{
		if (pos < (len / 2))
			ft_rotate(b, 'b');
		else
			ft_rev_rotate(b, 'b');
		count_instru--;
	}
	ft_push(b, a, 'b');
}

void	just_re_push(t_list **b, t_list **a)
{
	int	leno;

	leno = ft_lstsize(*b) - 1;
	re_push(b, a, leno);
}

void	re_push_if(t_list **b, t_list **a)
{
	int	leno;
	int	lent;

	leno = ft_lstsize(*b) - 1;
	lent = leno - 1;
	re_push(b, a, lent);
	re_push(b, a, leno);
	ft_swap(a, 'a');
}

void	push_to_a(t_list **b, t_list **a)
{
	int	fpos;
	int	spos;
	int	fnb;
	int	snb;
	int	index;

	index = ft_lstsize(*b) - 1;
	while (index > 0)
	{
		fpos = pos_nb(b, index);
		spos = pos_nb(b, index - 1);
		fnb = ft_nb_inst(ft_lstsize(*b), fpos);
		snb = ft_nb_inst(ft_lstsize(*b), spos);
		if (fnb > snb)
			re_push_if(b, a);
		else
			just_re_push(b, a);
		index = ft_lstsize(*b) - 1;
	}
	if (index == 0)
		ft_push(b, a, 'b');
}
