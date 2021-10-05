/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumbert <ghumbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:24:26 by ghumbert          #+#    #+#             */
/*   Updated: 2021/09/13 11:24:27 by ghumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	list_rrr(t_stack **list_a, t_stack **list_b)
{
	list_rrab(list_a, 3);
	list_rrab(list_b, 3);
	write(1, "rrr\n", 4);
}

void	list_rr(t_stack **list_a, t_stack **list_b)
{
	list_rarb(list_a, 1);
	list_rarb(list_b, 0);
	write(1, "rr\n", 3);
}

void	list_ss(t_stack **list_a, t_stack **list_b)
{
	list_sasb(list_a, 1);
	list_sasb(list_b, 0);
	write(1, "ss\n", 3);
}
