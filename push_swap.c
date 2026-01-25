#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node  *stack_a;
	t_node  *stack_b;
	char	**numbers;
	if (argc < 2)
		return 0;
	stack_a = NULL;
	stack_b = NULL;

	numbers = parse_input(argc, argv);
	return (0);
}
