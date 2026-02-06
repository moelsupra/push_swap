/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelamma <moelamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:32:27 by moelamma          #+#    #+#             */
/*   Updated: 2026/02/06 19:00:00 by moelamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*create_node(int value, int index)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

void	push_to_bottom(t_node **stack, t_node *new_node)
{
	t_node	*current;

	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

void	assign_indexes(t_node *stack, int *numbers, int count)
{
	int		i;
	int		index;
	t_node	*current;

	current = stack;
	while (current)
	{
		index = 0;
		i = 0;
		while (i < count)
		{
			if (numbers[i] < current->value)
				index++;
			i++;
		}
		current->index = index;
		current = current->next;
	}
}

t_node	*build_stack(int *numbers, int count)
{
	t_node	*stack;
	t_node	*new_node;
	int		i;

	stack = NULL;
	i = 0;
	while (i < count)
	{
		new_node = create_node(numbers[i], 0);
		if (!new_node)
			return (NULL);
		push_to_bottom(&stack, new_node);
		i++;
	}
	assign_indexes(stack, numbers, count);
	return (stack);
}
