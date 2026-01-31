#include "push_swap.h"

int main(int argc, char **argv)
{
	int	*numbers;
	int	count;
	int	i;

	if (argc < 2)
		return (0);
	numbers = parse_arguments(argc, argv, &count);


	if (!numbers)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	i = 0;
	printf("Successfully parsed %d numbers:\n", count);
	while (i < count)
	{
		printf("%d\n", numbers[i]);
		i++;
	}
	free(numbers);
	return (0);
}
