/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:12:52 by jomendes          #+#    #+#             */
/*   Updated: 2024/02/26 12:17:23 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long		ft_atol(const char *str)
{
	int i = 0;
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (str[i] <= 32 || str[i] == 127)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void		append_node(t_stack_node **stack, int n, char **av, int ac)
{
	t_stack_node *node;
	t_stack_node *last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
	{
		free_errors(stack, av, ac);
		return ;
	}
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **av, int ac)
{
	int		i;
	long	n;

	i = 0;
	if (!av || !a)
		return ;
	*a = NULL;
	while (av[i])
	{
		if (error_syntax(av[i]))
			free_errors(a, av, ac);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a, av, ac);
		if (error_duplicate(*a, (int)n))
			free_errors(a, av, ac);
		append_node(a, (int)n, av, ac);
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
