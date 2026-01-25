#include "push_swap.h"

static int is_only_spaces(char *str)
{
	while (str && *str)
	{
		if (*str != ' ' && *str != '\t')
			return (0);
		str++;
	}
	return (1);
}

char	**parse_input(int argc, char **argv)
{
	char	**numbers;

	numbers = NULL;
	if (argc < 2)
		return (NULL);
	if (argc == 2)
	{
		if (!argv[1] || argv[1][0] == '\0' || is_only_spaces(argv[1]))
			error_exit();
		numbers = ft_split(argv[1], ' ');
		if (!numbers  || !numbers[0])
			error_exit();
	}
	else
		numbers = argv + 1;
	return (numbers);
}
