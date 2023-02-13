/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:39:28 by imahri            #+#    #+#             */
/*   Updated: 2023/01/03 00:13:28 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_verify(t_list **a, t_list **b, char *str)
{
	if (ft_strcmp(str, "pa\n") == 0)
		ft_push(b, a, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		ft_push(a, b, 0);
	else if (ft_strcmp(str, "sa\n") == 0)
		ft_swap(a, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		ft_swap(b, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		ft_swap_x(a, b);
	else if (ft_strcmp(str, "ra\n") == 0)
		ft_rotate(a, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		ft_rotate(b, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		rotate_x(a, b, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		ft_rev_rotate(a, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		ft_rev_rotate(b, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rev_rotate_x(a, b, 0);
	else
		return (write(1, "Error\n", 6), exit(1));
}

void	ft_read_it(t_list **a, t_list **b)
{
	char	*s;

	s = get_next_line(0);
	while (s)
	{
		ft_verify(a, b, s);
		free(s);
		s = get_next_line(0);
	}
	if (sort_max(*a) == 0 && !*b)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}
