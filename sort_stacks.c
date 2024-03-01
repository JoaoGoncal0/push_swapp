/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:26:45 by jomendes          #+#    #+#             */
/*   Updated: 2024/03/01 12:39:48 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	artur(t_stack_node *stack)
// {
// 	if (!stack)
// 		return ;
// 	while (stack)
// 	{
// 		ft_printf("node_nbr = %d Target_Node_nbr = %d\n", stack->nbr, (stack)->target_node->nbr);
// 		stack = stack->next;
// 	}
// }

void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	t_stack_node *tmp_a;
	t_stack_node *tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	
	while (tmp_a != cheapest_node->target_node && tmp_b != cheapest_node->target_node)
		rr(a, b);
	if (tmp_a == cheapest->target_node && tmp_b == )
	current_index(*a);
	current_index(*b);
}

void	reverse_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	t_stack_node *tmp_a;
	t_stack_node *tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	
	while (tmp_a != cheapest_node->target_node && tmp_b != cheapest_node->target_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *cheapest_node;
	
	if (!(*a) || !(*b))
		return ;
	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(a, b);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	if (!(*a) || !(*b))
		return ;
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	min_on_top(t_stack_node **a)
{
	if (*a == NULL)
		return ;
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	// artur(*a);
	// ft_printf("SSSSSSSSSSSS\n");
	// artur(*b);
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	// artur(*a);
	// ft_printf("SSSSSSSSSSSS\n");
	// artur(*b);
	current_index(*a);
	min_on_top(a);
}