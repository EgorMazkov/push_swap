/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumbert <ghumbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:09:47 by ghumbert          #+#    #+#             */
/*   Updated: 2021/09/13 11:09:49 by ghumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algoritm(t_stack **list_a, t_stack **list_b)
{
	t_stack		*lst;
	t_number	number;

	null_number(&number);
	lst = *list_a;
	number.number_list = numbert_fot_list(lst);
	number.divs = max_div(&lst);
	while (*list_a)
	{
		lst = *list_a;
		number.divs = max_div(&lst);
		if ((*list_a)->divs == -1)
			algoritm_three(list_a, &number);
		if (number.rot == number.number_list)
			break ;
		algoritm_two(list_a, list_b, &number);
	}
}

void	rot_stack(t_stack **list_a, t_number *number)
{
	list_rarb(list_a, 1);
	number->rot++;
}

void	algoritm_two(t_stack **list_a, t_stack **list_b, t_number *number)
{
	while ((*list_a)->divs == number->divs)
	{
		number->i++;
		number->a++;
		*list_a = (*list_a)->next;
	}
	sort_list(list_a, list_b, number);
	number->i = 0;
	number->a = 0;
}

void	algoritm_three(t_stack **list_a, t_number *number)
{
	int		distance;
	t_stack	*lst;

	if ((*list_a)->divs == -1)
	{
		lst = *list_a;
		distance = check_divs_distance(&lst);
		if (distance == number->number_list)
		{
			while (number->rot != number->number_list)
				rot_stack(list_a, number);
			return ;
		}
		if ((*list_a)->divs == -1)
			rot_stack(list_a, number);
	}
}
