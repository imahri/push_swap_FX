/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linke.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 01:28:08 by imahri            #+#    #+#             */
/*   Updated: 2022/12/30 22:18:57 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **head)
{
	t_list	*tmp;

	if (head)
	{
		while ((*head) != NULL)
		{
			tmp = (*head)->next;
			free(*head);
			*head = tmp;
		}
	}
}
