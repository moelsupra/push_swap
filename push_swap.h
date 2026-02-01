#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>

typedef struct s_node
{
	int 			value;
	int 			index;
	struct s_node	*next;
}	t_node;

int	validate_and_count(char *str);
int	get_total_count(int argc, char **argv);
int	has_duplicates(int *numbers, int count);
int	fill_numbers_array(char **argv, int argc, int *numbers);
int	safe_atoi(char *str, int *j, int *result);
int	*parse_arguments(int argc, char **argv, int *count);

t_node	*create_node(int value, int index);
void	push_to_bottom(t_node **stack, t_node *new_node);
void	assign_indexes(t_node *stack, int *numbers, int count);
t_node	*build_stack(int *numbers, int count);
int		is_sorted(t_node *stack);
void	free_stack(t_node **stack);

void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

int		stack_size(t_node *stack);
void	sort_two(t_node **stack_a);
void	sort_three(t_node **stack_a);
int		find_position(t_node *stack, int target_index);
void	move_to_top(t_node **stack, int pos);
void	sort_four(t_node **stack_a, t_node **stack_b);
void	sort_five(t_node **stack_a, t_node **stack_b);

#endif