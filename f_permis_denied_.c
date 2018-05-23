/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_permis_denied_.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:00:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/17 15:00:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

int 		f_permis_denied_(char *name, t_ls *l)
{
	l->c > 0 || l->eror ? ft_printf("%s:\n", name) : 0;
	ft_printf("ls: %s: %s\n", name, strerror(errno));
	ft_printf("\n");
	return (1);
}
