/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:33:58 by jomendes          #+#    #+#             */
/*   Updated: 2024/02/22 21:05:12 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node *biggest_node;

	biggest_node = find_max(*a);
	if ((*a)->nbr == biggest_node->nbr)
		ra(a);
	else if ((*a)->next->nbr == biggest_node->nbr)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}