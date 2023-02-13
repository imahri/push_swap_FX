/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:34:44 by imahri            #+#    #+#             */
/*   Updated: 2023/01/02 22:28:38 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_n(t_list **head)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*head) > 1)
	{
		tmp = *head;
		last = lst_last(*head);
		while (tmp)
		{
			if (tmp->next->next == NULL)
			{
				tmp->next = NULL;
				break ;
			}
			tmp = tmp->next;
		}
		last->next = *head;
		*head = last;
	}
}

void	ft_rev_rotate(t_list **head, char c)
{
	rev_rotate_n(head);
	if (c == 'a')
		write (1, "rra\n", 4);
	else if (c == 'b')
		write (1, "rrb\n", 4);
}

void	rev_rotate_x(t_list **head1, t_list **head2, char c)
{
	rev_rotate_n(head1);
	rev_rotate_n(head2);
	if (c == 'x')
		write (1, "rrr\n", 4);
	else
		return ;
}
