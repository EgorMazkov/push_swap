/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_divs_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumbert <ghumbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:11:42 by ghumbert          #+#    #+#             */
/*   Updated: 2021/09/13 12:11:53 by ghumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_divs_minus_one_case_two(t_stack **list_a)
{
	int		i;
	t_stack	*list;

	i = 0;
	list = *list_a;
	if (list)
	{
		while (list && list->divs != -1)
		{
			i++;
			list = list->next;
		}
	}
	return (i);
}

void	torsion_stack(t_stack **list_a, t_stack *mean, int a)
{
	int		i;
	int		num_list;
	t_stack	*list;

	i = 0;
	list = *list_a;
	num_list = numbert_fot_list(list);
	i = torsion(*list_a, mean, a);
	if (i <= num_list / 2)
	{
		while (i--)
			list_rarb(list_a, a);
		return ;
	}
	else if (i > num_list / 2)
	{
		i = num_list - i;
		while (i--)
			list_rrab(list_a, a);
		return ;
	}
}

int	torsion(t_stack *list, t_stack *mean, int a)
{
	int		len;
	int		i;
	t_stack	*list_stack;

	list_stack = list;
	i = 0;
	len = numbert_fot_list(list_stack);
	if (a == 1)
		i = torsion_two(list, mean, a, len);
	else if (a == 0)
	{
		while (list && len--)
		{
			if (list->count < mean->count && list->divs != -1)
				i++;
			else if (list->count >= mean->count)
				return (i);
			list = list->next;
		}
	}
	return (i);
}

int	torsion_two(t_stack *list, t_stack *mean, int a, int len)
{
	int	i;

	i = 0;
	if (a == 1)
	{
		while (list && len--)
		{
			if (list->count >= mean->count && list->divs != -1)
				i++;
			else if ((list->count < mean->count))
				return (i);
			list = list->next;
		}
	}
	return (i);
}

int	check_number_min_perem(t_stack *list_a, t_stack *mean, int a)
{
	int		i;
	t_stack	*list;

	list = list_a;
	i = 0;
	while (list_a)
	{
		if (a == 1)
		{
			if (list_a->count < mean->count && list_a->divs != -1)
				i++;
			if (list_a->divs == -1)
				return (i);
			list_a = list_a->next;
		}
		else if (a == 0)
		{
			if (list_a->count >= mean->count && list_a->divs != -1)
				i++;
			if (list_a->divs == -1)
				return (i);
			list_a = list_a->next;
		}
	}
	return (i);
}
