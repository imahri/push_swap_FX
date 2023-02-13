/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkee.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 23:17:21 by imahri            #+#    #+#             */
/*   Updated: 2022/12/23 19:09:41 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*p;

	p = (t_list *) malloc (sizeof(t_list));
	if (!p)
		return (NULL);
	p->content = content;
	p->next = NULL;
	return (p);
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*z;

	i = 0;
	z = lst;
	while (z)
	{
		z = z->next;
		i++;
	}
	return (i);
}

void	lst_add_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

t_list	*lst_last(t_list *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

void	lst_add_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == NULL)
		*lst = new;
	tmp = lst_last(*lst);
	tmp->next = new;
	new->next = NULL;
}
