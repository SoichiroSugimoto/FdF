/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:40:50 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/15 13:40:13 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

void	get_z_max(int num, t_fdf *data)
{
	int	i;

	i = get_abs(num);
	if (i > data->z_max)
		data->z_max = i;
}

void	init_lst(t_coord *lst)
{
	lst->z = 0;
	lst->color = 0;
	lst->next = NULL;
}

void	ft_lstadd_back(t_coord **lst, t_coord *new)
{
	while (*lst)
		lst = &((*lst)->next);
	*lst = new;
}

char	*ft_strdup_till(const char *s1, char c)
{
	char	*p;
	int		cnt;
	int		i;

	cnt = 0;
	i = 0;
	while (s1[cnt] && s1[cnt] != c)
		cnt++;
	p = (char *)malloc(sizeof(char) * (cnt + 1));
	malloc_error(p);
	while (i < cnt)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
