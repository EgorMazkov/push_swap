/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumbert <ghumbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:13:21 by ghumbert          #+#    #+#             */
/*   Updated: 2021/09/13 12:13:22 by ghumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_list(t_stack **list_a, t_stack **list_b, t_number *number)
{
	int	a;

	a = number->a;
	if (number->i == 1)
	{
		*list_a = (*list_a)->back;
		(*list_a)->divs = -1;
		return ;
	}
	else if (a == 2)
	{
		divs_for_two(list_a, number);
		return ;
	}
	while (number->a--)
		*list_a = (*list_a)->back;
	if (number->i > 6)
	{
		sort_last_list(list_a, list_b);
		return ;
	}
	sort_list_two(list_a, list_b, number, a);
}

void	sort_list_two(t_stack **list_a, t_stack **list_b, \
t_number *number, int a)
{
	while (number->i--)
		list_pp(list_a, list_b, 1);
	if (a == 6)
		sort_six_list_max(list_a, list_b);
	else if (a == 5)
		sort_five_list_max(list_a, list_b);
	else if (a == 4)
		sort_four_argv_max(list_a, list_b);
	else if (a == 3)
		sort_three_argv_max(list_a, list_b);
	while (*list_b)
	{
		list_pp(list_b, list_a, 0);
		(*list_a)->divs = -1;
	}
}

long long	ft_atoll(const char *str)
{
	size_t		i;
	long long	n;
	long long	result;

	i = 0;
	n = 1;
	result = 0;
	while (str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * n);
}

int	tr_stack(t_stack *list_b, int max)
{
	int		i;
	t_stack	*dest;

	dest = list_b;
	i = 0;
	while (dest)
	{
		if (dest->count != max)
			i++;
		if (dest->count == max)
			return (i);
		dest = dest->next;
	}
	return (i);
}

void	list_rrab_stack_b(t_stack **list_b, int max)
{
	int		num_list;
	t_stack	*list;
	int		i;

	i = tr_stack(*list_b, max);
	list = *list_b;
	num_list = numbert_fot_list(list);
	if (i < num_list / 2)
	{
		while ((*list_b)->count != max)
			list_rarb(list_b, 0);
	}
	else
	{
		while ((*list_b)->count != max)
			list_rrab(list_b, 0);
	}
}
