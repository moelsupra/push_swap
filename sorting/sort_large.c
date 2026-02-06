/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelamma <moelamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:13:00 by moelamma          #+#    #+#             */
/*   Updated: 2026/02/07 00:26:04 by moelamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	calculate_chunk_size(int size)
{
	if (size <= 100)
		return (14);
	else if (size <= 500)
		return (30);
	else
		return (50);
}

static int	find_max_index(t_node *stack)
{
	int		max;
	t_node	*current;

	if (!stack)
		return (-1);
	max = stack->index;
	current = stack->next;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

static void	rotate_max_to_top(t_node **stack_b, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(stack_b);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rrb(stack_b);
			pos++;
		}
	}
}

static void	push_back_from_b(t_node **stack_a, t_node **stack_b)
{
	int	max_index;
	int	pos;
	int	size;

	while (*stack_b)
	{
		max_index = find_max_index(*stack_b);
		pos = find_index_position(*stack_b, max_index);
		size = stack_size(*stack_b);
		rotate_max_to_top(stack_b, pos, size);
		pa(stack_a, stack_b);
	}
}

void	chunk_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;

	chunk_size = calculate_chunk_size(size);
	chunk_start = 0;
	chunk_end = chunk_size;
	while (*stack_a)
	{
		if ((*stack_a)->index <= chunk_start)
		{
			pb(stack_a, stack_b);
			chunk_start++;
		}
		else if ((*stack_a)->index <= chunk_start + chunk_end)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			chunk_start++;
		}
		else
			ra(stack_a);
	}
	push_back_from_b(stack_a, stack_b);
}
