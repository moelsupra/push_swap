#include "../push_swap.h"

int	safe_atoi(char *str, int *j, int *result)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	if (str[*j] == '+' || str[*j] == '-')
	{
		if (str[*j] == '-')
			sign = -1;
		(*j)++;
	}
	while (str[*j] >= '0' && str[*j] <= '9')
	{
		num = num * 10 + (str[*j] - '0');
		if (num * sign > 2147483647 || num * sign < -2147483648)
			return (0);
		(*j)++;
	}
	*result = (int)(num * sign);
	return (1);
}

int	fill_numbers_array(char **argv, int argc, int *numbers)
{
	int	i;
	int	j;
	int	idx;

	i = 1;
	idx = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ' || argv[i][j] == '\t')
				j++;
			if (argv[i][j] == '\0')
				break ;
			if (!safe_atoi(argv[i], &j, &numbers[idx]))
				return (0);
			idx++;
		}
		i++;
	}
	return (1);
}

int	has_duplicates(int *numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*parse_arguments(int argc, char **argv, int *count)
{
	int	*numbers;
	int	total;

	total = get_total_count(argc, argv);
	if (total < 0)
		return (NULL);
	numbers = malloc(sizeof(int) * total);
	if (!numbers)
		return (NULL);
	if (!fill_numbers_array(argv, argc, numbers))
	{
		free(numbers);
		return (NULL);
	}
	if (has_duplicates(numbers, total))
	{
		free(numbers);
		return (NULL);
	}
	*count = total;
	return (numbers);
}
