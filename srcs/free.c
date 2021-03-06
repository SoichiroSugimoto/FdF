/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:39:17 by sosugimo          #+#    #+#             */
/*   Updated: 2021/10/29 14:57:53 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	safe_free(char *buf)
{
	free(buf);
	buf = NULL;
}

void	all_free_lst(t_coord **coord)
{
	int		i;
	t_coord	*lst;

	i = 0;
	while (coord[i])
	{
		lst = coord[i];
		while (lst->next != NULL)
		{
			free(lst);
			lst = lst->next;
		}
		free(lst);
		i++;
	}
	free(coord);
}

void	two_dim_free(int **buf)
{
	while (*buf)
	{
		free(*buf);
		buf++;
	}
	free(buf);
}
