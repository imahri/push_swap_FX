/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:04:13 by imahri            #+#    #+#             */
/*   Updated: 2023/01/02 22:28:49 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_n(t_list **head)
{
	t_list	*tmp;
	t_list	*p;

	if (ft_lstsize(*head) > 1)
	{
		p = lst_last(*head);
		tmp = (*head);
		(*head) = (*head)->next;
		tmp->next = NULL;
		p->next = tmp;
	}
}

void	ft_rotate(t_list **head1, char c)
{
	rotate_n(head1);
	if (c == 'a')
		write (1, "ra\n", 3);
	else if (c == 'b')
		write (1, "rb\n", 3);
}

void	rotate_x(t_list **head1, t_list **head2, char c)
{
	rotate_n(head1);
	rotate_n(head2);
	if (c == 'x')
		write (1, "rr\n", 3);
	else
		return ;
}
