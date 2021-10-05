/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumbert <ghumbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:22:22 by ghumbert          #+#    #+#             */
/*   Updated: 2021/09/13 15:43:15 by ghumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libs/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define A 1
# define B 0
# define MAX 1
# define MIN 0
# define ALL -999

typedef struct s_number
{
	int	divs;
	int	i;
	int	rot;
	int	a;
	int	number_list;
	int	sort_list_num;
	int	exit;
	int	check_divs;
	int	inversion;
}	t_number;

typedef struct s_mass
{
	int		argc;
	int		flag;
	int		i;
	int		a;
	char	**split;
	int		*dest;
}	t_mass;

typedef struct s_stack
{
	int				count;
	struct s_stack	*next;
	struct s_stack	*back;
	struct s_stack	*next_order;
	struct s_stack	*back_order;
	int				divs;
	int				number_list;
}	t_stack;

void		ft_perror(char *line, int i);
void		preim_pointers(t_stack **list, t_stack *element);
void		sort_list_for_divs(t_stack **list_a, t_stack **list_b, int a);
void		sort_five_list_mix(t_stack **list_a, t_stack **list_b);
void		sort_five_list_max(t_stack **list_a, t_stack **list_b);
void		sort_six_list_max(t_stack **list_a, t_stack **list_b);
void		sort_four_argv_min(t_stack **list_a, t_stack **list_b);
void		sort_four_argv_max(t_stack **list_a, t_stack **list_b);
void		sort_three_argv_min(t_stack **list_a);
void		sort_three_argv_min_case_two(t_stack **list_a);
void		sort_three_argv_max(t_stack **list_a, t_stack **list_b);
void		torsion_stack(t_stack **list_a, t_stack *mean, int a);
void		sort_stack_b(t_stack **list_a, t_stack **list_b, int a);
void		check_divs_minus_one(t_stack **list_a, int a);
void		sort_fot_list_two(t_stack **list_a, t_stack **list_b, \
int num, int a);
void		null_number(t_number *number);
void		sort_last_list(t_stack **list_a, t_stack **list_b);
void		ft_check_max(t_stack **list_a, t_stack **list_b, int max);
void		divs_for_two(t_stack **list_a, t_number *number);
void		sort_list_two(t_stack **list_a, t_stack **list_b, \
t_number *number, int a);
void		ft_mass_two(int argc, char **argv, t_mass *mass);
void		sort_list_for_divs_two(t_stack **list_a, t_stack **list_b, int a);
void		sort_list(t_stack **list_a, t_stack **list_b, t_number *number);
void		ft_mass(int argc, char **argv, t_mass *mass);
void		sort_two_max(t_stack **list);
void		list_rrab_stack_b(t_stack **list_b, int max);
void		numbering(t_stack *list);
long long	ft_atoll(const char *str);

// algoritm
void		algoritm(t_stack **list_a, t_stack **list_b);
void		algoritm_two(t_stack **list_a, t_stack **list_b, t_number *number);
void		algoritm_three(t_stack **list_a, t_number *number);

int			numbert_fot_list(t_stack *list);
int			len_for_element(t_stack *list, int a);
int			check_number_min_perem(t_stack *list_a, t_stack *mean, int a);
int			torsion(t_stack *list, t_stack *mean, int a);
int			max_div(t_stack **list_a);
int			check_divs_distance(t_stack **list_a);
int			ft_check_sort(t_mass *mass);
int			max_min_stack(t_stack *list_b);
int			check_sort_list(t_stack *list_a);
int			check_divs_minus_one_case_two(t_stack **list_a);
int			check_mass(int argc, char **argv, t_mass *mass);
int			torsion_two(t_stack *list, t_stack *mean, int a, int len);
int			lentab(char **mass);
int			*handler_input(const char **argv, int *size);

t_stack		*scan_min(t_stack *list_a, int a, int min);
t_stack		*scan_max(t_stack *list_a, int a, int min);
t_stack		*get_mid(t_stack *list, int a);
t_stack		*ul_getmax_div(t_stack *lst);
t_stack		*add_list(int a);
t_stack		*last_list(t_stack **list_a);
t_stack		*scan_minmax(t_stack *list, int a, int minmax);
t_stack		*neighbour_list(t_stack *element, int a);
t_stack		*up_neighbour(t_stack *list, int div);

// command
void		list_sasb(t_stack **lst, int a);
void		list_rarb(t_stack **ab, int a);
void		list_pp(t_stack **a, t_stack **b, int s);
void		list_rrab(t_stack **lst, int a);

#endif