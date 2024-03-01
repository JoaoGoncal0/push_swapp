/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:58:01 by jomendes          #+#    #+#             */
/*   Updated: 2024/02/27 14:40:30 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int	i = 0;

	a = NULL;
	b = NULL;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	if (ac > 2)
		init_stack_a(&a, av + 1, ac);
	if (ac == 2)
		init_stack_a(&a, av, ac);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		
		else
			sort_stacks(&a, &b);
		
	}
	free_stack(&a);
	if (ac == 2)
	{
		while (av[i])
		{
			free(av[i]);
			i++;
		}
		free(av);
	}
	return (0);
}