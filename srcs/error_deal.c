/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_deal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:39:09 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/28 18:50:31 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_message(char *message)
{
	ft_putstr_fd(message, 1);
	exit(0);
}

void	malloc_error(void *buf)
{
	if (buf == NULL)
	{
		ft_putstr_fd(ERR_MALLOC, 1);
		exit(0);
	}
}

int	empty_checker(char *str)
{
	while (*str)
	{
		if (22 <= *str && *str <= 126)
			return (1);
		str++;
	}
	return (0);
}

void	wd_cnt_checker(int	width, int wd_cnt)
{
	if (width < wd_cnt)
	{
		ft_putstr_fd(ERR_LARGER_WID, 1);
		exit(0);
	}
	if (width > wd_cnt)
	{
		ft_putstr_fd(ERR_SMALLER_WID, 1);
		exit(0);
	}
}
