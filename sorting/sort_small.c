#include "../push_swap.h"

int	stack_size(t_node *stack)
{
	int		count;
	t_node	*current;

	count = 0;
	current = stack;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	sort_two(t_node **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void	sort_three(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	c = (*stack_a)->next->next->index;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

int	find_position(t_node *stack, int target_index)
{
	int		pos;
	t_node	*current;

	pos = 0;
	current = stack;
	while (current)
	{
		if (current->index == target_index)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}

void	move_to_top(t_node **stack, int pos)
{
	int	size;

	size = stack_size(*stack);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(stack);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(stack);
			pos++;
		}
	}
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int	pos;

	pos = find_position(*stack_a, 0);
	move_to_top(stack_a, pos);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	pos;

	pos = find_position(*stack_a, 0);
	move_to_top(stack_a, pos);
	pb(stack_a, stack_b);
	pos = find_position(*stack_a, 1);
	move_to_top(stack_a, pos);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
