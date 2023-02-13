/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:55:38 by imahri            #+#    #+#             */
/*   Updated: 2023/01/02 22:28:27 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_n(t_list **head1, t_list **head2)
{
	t_list	*tmp;

	tmp = *head1;
	if (*head1)
	{
		(*head1) = (*head1)->next;
		lst_add_front(head2, tmp);
	}	
}

void	ft_push(t_list **head1, t_list **head2, char c)
{
	push_n(head1, head2);
	if (c == 'b')
		write (1, "pa\n", 3);
	else if (c == 'a')
		write (1, "pb\n", 3);
	else
		return ;
}
