/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_error_order_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:58:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/17 14:58:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		f_part_one(char **b, int i)
{
	int	k;

	k = 0;
	while (k < i && b[k])
	{
		b[k] ? ft_printf("ft_ls: %s: No such file or directory\n", b[k]) : 1;
		free(b[k++]);
	}
	free(b);
	return (1);
}

static	int		f_lcomp(char *one, char *two, t_ls *l)
{
	if (two && one)
	{
		while (*one && *two)
		{
			if (*one < *two)
				return (1);
			if (*one > *two)
				return (2);
			one++;
			two++;
		}
		if (*two)
			if (l->r)
				return (1);
	}
	return (0);
}

int				f_error_order_(char **b, t_ls *l)
{
	char	*tmp;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!*b)
		return (1);
	while (b[i])
		i++;
	while (k < i)
	{
		if ((f_lcomp(b[k], b[k + 1], l)) == 2)
		{
			tmp = b[k];
			b[k] = b[k + 1];
			b[k + 1] = tmp;
			k = 0;
		}
		else
			k++;
	}
	f_part_one(b, i);
	return (1);
}
