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

#endif