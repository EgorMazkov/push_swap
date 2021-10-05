/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_divs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumbert <ghumbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:10:28 by ghumbert          #+#    #+#             */
/*   Updated: 2021/09/13 12:11:36 by ghumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_list_for_divs(t_stack **list_a, t_stack **list_b, int a)
{
	static int	divs;
	int			old_divs;
	t_stack		*mean;
	int			num_min_perem;

	mean = get_mid(*list_a, ul_getmax_div(*list_a)->divs);
	old_divs = mean->divs;
	divs++;
	num_min_perem = check_number_min_perem(*list_a, mean, a);
	while (num_min_perem)
	{
		if ((a && (*list_a)->divs == old_divs && \
		(*list_a)->count < mean->count) || (!a && \
		(*list_a)->divs == old_divs && \
		(*list_a)->count >= mean->count))
		{
			list_pp(list_a, list_b, a);
			num_min_perem--;
			(*list_b)->divs = divs;
		}
		else
			torsion_stack(list_a, mean, a);
	}
	sort_list_for_divs_two(list_a, list_b, a);
}

void	sort_list_for_divs_two(t_stack **list_a, t_stack **list_b, int a)
{
	check_divs_minus_one(list_a, a);
	if (a == 0)
		sort_stack_b(list_a, list_b, a);
}

int	get_mids(t_stack *list_a, int a)
{
	int	len_for_el;
	int	sum;
	int	res;

	sum = 0;
	len_for_el = len_for_element(list_a, a);
	while (list_a)
	{
		sum += list_a->count;
		list_a = list_a->next;
	}
	res = sum / len_for_el;
	return (res);
}

void	sort_stack_b(t_stack **list_a, t_stack **list_b, int a)
{
	int	number_list;

	number_list = numbert_fot_list(*list_a);
	if (number_list == 2)
	{
		sort_fot_list_two(list_a, list_b, number_list, a);
		while (number_list--)
		{
			list_pp(list_a, list_b, a);
			(*list_b)->divs = -1;
		}
	}
	if (number_list == 1)
	{
		list_pp(list_a, list_b, a);
		(*list_b)->divs = -1;
	}
}

void	check_divs_minus_one(t_stack **list_a, int a)
{
	t_stack	*list;
	int		i;

	i = 0;
	i = check_divs_minus_one_case_two(list_a);
	list = *list_a;
	if (i == numbert_fot_list(list))
		return ;
	if (a == 1)
	{
		list = *list_a;
		if (last_list(&list)->divs != -1)
		{
			while (last_list(&list)->divs != -1)
			{
				list = *list_a;
				while (last_list(&list)->divs != -1)
					list_rrab(list_a, a);
			}
		}
	}
}
