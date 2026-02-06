/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelamma <moelamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:41:09 by moelamma          #+#    #+#             */
/*   Updated: 2026/02/06 17:17:45 by moelamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	process_sign(char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	if (str[*i] == '\0')
		return (0);
	if (str[*i] == '+' || str[*i] == '-')
	{
		(*i)++;
		if (str[*i] < '0' || str[*i] > '9')
			return (-1);
	}
	return (1);
}

int	validate_and_count(char *str)
{
	int	i;
	int	count;
	int	status;

	i = 0;
	count = 0;
	while (str[i])
	{
		status = process_sign(str, &i);
		if (status == 0)
			break ;
		if (status == -1)
			return (-1);
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		count++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '\t')
			return (-1);
	}
	if (count == 0)
		return (-1);
	return (count);
}

int	get_total_count(int argc, char **argv)
{
	int	total;
	int	count;
	int	i;

	total = 0;
	i = 1;
	while (i < argc)
	{
		count = validate_and_count(argv[i]);
		if (count < 0)
			return (-1);
		total += count;
		i++;
	}
	return (total);
}
