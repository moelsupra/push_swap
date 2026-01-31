#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		*numbers;
	int		count;
	t_node	*stack_a;
	t_node	*current;

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
		printf("Stack is already sorted!\n");
		free(numbers);
		return (0);
	}
	current = stack_a;
	printf("Stack A (top to bottom):\n");
	while (current)
	{
		printf("value: %d, index: %d\n", current->value, current->index);
		current = current->next;
	}
	printf("\nStack needs to be sorted.\n");
	free(numbers);
	return (0);
}