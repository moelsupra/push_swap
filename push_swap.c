/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelamma <moelamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:18:10 by moelamma          #+#    #+#             */
/*   Updated: 2026/02/07 00:07:47 by moelamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(int *numbers)
{
	if (numbers)
		free(numbers);
	write(2, "Error\n", 6);
}

void	sort_stack(t_node **stack_a, t_node **stack_b, int count)
{
	if (count == 2)
		sort_two(stack_a);
	else if (count == 3)
		sort_three(stack_a);
	else if (count == 4)
		sort_four(stack_a, stack_b);
	else if (count == 5)
		sort_five(stack_a, stack_b);
	else
		chunk_sort(stack_a, stack_b, count);
}

int	main(int argc, char **argv)
{
	int		*numbers;
	int		count;
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	numbers = parse_arguments(argc, argv, &count);
	if (!numbers)
		return (handle_error(NULL), 1);
	stack_a = build_stack(numbers, count);
	if (!stack_a)
		return (handle_error(numbers), 1);
	if (is_sorted(stack_a))
		return (free(numbers), free_stack(&stack_a), 0);
	sort_stack(&stack_a, &stack_b, count);
	free(numbers);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
