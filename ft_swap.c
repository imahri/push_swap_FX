/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:51:02 by imahri            #+#    #+#             */
/*   Updated: 2023/01/02 22:43:23 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_n(t_list **head)
{
	int	tmp;
	int	ind;

	if (!*head || !(*head)->next)
		return ;
	tmp = (*head)->content;
	ind = (*head)->index;
	(*head)->index = (*head)->next->index;
	(*head)->next->index = ind;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = tmp;
}

void	ft_swap(t_list **head, char c)
{
	ft_swap_n(head);
	if (c == 'a')
		write (1, "sa\n", 3);
	else if (c == 'b')
		write (1, "sb\n", 3);
	else
		return ;
}

void	ft_swap_x(t_list **head1, t_list **head2)
{
	ft_swap_n(head1);
	ft_swap_n(head2);
	write (1, "ss\n", 3);
}
