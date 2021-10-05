/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumbert <ghumbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:13:25 by ghumbert          #+#    #+#             */
/*   Updated: 2021/09/13 12:13:26 by ghumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*neighbour_list(t_stack *element, int a)
{
	t_stack	*s;
	t_stack	*dest;

	s = element;
	dest = scan_minmax(element, a, MAX);
	if (dest == element)
		return (NULL);
	while (s->back)
		s = s->back;
	while (s)
	{
		if (s->divs == a || a == ALL)
		{
			if (s->count < dest->count && s->count > element->count)
				dest = s;
			s = s->next;
		}
	}
	return (dest);
}

int	max_div(t_stack **list_a)
{
	int	div;

	div = 0;
	while (*list_a)
	{
		if (*list_a && div < (*list_a)->divs)
			div = (*list_a)->divs;
		else
			(*list_a) = (*list_a)->next;
	}
	return (div);
}

int	check_sort_list(t_stack *list_a)
{
	t_stack	*list;
	int		flag;

	flag = 0;
	list = list_a;
	while (list->next)
	{
		if (list->next && list->count < list->next->count)
			list = list->next;
		else if (list->count > list->next->count)
		{
			flag = 0;
			return (flag);
		}
	}
	flag = 1;
	return (flag);
}

void	divs_for_two(t_stack **list_a, t_number *number)
{
	while (number->i--)
	{
		(*list_a) = (*list_a)->back;
		(*list_a)->divs = -1;
	}
	if ((*list_a)->count > (*list_a)->next->count)
		list_sasb(list_a, 1);
}

void	sort_last_list(t_stack **list_a, t_stack **list_b)
{
	while (*list_a)
	{
		sort_list_for_divs(list_a, list_b, 1);
		while (numbert_fot_list(*list_b) > 1)
			sort_list_for_divs(list_b, list_a, 0);
		if (!*list_b)
			break ;
	}
}
