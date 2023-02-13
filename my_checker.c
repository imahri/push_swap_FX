/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:35:02 by imahri            #+#    #+#             */
/*   Updated: 2023/01/03 18:51:28 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lek(void)
{
	system("leaks push_swap");
}

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
	ft_read_it(&a, &b);
	return (0);
}
