/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:29:59 by imahri            #+#    #+#             */
/*   Updated: 2023/01/03 19:44:37 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac < 2)
		return (0);
	if (check_args(av) == 1)
		return (0);
	stock_a(&a, ac, av);
	if (check_do(a) == 1)
		return (ft_lstclear(&a), write(2, "Error\n", 7), 0);
	if (sort_max(a) == 0)
		return (ft_lstclear(&a), 0);
	ft_push_swap(&a, &b, ft_lstsize(a));
	return (0);
}
