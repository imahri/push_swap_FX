/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:54:32 by imahri            #+#    #+#             */
/*   Updated: 2023/01/02 19:04:19 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_tree(t_list **head)
{
	int	n2;
	int	n3;

	n2 = (*head)->next->content;
	n3 = (*head)->next->next->content;
	if ((*head)->content < n2 && (*head)->content < n3 && n2 > n3)
	{
		ft_swap(head, 'a');
		ft_rotate(head, 'a');
	}
	else if ((*head)->content < n2 && (*head)->content > n3 && n2 > n3)
	{
		ft_rotate(head, 'a');
		ft_rotate(head, 'a');
	}
	else if ((*head)->content > n2 && (*head)->content < n3 && n2 < n3)
		ft_swap(head, 'a');
	else if ((*head)->content > n2 && (*head)->content > n3 && n2 < n3)
		ft_rotate(head, 'a');
	else if ((*head)->content > n2 && (*head)->content > n3 && n2 > n3)
	{
		ft_rotate(head, 'a');
		ft_swap(head, 'a');
	}
}

void	push_four(t_list **head, t_list **b)
{
	int	i;

	i = p_min(head);
	if (i == 2)
		ft_swap(head, 'a');
	else if (i == 3)
	{
		ft_rotate(head, 'a');
		ft_swap(head, 'a');
	}
	else if (i == 4)
		ft_rev_rotate(head, 'a');
	ft_push(head, b, 'a');
	push_tree(head);
	ft_push(b, head, 'b');
}

void	push_five(t_list **head, t_list **b)
{
	int	i;

	i = p_min(head);
	if (i == 2)
		ft_swap(head, 'a');
	else if (i == 3)
	{
		ft_rotate(head, 'a');
		ft_swap(head, 'a');
	}
	else if (i == 4)
	{
		ft_rev_rotate(head, 'a');
		ft_rev_rotate(head, 'a');
	}
	else if (i == 5)
		ft_rev_rotate(head, 'a');
	ft_push(head, b, 'a');
	push_four(head, b);
	ft_push(b, head, 'b');
}
