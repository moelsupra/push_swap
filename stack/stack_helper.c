/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelamma <moelamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:59:46 by moelamma          #+#    #+#             */
/*   Updated: 2026/02/06 19:00:27 by moelamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_node *stack)
{
	int		i;
	t_node	*current;

	i = 0;
	current = stack;
	while (current)
	{
		if (current->index != i)
			return (0);
		i++;
		current = current->next;
	}
	return (1);
}

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}
