#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		*numbers;
	int		count;
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (0);
	numbers = parse_arguments(argc, argv, &count);
	if (!numbers)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = build_stack(numbers, count);
	if (!stack_a)
	{
		free(numbers);
		write(2, "Error\n", 6);
		return (1);
	}
	if (is_sorted(stack_a))
	{
		free(numbers);
		free_stack(&stack_a);
		return (0);
	}
	if (count == 2)
		sort_two(&stack_a);
	else if (count == 3)
		sort_three(&stack_a);
	else if (count == 4)
		sort_four(&stack_a, &stack_b);
	else if (count == 5)
		sort_five(&stack_a, &stack_b);
	else
		printf("Stack size %d - sorting not implemented yet\n", count);
	free(numbers);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
