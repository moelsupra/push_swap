#include "../push_swap.h"

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;
	
	if (!stack_a || !*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "pb\n", 3);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!stack_b || !*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "pa\n", 3);
}